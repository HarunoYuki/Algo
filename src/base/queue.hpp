#include <iostream>

class MyQueue
{
private:
	int* nums;
	int front;
	int queSize;
	int queCapacity;

public:
	MyQueue(int capacity):queCapacity(capacity) {
		nums = new int[queCapacity];
		front = queSize = 0;
	}
	~MyQueue() {
		delete[] nums;
	}

	int size() {
		return queSize;
	}

	int capacity() {
		return queCapacity;
	}

	bool empty() {
		return queSize == 0;
	}

	int index() {
		return (front + queSize) % queCapacity;
	}

	void push_back(int num) {
		if (queSize == queCapacity) {

		}
		int idx = index();
		nums[idx] = num;
		queSize++;
	}

	int pop_front() {
		int tmp = nums[front];
		front = (front + 1) % queCapacity;
		queSize--;
		return tmp;
	}

	int front() {
		if (empty()) {
			throw("Full Queue");
		}
		return nums[front];
	}

private:

};