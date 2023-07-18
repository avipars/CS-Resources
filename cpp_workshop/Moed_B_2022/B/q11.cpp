#include <iostream>
#include <queue>
using namespace std; 

class Node
{
public:
    Node *left;
    // מצביע לבן שמאל
    Node *right;
    // מצביע לבן ימין
    Node *next;
    // מצביע לצומת הבא באותה הרמה
    int value;
    // ערך של הצומת
    int level;
    // הרמה של הצומת
    Node(int val, int lv = 0) : value(val), level(lv), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int val, Node *l, Node *r, Node *n, int lv) : value(val), left(l), right(r), next(n), level(lv) {}
};

void SearchTree::add(int val)
{
    // add value to binary search tree
    if (!root)
    {
        root = new Node(val);
        return;
    }
    add(root, val, 1);
}

//part A
void SearchTree::add(Node *current, int val, int level)
{
    if (current->value < val)
    {
        jf(!current->right)
        {
            current->right = new Node(nullptr, nullptr,nullptr,level);
            return;
        }
        else add(current->right, val, level + 1);
    }
    else{
        if (!current->left)
        {
            current->left = new Node(nullptr, nullptr,nullptr,level);
            return;
        }
        else add(current->left, val, level + 1);
    }
}



//part B  (needs work)

 // Function to connect nodes at the same level
 // (connect method) may be incorrect and/or incomplete
//  To implement the connect method in the binary search tree to connect all nodes at the same level to a linked list, we can use a breadth-first traversal approach using the STL queue. Each level of the tree will be traversed, and we will connect the nodes at the same level through their next pointers.
    void connect() {
        if (root == nullptr) {
            return;
        }

        nodeQueue.push(root);

        while (!nodeQueue.empty()) {
            int levelSize = nodeQueue.size();
            Node* prev = nullptr;
            
            for (int i = 0; i < levelSize; i++) {
                Node* current = nodeQueue.front();
                nodeQueue.pop();

                if (prev != nullptr) {
                    prev->next = current;
                }

                prev = current;

                if (current->left) {
                    nodeQueue.push(current->left);
                }

                if (current->right) {
                    nodeQueue.push(current->right);
                }
            }
        }
    }
