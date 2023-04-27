#include <iostream>
using namespace std;

struct node{
	int value;
	node *left;
	node *right;

	node(){}
};

node *createTree(){
	int val;
	cout << "Enter node value:";
	cin >> val;

	if(val==-1){
		return nullptr;
	}

	node *root = new node;

	root->value = val;

	root->left = createTree();
	root->right = createTree();

	return root;
}

void treePrettyPrint(node *root,string prefix = "",bool isRight = false){
	if(root==nullptr){
		cout << "Empty tree" << endl;
		return;
	}

	if(root->right){
		treePrettyPrint(root->right,prefix+(isRight ? "    " : "│   "),true);
	}

	cout << prefix + (isRight ? "┌── " : "└── ")  << to_string(root->value) << '\n';
	
	if(root->left){
		treePrettyPrint(root->left,prefix+(isRight ? "│   " : "    "),false);
	}
}

int main(){
	// C++ program to pretty print a tree
	// Original code taken from Leetcode website

	node *root;
	cout << "Root node created. Enter value as -1 as the null value." << endl;

	root = createTree();

	treePrettyPrint(root);

	return 0;
}
