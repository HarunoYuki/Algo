#include "thread.hpp"

//template<typename T>
//T MYmax(T a, T b) {
//    return (a > b) ? a : b;
//}
int thread_test() {
	atomic<int> at;
	at.store(1);
	at.exchange(2);

	auto f = [](int id) {
		std::cout << "Thread " << id << " is running...\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Thread " << id << " finished.\n";
		};
	vector<thread> ths;
	for (int i = 0; i < 5; i++)
	{
		ths.emplace_back(f, i);
	}
	_sleep(2000);
	cout << "pause" << endl;
	for (auto& t : ths) {
		t.join();
	}
	return 0;
}