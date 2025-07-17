// find the sum of all the nodes in a binary tree using recursion

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cerr << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}   

// Function to find the sum of all nodes in the tree

int sumOfNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}

// Driver code

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    cout << "Sum of all nodes: " << sumOfNodes(root) << std::endl;
    return 0;
}   