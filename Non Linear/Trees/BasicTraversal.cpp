#include <iostream>
using namespace std;

struct node{
	node *left;
	int data;
	node *right;
};

node *createBinaryTree(){
	int data;
	cout << "Enter node data:";
	cin >> data;
	if(data==-1){
		// setting up a condition if user enters -1 then it means the user doesn't wants to add more nodes
		return nullptr;
	}

	node *root = new node;
	root->data = data;

	root->left = createBinaryTree();
	root->right = createBinaryTree();

	return root;
}

void inOrderTraversal(node *root){
	if(root==nullptr || root==NULL){
		return;
	}

	inOrderTraversal(root->left);
	cout << root->data << " " ;
	inOrderTraversal(root->right);
}

void preOrderTraversal(node *root){
	if(root==nullptr || root==NULL){
		return;
	}

	cout << root->data << " ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}

void postOrderTraversal(node *root){
	if(root==nullptr || root==NULL){
		return;
	}

	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout << root->data <<  " " ;
}


int main(){
	// implementing binary trees with three basic traversals in C++
	
	node *root;  // creating a root node for the binary tree
	root = createBinaryTree();

	cout << endl;
	int choice;
	cout << "Enter which type of tree traversal you want to display:";
	cout << "1. In-Order Traversal" << endl;
	cout << "2. Pre-Order Traversal" << endl;
	cout << "3. Post-Order Traversal" << endl;
	cout << "*. In Order Traversal" << endl;
	cout << "Enter your choice:";
	cin >> choice;
	cout << endl;

	switch(choice){
		case 1:
			inOrderTraversal(root);
			break;

		case 2:
			preOrderTraversal(root);
			break;
	
		case 3:
			postOrderTraversal(root);
			break;

		default:
			inOrderTraversal(root);
	}


	return 0;
}