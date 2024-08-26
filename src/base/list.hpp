#include <iostream>

class MyVector
{
private:
	int* arr;
	int arrSize=0;
	int arrCapacity=10;
	int extendRatio=2;

public:
	MyVector() {
		arr = new int[arrCapacity];
	}
	~MyVector() {
		delete[] arr;
	}

	int size() {
		return arrSize;
	}
	int capacity() {
		return arrCapacity;
	}

	int& operator[](int index) {
		if (index < 0 || index >= arrSize) {
			throw("Out Of Index");
		}
		return arr[index];
	}

	const int& operator[](int index)const {
		if (index < 0 || index >= arrSize) {
			throw("Out Of Index");
		}
		return arr[index];
	}
	int get(int index) {
		if (index < 0 || index >= arrSize) {
			throw("Out Of Index");
		}
		return arr[index];
	}
	void set(int index, int num) {
		if (index < 0 || index >= arrSize) {
			throw("Out Of Index");
		}
		arr[index] = num;
	}

	void push_back(int num) {
		if (arrSize == arrCapacity) {
			extend();
		}
		arr[arrSize] = num;
		arrSize++;
	}
	int pop_back() {
		if (arrSize < 1) {
			throw("None Item");
		}
		arrSize--;
		return arr[arrSize];
	}

	void insert(int index, int num) {
		if (index < 0 || index >= arrSize) {
			throw("Out Of Index");
		}
		if (arrSize == arrCapacity) {
			extend();
		}
		for (size_t i = arrSize-1; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = num;
		arrSize++;
	}
	int remove(int index) {
		if (index < 0 || index >= arrSize) {
			throw("Out Of Index");
		}
		int res = arr[index];
		for (size_t i = index; i < arrSize-1; i++)
		{
			arr[i] = arr[i + 1];
		}
		arrSize--;
		return res;
	}

	void extend() {
		int newCapacity = arrCapacity * extendRatio;
		int* tmp = arr;
		arr = new int[newCapacity];
		for (size_t i = 0; i < arrSize; i++) {
			arr[i] = tmp[i];
		}
		delete[] tmp;
		arrCapacity = newCapacity;
	}
};