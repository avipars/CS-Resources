// C++ program to print BST in given range
// #include<bits/stdc++.h>
#include <iostream>
using namespace std;

/* A Binary Tree node */
class TNode
{
	public:
	int data;
	TNode* left;
	TNode* right;
    int BF; 
};

TNode* newNode(int data);

/* A function that constructs Balanced
Binary Search Tree from a sorted array */
TNode* sortedArrayToBST(int arr[],
						int start, int end)
{
	/* Base Case */
	if (start > end)
	return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	TNode *root = newNode(arr[mid]);

	/* Recursively construct the left subtree
	and make it left child of root */
	root->left = sortedArrayToBST(arr, start,
									mid - 1);
	//set balancing factor 

	/* Recursively construct the right subtree
	and make it right child of root */
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

int height(TNode *node)
{
	//base case
	if (node == NULL) 
	return 0;
	else
	{
		/* compute  height of each subtree */
		int lheight = height(node->left);
		int rheight = height(node->right);

		/* use the larger one */
		if (lheight > rheight)
		return(lheight + 1);
		else return(rheight + 1);
	}
}

void setBF(TNode * root){
	if(root == NULL)
		return;
	// root->BF = height(root->right) - height(root->left);
	root->BF = root->right->BF - root->left->BF;
	setBF(root->left);
	setBF(root->right);
}

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
TNode* newNode(int data)
{
	TNode* node = new TNode();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* A utility function to print
preorder traversal of BST */
void preOrder(TNode* node)
{
	if (node == NULL)
		return;
	setBF(node);
	cout << node->data << " (" << node->BF << ") ";
	preOrder(node->left);
	preOrder(node->right);
}

void printBT(const std::string& prefix, const TNode* node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->data << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const TNode* node)
{
    printBT("", node, false);    
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Convert List to BST */
	TNode *root = sortedArrayToBST(arr, 0, n-1);
	cout << "PreOrder Traversal of constructed BST \n";
	preOrder(root);
 
    cout << endl;

    printBT(root);

	return 0;
}

// This code is contributed by rathbhupendra
