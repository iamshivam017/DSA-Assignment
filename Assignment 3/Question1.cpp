#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    int height;
    int size;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), height(0), size(1), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertAVL(const vector<int>& items, int threshold) {
        if (items.empty())
            return nullptr;

        TreeNode* root = new TreeNode(items[0]);

        for (size_t idx = 1; idx < items.size(); ++idx) {
            root = insert(root, items[idx], threshold);
        }

        return root;
    }

    // Get the height of a node
    int Height(TreeNode* node) {
        return (node == nullptr) ? -1 : getHeightHelper(node);
    }


private:
    // Insert a key into the AVL tree rooted at 'node'
    TreeNode* insert(TreeNode* node, int key, int threshold) {
        if (!node)
            return new TreeNode(key);

        if (key < node->val) {
            node->left = insert(node->left, key, threshold);
        } else if (key > node->val) {
            node->right = insert(node->right, key, threshold);
        } else {
            // Duplicate keys are not allowed
            return node;
        }

        // Update height of the ancestor node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        
        // update size of the ancestor node
        node->size = 1 + getSize(node->left) + getSize(node->right);

        // Check for imbalance
        int balance = getBalance(node);

        // Balance the tree
        if (balance > threshold) {
            if (getBalance(node->left) >= 0) {
                return rightRotate(node);
            } else {
                return leftRightRotate(node);
            }
        } else if (balance < -threshold) {
            if (getBalance(node->right) <= 0) {
                return leftRotate(node);
            } else {
                return rightLeftRotate(node);
            }
        }

        return node;
    }

    // Delete a key from the AVL tree rooted at 'node'
    TreeNode* deleteNode(TreeNode* root, int key, int threshold) {
        if (!root)
            return root;

        // Perform standard BST delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key, threshold);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key, threshold);
        } 
        else {
            // Node with only one child or no child
            if (!root->left || !root->right) {
                TreeNode* temp = root->left ? root->left : root->right;

                // No child case
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else {
                    // One child case
                    *root = *temp;
                }
                delete temp;
            } else {
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                TreeNode* temp = minValueNode(root->right);

                // Copy the inorder successor's value to this node
                root->val = temp->val;

                // Delete the inorder successor
                root->right = deleteNode(root->right, temp->val, threshold);
            }
        }

        // If the tree had only one node then return
        if (!root)
            return root;

        // Update height of the current node
        root->height = 1 + max(getHeight(root->left), getHeight(root->right));


        // Update size of the current node
        root->size = 1 + getSize(root->left) + getSize(root->right);

        // Get the balance factor of this node
        int balance = getBalance(root);

        // Balance the tree
        if (balance > threshold) {
            if (getBalance(root->left) >= 0) {
                return rightRotate(root);
            } else {
                return leftRightRotate(root);
            }
        } else if (balance < -threshold) {
            if (getBalance(root->right) <= 0) {
                return leftRotate(root);
            } else {
                return rightLeftRotate(root);
            }
        }

        return root;
    }

    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;

        // Loop down to find the leftmost leaf
        while (current->left != nullptr)
            current = current->left;

        return current;
    }

    // Get the height of a node
    int getHeight(TreeNode* node) {
        if (!node)
            return -1;
        return node->height;
    }

    // Helper function to get the height of a node
    int getHeightHelper(TreeNode* node) {
        if (!node) {
            return -1; // Base case: empty tree has height -1
        } else {
            // Recursively calculate the height of left and right subtrees
            int leftHeight = getHeightHelper(node->left);
            int rightHeight = getHeightHelper(node->right);

            // Return the maximum height + 1 for the current node
            return 1 + max(leftHeight, rightHeight);
        }
    }

    int getSize(TreeNode* node) {
        return node ? node->size : 0;
    }

    // Get the balance factor of a node
    int getBalance(TreeNode* node) {
        if (!node)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    // ======================================== R O T A T I O N S ========================================
    // Right rotate subtree rooted with y
    TreeNode* rightRotate(TreeNode* y) {
        TreeNode* x = y->left;
        TreeNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        // Return new root
        return x;
    }

    // Left rotate subtree rooted with x
    TreeNode* leftRotate(TreeNode* x) {
        TreeNode* y = x->right;
        TreeNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        // Return new root
        return y;
    }

    // Left Right rotate subtree rooted with z
    TreeNode* leftRightRotate(TreeNode* z) {
        z->left = leftRotate(z->left);
        return rightRotate(z);
    }

    // Right Left rotate subtree rooted with z
    TreeNode* rightLeftRotate(TreeNode* z) {
        z->right = rightRotate(z->right);
        return leftRotate(z);
    }

    // ======================== P U B L I C  F U N C T I O N S =================================

public:

    int order_of_key(TreeNode* root, int key) {
        if (!root)
            return 0;

        if (key <= root->val) {
            return order_of_key(root->left, key);
        } else {
            return 1 + getSize(root->left) + order_of_key(root->right, key);
        } 
        // else {
        //     return getSize(root->left);
        // }
    }

    int get_by_order(TreeNode* root, int k) {
        if (!root)
            return -1; // Return an invalid value if k is out of bounds

        int leftSize = getSize(root->left);

        if (k < leftSize) {
            return get_by_order(root->left, k);
        } else if (k > leftSize) {
            return get_by_order(root->right, k - leftSize - 1);
        } else {
            return root->val;
        }
    }
    

    // insert(key) : inserts the key into the tree
    TreeNode* insertSingle(TreeNode* root, int key, int threshold) {
        return insert(root, key, threshold);
    }

    // delete(key) : deletes the key from the tree
    TreeNode* remove(TreeNode* root, int key, int threshold) {
        return deleteNode(root, key, threshold);
    }

    
};

