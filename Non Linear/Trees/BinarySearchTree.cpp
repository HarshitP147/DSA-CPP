#include <iostream>
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

void inOrderTraversal(node *root){
	if(root){
		inOrderTraversal(root->left);
		cout << root->data << " ";
		inOrderTraversal(root->right);
	}
}

// class based implementation of a BST
struct BinarySearchTree{
	node *root = nullptr;

	void addNewNode(node *newNode);

	node *minValueNode(node *Node){
		// helper function to return the minimum value of the BST
		node *current = Node;
		while(current->left!=nullptr){
			current = current->left;
		}
		return current;
	}

	node *deleteNode(node *root,int value);

	bool iterativeSearch(int value){
		if(root==nullptr){
			return false;
		}
		else{
			node *temp = root;
			while(temp!=nullptr){
				if(temp->data==value){
					return true;
				}
				else if(value < temp->data){
					temp = temp->right;
				}
				else if(value > temp->data){
					temp = temp->left;
				}
			}
			return false;
		}
	}

};


void BinarySearchTree::addNewNode(node *newNode){
	if(root==nullptr){
		root = newNode;
	}
	else{
		node *temp = root;
		while(temp!=nullptr){
			if(temp->data == newNode->data){
				return;  // duplicate nodes are not allowed
			}
			else if((newNode->data < temp->data) && (temp->left==nullptr)){
				temp->left = newNode;
			}
			else if(newNode->data < temp->data){
				temp = temp->left;
			}
			else if((newNode->data > temp->data) && (temp->right==nullptr)){
				temp->right = newNode;
			}
			else if(newNode->data > temp->data){
				temp = temp->right;
			}
		}
	}
}

node *BinarySearchTree::deleteNode(node *root,int value){
	if(root==nullptr){
		return root;
	}
	else if(value < root->data){
		root->left = deleteNode(root->left,value);
	}
	else if(value > root->data){
		root->right = deleteNode(root->right,value);
	}
	else{
		// condition in which we find the value to be deleted
		node *temp;
		if(root->left==nullptr){
			// node with only right child
			temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==nullptr){
			// node with only left child
			temp = root->left;
			delete root;
			return temp;
		}
		else{
			// node with two children
			temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right,temp->data);
		}
	}
}

int treeHeight(node *root){
	if(root==nullptr){
		return -1;
	}
	else{
		int lheight = treeHeight(root->left);
		int rheight = treeHeight(root->right);
		if(lheight>rheight){
			return (lheight+1);
		}
		else{
			return (rheight+1);
		}
	}
}

void printTreeLevel(node *root,int level){
	if(root==nullptr){
		return;
	}
	else if(level==0){
		cout << root->data << " ";
	}
	else{
		printTreeLevel(root->left,level-1);
		printTreeLevel(root->right,level-1);
	}
}

void levelOrderTraversal(node *root){
	int h = treeHeight(root);
	for(int i=0;i<=h;i++){
		printTreeLevel(root,i);
	}
}


int main(){
	// implementing binary search trees in C++
	BinarySearchTree bs;  // implementing using one instance of the BST object

	bool running = true;

	while(running){
		cout << endl;
		cout << "1. Add a new node in the binary search tree" << endl;
		cout << "2. Delete a node from the binary search tree" << endl;
		cout << "3. Search for a node in the binary search tree" << endl;
		cout << "4. Traverse and print the tree using inorder traversal" << endl;
		cout << "5. Traverse and print the tree using level order traversal" << endl;
		cout << "6. Exit the prompt" << endl;
		int choice;
		cout << "Enter your choice:";
		cin >> choice;
		cout << endl;
	
		switch(choice){
			case 1:
				node *temp;
				temp = new node;
				cout << "Enter node value:";
				cin >> temp->data;

				temp->left = nullptr;
				temp->right = nullptr;

				bs.addNewNode(temp);

				break;

			case 2:
				int value;
				bool nodePresent;
				cout << "Enter the value ot be deleted from the binary search tree:";
				cin >> value;
				nodePresent = bs.iterativeSearch(value);
				if(nodePresent){
					node *delNode;
					delNode = bs.deleteNode(bs.root,value);
					if(delNode){
						cout << "Node deleted from the binary search tree with value:" << delNode->data << endl;
					}
					else{
						cout << "Node was not deleted from the binary search tree !!" << endl;
					}
				}
				else{
					cout << "The node you want to delete is not present in the binary search tree !!" << endl;
				}			
				break;

			case 3:
				
				cout << "Enter the value you are searching for:";
				cin >> value;
				nodePresent = bs.iterativeSearch(value);
				if(nodePresent){
					cout << "Node is present in the binary search tree" << endl;
				}
				else{
					cout << "Node is not present in the binary search tree" << endl;
				}
				break;

			case 4:
				cout << "Inorder traversal of the tree:" << endl;
				inOrderTraversal(bs.root);
				cout << endl;
				break;

			case 5:
				cout << "Level order traversal of the tree:" << endl;
				levelOrderTraversal(bs.root);
				cout << endl;
				break;

			case 6:
				running = false;
				break;
		}
	}


	return 0;
}