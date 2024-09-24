#include "find.hpp"

int binarySearch(vector<int>& vec, int target) {
	int i = 0, j = vec.size() - 1;
	while (i <= j)
	{
		int mid = i + (j - i) / 2;
		if (vec[mid] < target) {
			i = mid + 1;
		}
		else if (vec[mid] > target) {
			j = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
}

int binarySearchInsertion(vector<int>& vec, int target) {
	int i = 0, j = vec.size() - 1;
	while (i <= j) {
		int mid = i + (j - i) / 2;
		if (vec[mid] < target)
			i = mid + 1;
		else if (vec[mid] > target)
			j = mid - 1;
		else
			j = mid - 1;
	}
	return i;
}

int binarySearchLeftEdge(vector<int>& vec, int target) {
	int i = binarySearchInsertion(vec, target);
	if (i == vec.size() || vec[i] != target) {
		return -1;
	}
	return i;
}

void findTest() {
	vector<int> vec = { 0,1,2,3,4,5,6,7,8,8,8,8,8,9 };
	cout << binarySearch(vec, 7) << endl;
	cout << binarySearchInsertion(vec, 10) << endl;
	cout << binarySearchInsertion(vec, 8) << endl;
	cout << binarySearchLeftEdge(vec, 10) << endl;
	cout << binarySearchLeftEdge(vec, 8) << endl;
}