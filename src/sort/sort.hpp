#pragma once
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;
using std::swap;

namespace QuickSort {
    /** 
     * T: O(nlogn)->O(n^2) 平均logn层 每层n  基准数优化：选左中右三个的中位数为基准数
     * O: O(n)->O(logn) 栈帧 尾递归优化：只递归数组短的一段
     * */
	int partition(vector<int>& num, int left, int right) {
		int i = left, j = right;
		while (i<j)
		{
			while (i < j && num[j] >= num[left]) j--;
			while (i < j && num[i] <= num[left]) i++;
			swap(num[i], num[j]);
		}
		swap(num[i], num[left]);
		return i;
	}
	void quickSort(vector<int>& num, int left, int right) {
		if (left >= right) return;
		int pivot = partition(num, left, right);
		quickSort(num, left, pivot - 1);
		quickSort(num, pivot + 1, right);
	}
}
namespace SelectionSort{
    /**
     * T: O(n^2) 非自适应 循环次数 n-1 n-2 ... 2 1 求和n*(n-1)/2
     * O: O(1) 原地
     * 非稳定 */
    void selectionSort(vector<int>& vec){
        int n = vec.size();
        for (size_t i = 0; i < n-1; i++)
        {
            int k = i;
            for (size_t j = i+1; j < n; j++)
            {
                if (vec[j] < vec[k]) k = j;
            }
            swap(vec[i],vec[k]);
        }
    }
}
namespace BubbleSort {
    /**
     * T: O(n^2)->O(n) 自适应  效率优化 循环次数 n-1 n-2 ... 2 1 求和n*(n-1)/2
     * O: O(1) 原地
     * 稳定 */
    void bubbleSort(vector<int>& vec) {
        int n = vec.size();
        for (size_t i = n-1; i > 0; i--)
        {
            bool flag = false;
            for (size_t j = 0; j < i; j++)
            {
                if (vec[j] > vec[j + 1]) {
                    flag = true;
                    swap(vec[j], vec[j+1]);
                }
            }
            if (!flag) { break; }
        }
    }
}
namespace InsertionSort{
    /**
     * T: O(n^2)->O(n) 自适应  效率优化 循环次数 n-1 n-2 ... 2 1 求和n*(n-1)/2
     * O: O(1) 原地
     * 稳定 */
    void insertionSort(vector<int>& vec) {
        for (size_t i = 1; i < vec.size(); i++)
        {
            int base = vec[i], j = i - 1;
            for (;j >=0 && vec[j]>base; j--)
            {
                vec[j + 1] = vec[j];
            }
            vec[j + 1] = base;
        }
    }
}
/*
而在数据量较小时，复杂度不占主导地位，每轮中的单元操作数量起到决定性作用。
实际上，许多编程语言（例如 Java）的内置排序函数采用了插入排序，大致思路为：对于长数组，采用基于分治策略的排序算法，例如快速排序；对于短数组，直接使用插入排序。

冒泡排序基于元素交换实现，需要借助一个临时变量，共涉及 3 个单元操作；插入排序基于元素赋值实现，仅需 1 个单元操作。因此，冒泡排序的计算开销通常比插入排序更高。
选择排序在任何情况下的时间复杂度都为O(n^2)。如果给定一组部分有序的数据，插入排序通常比选择排序效率更高。
选择排序不稳定，无法应用于多级排序。
*/
namespace MergeSort {
    void merge(vector<int>& vec, int left,int mid, int right) {
        vector<int> tmp(right-left+1);
        int i = left, j = mid + 1, k = 0;
        while (i<=mid && j<=right)
        {
            if (vec[i] < vec[j])
                tmp[k++] = vec[i++];
            else
                tmp[k++] = vec[j++];
        }
        while (i<=mid) {
            tmp[k++] = vec[i++];
        }
        while (j <= right) {
            tmp[k++] = vec[j++];
        }

        for (size_t k = 0; k < tmp.size(); k++)
        {
            vec[left + k] = tmp[k];
        }
    }
    void mergeSort(vector<int>& vec,int left,int right) {
        if (left >= right) { return; }
        int mid = left + (right - left) / 2;
        mergeSort(vec,left,mid);
        mergeSort(vec,mid+1,right);
        merge(vec,left,mid,right);
    }
}

namespace HeapSort {

}

void sortTest() {
    vector<int> vec = { 2,4,3,8,1,6,4 };
    QuickSort::quickSort(vec, 0, vec.size() - 1);
    cout << "Quick Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec = { 2,4,3,8,1,6,4 };
    SelectionSort::selectionSort(vec);
    cout << "Selection Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec = { 2,4,3,8,1,6,4 };
    BubbleSort::bubbleSort(vec);
    cout << "BubbleSort Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec = { 2,4,3,8,1,6,4 };
    InsertionSort::insertionSort(vec);
    cout << "Insertion Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec = { 2,4,3,8,1,6,4 };
    MergeSort::mergeSort(vec, 0, vec.size() - 1);
    cout << "Merge Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}