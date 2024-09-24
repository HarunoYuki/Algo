#include "tree.hpp"

void treeTest() {
    //TreeNode node5(1, nullptr, nullptr);
    //TreeNode node4(2, nullptr, nullptr);
    //TreeNode node3(3, nullptr, &node4);
    //TreeNode node2(4, nullptr, &node5);
    //TreeNode node1(5, &node3, nullptr);
    //TreeNode root(0, &node1, &node2);

    //cout << "Level Order: " << endl;
    //levelOrder(&root);
    //cout << "\nRecursive preorder: " << endl;
    //RecursiveDFS::preorder(&root);
    //cout << "\nRecursive inorder: " << endl;
    //RecursiveDFS::inorder(&root);
    //cout << "\nRecursive postorder: " << endl;
    //RecursiveDFS::postorder(&root);
    //cout << "\nIterative preorder: " << endl;
    //IterativeDFS::preorder(&root);
    //cout << "\nIterative inorder: " << endl;
    //IterativeDFS::inorder(&root);
    //cout << "\nIterative postorder: " << endl;
    //IterativeDFS::postorder(&root);

    vector<int> vec = {1,2,3,5,1,47,63,75};
    MaxHeap h;
    for (int v: vec) {
        h.push(v);
    }
    h.print();
}