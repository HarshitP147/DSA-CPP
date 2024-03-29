#include <iostream>
using namespace std;

struct node{
	node *left;
	int data;
	node *right;
};

node *createTree(){
	int data;
	cout << "Enter node data:";
	cin >> data;
	if(data==-1){
		// setting up a condition if user enters -1 then it means the user doesn't wants to add more nodes
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
		cout << root->data << " " ;
		inOrderTraversal(root->right);
	}
}

void preOrderTraversal(node *root){
	if(root!=nullptr){
		cout << root->data << " ";
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}

void postOrderTraversal(node *root){
	if(root!=nullptr){
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout << root->data <<  " " ;
	}
}

int treeHeight(node *root){
	if(root==nullptr){
		return 0;
	}
	else{
		// find the height of the left and right side
		int leftHeight = treeHeight(root->left);
		int rightHeight = treeHeight(root->right);

		int maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;  // find and return the max height of the tree

		return maxHeight+1;
	}
}

void printLevel(node *root,int level){
	if(root==nullptr){
		return;
	}
	if(level==0){
		cout << root->data << " " ;
	}
	else{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);
	}
}

void levelOrderTraversal(node *root){
	int height = treeHeight(root);
	for(int i=0;i<height;i++){
		printLevel(root,i);
	}
	cout << endl;
}

int main(){
	// implementing binary trees with three basic traversals in C++
	
	node *root = NULL;  // creating a root node for the binary tree
	root = createTree();

	cout << endl;
	int choice;
	cout << "Enter which type of tree traversal you want to display:" << endl;
	cout << "1. In-Order Traversal" << endl;
	cout << "2. Pre-Order Traversal" << endl;
	cout << "3. Post-Order Traversal" << endl;
	cout << "4. Level-Order Traversal" << endl;
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

		case 4:
			levelOrderTraversal(root);
			break;

		default:
			inOrderTraversal(root);
	}


	return 0;
}