// Helper function to print the binary tree in-order
    void printInorder(TreeNode* root) {
        if (!root) return;
        printInorder(root->left);
        cout << root->val << " ";
        printInorder(root->right);
    }

// find(key) : returns true if key is present else false in the tree
    bool find(TreeNode* root, int key) {
        if (!root) return false;
        if (root->val == key) return true;
        if (key < root->val) return find(root->left, key);
        return find(root->right, key);
    }




int main() {
    Solution solution;
    vector<int> items = {10, 20, 30, 40, 50, 25};
    int threshold = 1;

    TreeNode* root = solution.insertAVL(items, threshold);

    cout << "Inorder traversal of the constructed AVL tree: ";
    printInorder(root);
    cout << endl;


    cout << "Height of the constructed AVL tree: " << solution.Height(root) << endl;

    
    cout << "Height of the updated AVL tree: " << solution.Height(root) << endl;

    cout << "Inorder traversal of the updated AVL tree: ";
    printInorder(root);
    cout << endl;

    // Insert a single element into the existing AVL tree
    root = solution.insertSingle(root, 60, threshold);

    cout << "Inorder traversal after inserting 60: ";
    printInorder(root);
    cout << endl;

    // Insert another element
    root = solution.insertSingle(root, 70, threshold);

    cout << "Inorder traversal after inserting 70: ";
    printInorder(root);
    cout << endl;

    // FIND KEY
    cout<<"Finding 70 in the AVL tree: "<<find(root, 70)<<endl;
    cout<<"Finding 100 in the AVL tree: "<<find(root, 100)<<endl;

     // Height of the updated AVL tree
    cout << "Height of the updated AVL tree: " << solution.Height(root) << endl;

    // Delete a single element from the existing AVL tree
    root = solution.remove(root, 25, threshold);

    cout << "Inorder traversal after deleting 25: ";
    printInorder(root);
    cout << endl;

    // Delete another element
    root = solution.remove(root, 10, threshold);

    cout << "Inorder traversal after deleting 10: ";
    printInorder(root);
    cout << endl;

    cout << "Order of key 30: " << solution.order_of_key(root, 30) << endl;
    cout << "3rd smallest element (0-based index): " << solution.get_by_order(root, 2) << endl;
    cout << "Order of key 50: " << solution.order_of_key(root, 60) << endl;


    return 0;
}