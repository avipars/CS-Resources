/* C++ program to construct tree using
inorder and preorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;
};

/* Prototypes for utility functions */
int search(int arr[], int strt, int end, char value);
node *newNode(int data);
void printBT(node *);
void printFullTree(const string &prefix, node *, bool isLeft);
/* Recursive function to construct binary
of size len from Inorder traversal in[]
and Preorder traversal pre[]. Initial values
of inStrt and inEnd should be 0 and len -1.
The function doesnt do any error checking
for cases where inorder and preorder do not
form a tree */
node *buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;

    if (inStrt > inEnd)
       { return NULL;}

    /* Pick current node from Preorder
    traversal using preIndex
    and increment preIndex */
    node *tNode = newNode(pre[preIndex++]);

    /* If this node has no children then return */
    if (inStrt == inEnd)
        {return tNode;}

    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    /* Using index in Inorder traversal, construct left and
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

    return tNode;
}

/* UTILITY FUNCTIONS */
/* Function to find index of value in arr[start...end]
The function assumes that value is present in in[] */
int search(int arr[], int strt, int end, char value)
{
    for (int i = strt; i <= end; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1; //not found
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

/* This function is here just to test buildTree() */
void printInorder(node *node)
{
    if (node == NULL)
     {   return;}

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

void printPostOrder(node *node)
{
    if (node == NULL)
{        return;
}
    /* first recur on left child */
    printPostOrder(node->left);

    /* then recur on right child */
    printPostOrder(node->right);

    /* now print the data of node */
    cout << node->data << " ";
}

// BFS - via recursion
void printBreadth(node *nd)
{
    //if the tree is empty, simply return
	if (nd == NULL)
     {   return;}
	
	node* current = NULL;

	//create a queue that will hold node pointers
    queue<node*> q;

	//add the root to the queue
    q.push(nd);

	//while the queue is not empty, continue the process
	while (!q.empty())
	{
		//set current to be the first node in the queue
		//save value form the pop
        current = q.front();
        q.pop(); 
		
		//print the value in the node
		cout << current->data << " ";

		//put the left of current and right into the queue if they is exist
		if (current->left != NULL)
		{
			q.push(current->left);
		}

		if (current->right != NULL)
		{
			q.push(current->right);
		}
	}
}

void printBT(node *nd) //recursive wrapper fn 
{
    printFullTree("", nd, false);
}

void printFullTree(const string &prefix, node *nd, bool isLeft) //recursive function to print node, then call to children etc.
{
    if (nd != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "|--" : "L--");
        // print the value of the node
        std::cout << nd->data << std::endl;
        // enter the next tree level - left and right branch
        printFullTree(prefix + (isLeft ? "|   " : "    "), nd->left, true);
        printFullTree(prefix + (isLeft ? "|   " : "    "), nd->right, false);
    }
}

/* Driver code */
int main()
{  
    //given inorder and preorder traversal, print postorder traversal and breadth first scan (level order) of tree
    int in[] = { 1, 2, 3, 5, 7, 8, 9};
    int pre[] = {1, 2, 3, 8, 5, 7, 9};

    int len = sizeof(in) / sizeof(in[0]);
    node *root = buildTree(in, pre, 0, len - 1);

    cout << "postorder" << endl;
    printPostOrder(root);
    cout << endl; 

    cout << "bfs" << endl;
    printBreadth(root);
    cout << endl;

    printBT(root);
    return 0;
}