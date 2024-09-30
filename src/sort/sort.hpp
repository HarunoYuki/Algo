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
    int partition(vector<int>& num, int left, int right);
    void quickSort(vector<int>& num, int left, int right);
}
namespace SelectionSort{
    /**
     * T: O(n^2) 非自适应 循环次数 n-1 n-2 ... 2 1 求和n*(n-1)/2
     * O: O(1) 原地
     * 非稳定 */
    void selectionSort(vector<int>& vec);
}
namespace BubbleSort {
    /**
     * T: O(n^2)->O(n) 自适应  效率优化 循环次数 n-1 n-2 ... 2 1 求和n*(n-1)/2
     * O: O(1) 原地
     * 稳定 */
    void bubbleSort(vector<int>& vec);
}
namespace InsertionSort{
    /**
     * T: O(n^2)->O(n) 自适应  效率优化 循环次数 n-1 n-2 ... 2 1 求和n*(n-1)/2
     * O: O(1) 原地
     * 稳定 */
    void insertionSort(vector<int>& vec);
}
/*
而在数据量较小时，复杂度不占主导地位，每轮中的单元操作数量起到决定性作用。
实际上，许多编程语言（例如 Java）的内置排序函数采用了插入排序，大致思路为：对于长数组，采用基于分治策略的排序算法，例如快速排序；对于短数组，直接使用插入排序。

冒泡排序基于元素交换实现，需要借助一个临时变量，共涉及 3 个单元操作；插入排序基于元素赋值实现，仅需 1 个单元操作。因此，冒泡排序的计算开销通常比插入排序更高。
选择排序在任何情况下的时间复杂度都为O(n^2)。如果给定一组部分有序的数据，插入排序通常比选择排序效率更高。
选择排序不稳定，无法应用于多级排序。
*/
namespace MergeSort {
    void merge(vector<int>& vec, int left, int mid, int right);
    void mergeSort(vector<int>& vec, int left, int right);
}

namespace HeapSort {
    void siftDown(vector<int>& num, int n, int i);
    void heapSort(vector<int>& num);
}

void sortTest();