#include "sort.hpp"
#include <algorithm>

namespace QuickSort {
    /**
     * T: O(nlogn)->O(n^2) ƽ��logn�� ÿ��n  ��׼���Ż���ѡ��������������λ��Ϊ��׼��
     * O: O(n)->O(logn) ջ֡ β�ݹ��Ż���ֻ�ݹ�����̵�һ��
     * */
    int partition(vector<int>& num, int left, int right) {
        int i = left, j = right;
        while (i < j) {
            while (i < j && num[j] >= num[left])j--;
            while (i < j && num[i] <= num[left])i++;
            swap(num[i], num[j]);
        }
        swap(num[i], num[left]);
        return i;
    }
    void quickSort(vector<int>& num, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = partition(num, left, right);
        quickSort(num, left, pivot - 1);
        quickSort(num, pivot + 1, right);
    }
}
namespace SelectionSort {
    /**
     * T: O(n^2) ������Ӧ ѭ������ n-1 n-2 ... 2 1 ���n*(n-1)/2
     * O: O(1) ԭ��
     * ���ȶ� */
    void selectionSort(vector<int>& vec) {
        int n = vec.size();
        for (size_t i = 0; i < n - 1; i++)
        {
            int k = i;
            for (size_t j = i + 1; j < n; j++)
            {
                if (vec[j] < vec[k]) k = j;
            }
            swap(vec[i], vec[k]);
        }
    }
}
namespace BubbleSort {
    /**
     * T: O(n^2)->O(n) ����Ӧ  Ч���Ż� ѭ������ n-1 n-2 ... 2 1 ���n*(n-1)/2
     * O: O(1) ԭ��
     * �ȶ� */
    void bubbleSort(vector<int>& vec) {
        int n = vec.size();
        for (size_t i = n - 1; i > 0; i--)
        {
            bool flag = false;
            for (size_t j = 0; j < i; j++)
            {
                if (vec[j] > vec[j + 1]) {
                    flag = true;
                    swap(vec[j], vec[j + 1]);
                }
            }
            if (!flag) { break; }
        }
    }
}
namespace InsertionSort {
    /**
     * T: O(n^2)->O(n) ����Ӧ  Ч���Ż� ѭ������ n-1 n-2 ... 2 1 ���n*(n-1)/2
     * O: O(1) ԭ��
     * �ȶ� */
    void insertionSort(vector<int>& vec) {
        for (int i = 1; i < vec.size(); i++) {
            int base = vec[i], j = i - 1;
            for (j; j >= 0 && vec[j] > base; --j) {
                vec[j + 1] = vec[j];
            }
            vec[j + 1] = base;
        }
    }
}
/*
������������Сʱ�����ӶȲ�ռ������λ��ÿ���еĵ�Ԫ���������𵽾��������á�
ʵ���ϣ���������ԣ����� Java�������������������˲������򣬴���˼·Ϊ�����ڳ����飬���û��ڷ��β��Ե������㷨������������򣻶��ڶ����飬ֱ��ʹ�ò�������

ð���������Ԫ�ؽ���ʵ�֣���Ҫ����һ����ʱ���������漰 3 ����Ԫ�����������������Ԫ�ظ�ֵʵ�֣����� 1 ����Ԫ��������ˣ�ð������ļ��㿪��ͨ���Ȳ���������ߡ�
ѡ���������κ�����µ�ʱ�临�Ӷȶ�ΪO(n^2)���������һ�鲿����������ݣ���������ͨ����ѡ������Ч�ʸ��ߡ�
ѡ�������ȶ����޷�Ӧ���ڶ༶����
*/
namespace MergeSort {
    void merge(vector<int>& vec, int left, int mid, int right) {
        vector<int> tmp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (vec[i] > vec[j])
                tmp[k++] = vec[j++];
            else
                tmp[k++] = vec[i++];
        }
        while (i <= mid) {
            tmp[k++] = vec[i++];
        }
        while (j <= right) {
            tmp[k++] = vec[j++];
        }
        for (int p = 0; p < k; ++p) {
            vec[left + p] = tmp[p];
        }
    }
    void mergeSort(vector<int>& vec, int left, int right) {
        if (left >= right) { return; }
        int mid = left + (right-left) / 2;
        mergeSort(vec,left,mid);
        mergeSort(vec,mid+1,right);
        merge(vec,left,mid,right);
    }
}

namespace HeapSort {
    void siftDown(vector<int>& num, int n, int i) {
        while (true) {
            int l = 2 * i + 1, r = 2 * i + 2, ma = i;
            if (l<n && num[l]>num[ma]) {
                ma = l;
            }
            if (r<n && num[r]>num[ma]) {
                ma = r;
            }
            if (ma == i) {
                return;
            }
            swap(num[ma], num[i]);
            i = ma;
        }
    }
    void heapSort(vector<int>& num) {
        for (int i = num.size() / 2 - 1; i >= 0; --i) {
            siftDown(num, num.size(), i);
        }
        for (int i = num.size() - 1; i >= 0; --i) {
            swap(num[0], num[i]);
            siftDown(num, i, 0);
        }
    }
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

    vec = { 2,4,3,8,1,6,4 };
    HeapSort::heapSort(vec);
    cout << "Heap Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec = { 2,4,3,8,1,6,4 };
    sort(vec.begin(), vec.end(), std::less<int>());
    cout << "Lib Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    vec = { 2,4,3,8,1,6,4 };
    sort(vec.begin(), vec.end(), std::greater<int>());
    cout << "Lib Sort: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}