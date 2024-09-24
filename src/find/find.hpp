#pragma once
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

int binarySearch(vector<int>& vec, int target);
int binarySearchInsertion(vector<int>& vec, int target);
int binarySearchLeftEdge(vector<int>& vec, int target);

void findTest();