#pragma once
#include <iostream>

class MyQueue
{
private:
	int* nums;
	int head;
	int queSize;
	int queCapacity;

public:
	MyQueue(int capacity):queCapacity(capacity) {
		nums = new int[queCapacity];
		head = queSize = 0;
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
		return (head + queSize) % queCapacity;
	}

	void push(int num) {
		if (queSize == queCapacity) {

		}
		int idx = index();
		nums[idx] = num;
		queSize++;
	}

	int pop() {
		int tmp = front();
		head = (head + 1) % queCapacity;
		queSize--;
		return tmp;
	}

	int front() {
		if (empty()) {
			throw("Full Queue");
		}
		return nums[head];
	}

private:

};