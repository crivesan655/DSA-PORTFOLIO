#include <iostream>
#include <vector>
#include <algorithm> // For std::find, though not strictly needed here

// New Node structure for a Binary Search Tree
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

    // Constructor
    BSTNode(int value) : data(value), left(nullptr), right(nullptr) {}

    // Destructor for proper memory cleanup
    ~BSTNode() {
        // Recursive deletion for the tree
        delete left;
        delete right;
    }
};

// Function to insert a value into the BST
BSTNode* insert(BSTNode* root, int value) {
    // If the tree is empty, create a new node
    if (root == nullptr) {
        return new BSTNode(value);
    }

    // Traverse to the correct position based on BST rule
    if (value < root->data) {
        root->left = insert(root->left, value); // Insert left
    } else if (value > root->data) {
        root->right = insert(root->right, value); // Insert right
    }
    // If value equals root->data, do nothing (no duplicates)

    return root;
}

// In-order Traversal: Left -> Node -> Right (Prints sorted order)
void inOrderTraversal(BSTNode* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Pre-order Traversal: Node -> Left -> Right
void preOrderTraversal(BSTNode* root) {
    if (root == nullptr) return;
    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Post-order Traversal: Left -> Right -> Node
void postOrderTraversal(BSTNode* root) {
    if (root == nullptr) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}


int main() {
    BSTNode* root = nullptr;
    std::vector<int> values = {2, 3, 9, 18, 0, 1, 4, 5};

    // Insert all values into the BST
    for (int val : values) {
        root = insert(root, val);
    }
    
    // (Comparison)
    std::cout << "In-order Traversal:  ";
    inOrderTraversal(root);
    std::cout << "\n";

    // (Pre-order)
    std::cout << "Pre-order Traversal: ";
    preOrderTraversal(root);
    std::cout << "\n";

    // (Post-order)
    std::cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    std::cout << "\n";

    // Clean up memory
    delete root;

    return 0;
}
