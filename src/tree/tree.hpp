#pragma once
#include <iostream>
#include <stack>
#include <queue>

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

void levelOrder(TreeNode* root) {
    if (root == nullptr) { return; }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->lchild != nullptr)
            q.push(node->lchild);
        if (node->rchild != nullptr)
            q.push(node->rchild);
    }
}

namespace RecursiveDFS{
    void preorder(TreeNode* root){
        if (root == nullptr) { return; }
        cout << root->val << " ";
        preorder(root->lchild);
        preorder(root->rchild);
    }

    void inorder(TreeNode* root){
        if (root == nullptr) { return; }
        inorder(root->lchild);
        cout << root->val << " ";
        inorder(root->rchild);
    }

    void postorder(TreeNode* root){
        if (root == nullptr) { return; }
        postorder(root->lchild);
        postorder(root->rchild);
        cout << root->val << " ";
    }
}

namespace IterativeDFS {
    void preorder(TreeNode* root) {
        if (root == nullptr) { return; }
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                cout << root->val << " ";
                s.emplace(root);
                root = root->lchild;
            }
            root = s.top();
            s.pop();
            root = root->rchild;
        }
    }
    void inorder(TreeNode* root) {
        if (root == nullptr) { return; }
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->lchild;
            }
            root = s.top();
            s.pop();
            cout << root->val << " ";
            root = root->rchild;
        }
    }
    void postorder(TreeNode* root) {
        if (root == nullptr) { return; }
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        while (!s.empty() || root != nullptr) {
            while (root != nullptr) {
                s.emplace(root);
                root = root->lchild;
            }
            root = s.top();
            s.pop();
            if (root->rchild == nullptr || root->rchild == pre) {
                cout << root->val << " ";
                pre = root;
                root = nullptr;
            }
            else {
                s.emplace(root);
                root = root->rchild;
            }
        }
    }
}


void treeTest() {
    TreeNode node5(1,nullptr,nullptr);
    TreeNode node4(2,nullptr,nullptr);
    TreeNode node3(3,nullptr,&node4);
    TreeNode node2(4,nullptr,&node5);
    TreeNode node1(5,&node3,nullptr);
    TreeNode root(0, &node1, &node2);

    cout << "Level Order: " << endl;
    levelOrder(&root);
    cout << "\nRecursive preorder: " << endl;
    RecursiveDFS::preorder(&root);
    cout <<"\nRecursive inorder: "<< endl;
    RecursiveDFS::inorder(&root);
    cout <<"\nRecursive postorder: "<< endl;
    RecursiveDFS::postorder(&root);
    cout <<"\nIterative preorder: "<< endl;
    IterativeDFS::preorder(&root);
    cout <<"\nIterative inorder: "<< endl;
    IterativeDFS::inorder(&root);
    cout <<"\nIterative postorder: "<< endl;
    IterativeDFS::postorder(&root);
}