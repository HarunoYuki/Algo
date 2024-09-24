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

//void levelOrder(TreeNode* root) {
//    if (root == nullptr) { return; }
//    queue<TreeNode*> q;
//    q.push(root);
//    while (!q.empty()) {
//        TreeNode* node = q.front();
//        q.pop();
//        cout << node->val << " ";
//        if (node->lchild != nullptr)
//            q.push(node->lchild);
//        if (node->rchild != nullptr)
//            q.push(node->rchild);
//    }
//}
//
//namespace RecursiveDFS{
//    void preorder(TreeNode* root){
//        if (root == nullptr) { return; }
//        cout << root->val << " ";
//        preorder(root->lchild);
//        preorder(root->rchild);
//    }
//
//    void inorder(TreeNode* root){
//        if (root == nullptr) { return; }
//        inorder(root->lchild);
//        cout << root->val << " ";
//        inorder(root->rchild);
//    }
//
//    void postorder(TreeNode* root){
//        if (root == nullptr) { return; }
//        postorder(root->lchild);
//        postorder(root->rchild);
//        cout << root->val << " ";
//    }
//}
//
//namespace IterativeDFS {
//    void preorder(TreeNode* root) {
//        if (root == nullptr) { return; }
//        stack<TreeNode*> s;
//        while (!s.empty() || root != nullptr) {
//            while (root != nullptr) {
//                cout << root->val << " ";
//                s.emplace(root);
//                root = root->lchild;
//            }
//            root = s.top();
//            s.pop();
//            root = root->rchild;
//        }
//    }
//    void inorder(TreeNode* root) {
//        if (root == nullptr) { return; }
//        stack<TreeNode*> s;
//        while (!s.empty() || root != nullptr) {
//            while (root != nullptr) {
//                s.emplace(root);
//                root = root->lchild;
//            }
//            root = s.top();
//            s.pop();
//            cout << root->val << " ";
//            root = root->rchild;
//        }
//    }
//    void postorder(TreeNode* root) {
//        if (root == nullptr) { return; }
//        stack<TreeNode*> s;
//        TreeNode* pre = nullptr;
//        while (!s.empty() || root != nullptr) {
//            while (root != nullptr) {
//                s.emplace(root);
//                root = root->lchild;
//            }
//            root = s.top();
//            s.pop();
//            if (root->rchild == nullptr || root->rchild == pre) {
//                cout << root->val << " ";
//                pre = root;
//                root = nullptr;
//            }
//            else {
//                s.emplace(root);
//                root = root->rchild;
//            }
//        }
//    }
//}

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
        int len = h.size();
        while (true) {
            int l = left(idx);
            int r = right(idx);
            int ma = idx;
            if (l<len && h[l]> h[ma]) {
                ma = l;
            }
            if (r<len && h[r]>h[ma]) {
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