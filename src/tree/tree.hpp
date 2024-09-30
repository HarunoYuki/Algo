#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>

using std::vector;
using std::stack;
using std::queue;
using std::cout;
using std::endl;

struct TreeNode{
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int v) :val(v), lchild(nullptr), rchild(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) :val(v), lchild(l), rchild(r) {}
};

void levelOrder(TreeNode* root);

namespace RecursiveDFS{
    void preorder(TreeNode* root);
    void inorder(TreeNode* root);
    void postorder(TreeNode* root);
}

namespace IterativeDFS {
    void preorder(TreeNode* root);
    void inorder(TreeNode* root);
    void postorder(TreeNode* root);
}

class MaxHeap
{
public:
    MaxHeap() {}
    ~MaxHeap() {}
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int size() {
        return h.size();
    }
    bool empty() {
        return h.size() == 0;
    }
    int peek() {
        if (empty()) {
            throw("Empty Heap");
        }
        return h[0];
    }
    void push(int val) {
        h.push_back(val);
        siftUp(h.size() - 1);
    }
    void siftUp(int idx) {
        while (true) {
            int p = parent(idx);
            if (p < 0 || h[p] >= h[idx]) {
                break;
            }
            std::swap(h[idx], h[p]);
            idx = p;
        }
    }
    void pop() {
        if (empty()) {
            throw("Empty Heap");
        }
        std::swap(h[0], h[size() - 1]);
        h.pop_back();
        siftDown(0);
    }
    void siftDown(int idx) {
        while (true) {
            int l = left(idx);
            int r = right(idx);
            int ma = idx;
            if (l<size() && h[l]> h[ma]) {
                ma = l;
            }
            if (r<size() && h[r]>h[ma]) {
                ma = r;
            }
            //no greater val
            if (ma == idx) {
                break;
            }
            std::swap(h[idx], h[ma]);
            idx = ma;
        }
    }
    void print() {
        for (int v : h) {
            cout << v << " ";
        }
        cout << endl;
    }

private:
    vector<int> h;
};

void treeTest();