#include <iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

node *createTree(){
	int data;
	cout << "Enter node data:";
	cin >> data;
	if(data==-1){
		return nullptr;
	}

	node *root = new node;
	root->data = data;

	root->left = createTree();
	root->right = createTree();

	return root;
}

void inOrderTraversal(node *root){
	if(root!=nullptr){
		inOrderTraversal(root->left);
		cout << root->data << " ";
		inOrderTraversal(root->right);
	}
}

node *invertingTree(node *root){
	if(root!=nullptr){
		node *tempNode = root->left;
		root->left = root->right;
		root->right = tempNode;
		invertingTree(root->left);
		invertingTree(root->right);
	}
	return root;
}



int main(){
	// inverting a tree in C++	
	node *root;
	root = createTree();

	cout << endl;
	cout << "Displaying inorder traversal of the trees:" << endl;
	// using only In-order traversal to display the trees
	cout << "Original tree:" << endl;
	inOrderTraversal(root);
	cout << endl;

	invertingTree(root);

	cout << "Inverted tree:" << endl;
	inOrderTraversal(root);
	cout << endl;

	return 0;
}