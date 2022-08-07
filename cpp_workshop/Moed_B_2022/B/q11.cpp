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


//part B - WIP 