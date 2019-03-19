#include <stdio.h>
#include <stdlib.h>
/*A binary tree node has data, pointer
 to left child and a pointer to right*/
//create root, left, and right nodes
struct node
{
	int root;//first node "root"
	struct node* left;//left nodes
	struct node* right;//right nodes
};

/* Function that allocates a new node with the given data
and NULL left and right pointers */

struct node* newNode(int root)
{ 
struct node* node = (struct node*)
			malloc(sizeof(struct node));
node->root = root;
node->left = NULL;
node->right = NULL;
return(node);
}

/* given a binary tree, print its nodes in preorder*/ 
void printPreorder(struct node* node)
{
if(node==NULL)
	return;
//first print the root node
printf("%d ", node->root);
//first traverse left
printPreorder(node->left);
//now travers the right
printPreorder(node->right);
}
/* Main func*/
int main()
{
	//Create the structure of the tree with pre-defined values
struct node *root = newNode(1);//root
root->left	=newNode(2);//left child
root->right	=newNode(3);//right child
root->left->left	=newNode(4);
root->left->right	=newNode(5);
//print the tree
printf("\nPreorder traversal of binary tree is\n");
printPreorder(root);

getchar();
return 0;
}


