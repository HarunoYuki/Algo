#pragma once
#include <iostream>
#include <atomic>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <functional>
#include <future>

using namespace std;

class ThreadPool
{
private:
	vector<thread> wokers;
	queue<function<void()>> tasks;
	mutex queueMutex;
	condition_variable cv;
	atomic<bool> stoped;

public:
	ThreadPool(int num):stoped(false) {
		for (int i = 0; i < num; i++) {
			wokers.emplace_back([this] {
				while (true) {
					function<void()> task;
					{
						unique_lock<mutex> lock(queueMutex);
						// expression == false blocked; expression == true go on
						cv.wait(lock, [this] { return stoped || !tasks.empty(); });
						if (stoped && tasks.empty()) {
							return;
						}
						task = move(tasks.front());
						tasks.pop();
					}
					task();
				}
			});
		}
	}
	~ThreadPool() {
		{
			unique_lock<mutex> lock(queueMutex);
			stoped = true;
			cv.notify_all();
		}
		for (auto& t : wokers) {
			if (t.joinable()) {
				t.join();
			}
		}
	}

	// 提交任务
	template <class F, class... Args>
	auto push(F&& f, Args&&... args) -> std::future<decltype(f(args...))> {
		using return_type = decltype(f(args...));

		// 将任务打包成一个 std::packaged_task
		auto task = std::make_shared<std::packaged_task<return_type()>>(
			std::bind(std::forward<F>(f), std::forward<Args>(args)...)
		);

		// 将任务放入队列
		{
			std::unique_lock<std::mutex> lock(queueMutex);
			// 如果停止，抛出异常
			if (stoped) {
				throw std::runtime_error("enqueue on stopped ThreadPool");
			}
			tasks.push([task]() { (*task)(); });
			cv.notify_one();
		}
		return task->get_future();
	}
};

int thread_test();

//template<typename T>
//T MYmax(T a, T b) {
//    return (a > b) ? a : b;
//}
//template int MYmax<int>(int a, int b);
//template double MYmax<double>(double a, double b);

/*
class ThreadPool
{
private:
	vector<thread> workers;
	queue<function<void()>> tasks;
	mutex queMutex;
	condition_variable cv;
	atomic_bool stoped;

public:
	ThreadPool(int num):stoped(false) {
		for (int i = 0; i < num; i++)
		{
			workers.emplace_back([this] {
				function<void()> task;
				{
					unique_lock<mutex> lock(queMutex);
					cv.wait(lock, [this] {return stoped || !tasks.empty(); });
					if (stoped && tasks.empty()) {
						return;
					}
					task = move(tasks.front());
					tasks.pop();
				}
				task();
			});
		}
	}
	~ThreadPool() {
		{
			unique_lock<mutex> lock(queMutex);
			stoped = true;
			cv.notify_all();
		}
		for (auto& t : workers) {
			if (t.joinable()) {
				t.join();
			}
		}
	}
	template <class F, class... Args>
	auto push(F&& f, Args&&... args)->future<decltype(f(args...))> {
		using return_type = decltype(f(args...));
		auto task = make_shared<packaged_task<return_type()>>(
			bind(forward<F>(f), forward<Args>(args)...)
		);
		future<return_type> result = task->get_future();
		{
			unique_lock<mutex> lock(queMutex);
			if (stoped) {
				throw("Error: Stoped Queue");
			}
			tasks.emplace([task]() {(*task)(); });
			cv.notify_one();
		}
		return result;
	}
};
*/