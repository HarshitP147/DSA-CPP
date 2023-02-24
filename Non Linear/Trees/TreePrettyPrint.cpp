#include <iostream>
#include <math.h>
using namespace std;

#define COUNT 10

struct node{
	int value;
	node *left;
	node *right;
};

node *createTree(){
	int value;
	cout << "Enter node value:";
	cin >> value;
	if(value==-1){
		return nullptr;
	}

	node *root = new node;
	root->value = value;

	root->left = createTree();
	root->right = createTree();

	return root;
}

// this is basically inOrderTraversal on a better format 
void prettyPrintTree(node *root,int space){
	if(root==nullptr || root==NULL){
		return;
	}

	// increase the distance between levels
	space+=COUNT;

	// process the right child
	prettyPrintTree(root->right,space);

	cout << endl;
	for(int i=COUNT;i<space;i++){
		cout << " ";
	}
	cout << root->value << endl;

	// process the left child
	prettyPrintTree(root->left,space);
}

int main(){
	// fun C++ program to pretty print the tree in the terminal	
	node *root ;
	cout << "Root of the tree created, enter -1 to terminate the tree" << endl;
	root = createTree();
	cout << endl;

	prettyPrintTree(root,0);


	return 0;
}