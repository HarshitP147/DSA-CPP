// delete first node
// delete last node
// delete from the middle
#include <bits/stdc++.h>
using namespace std;

struct node{
	string name;
	node *next;
};

void displayLinkedList(node *start,int count){
	node *display;
	display = start;
	cout << endl;
	for(int i=1;i<=count;i++){
		cout << "Node name:" << display->name << endl;
		display = display->next;
	}	
	cout << endl;
}

node *addNewNode(){
	node *temp;
	temp = new node;
	cout << endl;
	cout << "Enter node name:" ;
	cin >> temp->name;

	return temp;
}

void deleteLastNode(node *start,int count){
	// deleting the last node
	node *deleteNode;
	deleteNode = start;
	for(int i=1;i<count;i++){
		deleteNode = deleteNode->next;
	}	
	delete deleteNode;
	cout << endl;
}

void deleteNodePos(node *start,int pos){
	node *prevEle;
	prevEle = start;

	node *delVar;
	delVar = start;

	node *nextEle;
	nextEle = start;

	for(int i=1;i<pos-1;i++){
		prevEle = prevEle->next;	
	}	
	// arriving one position before the element is to be deleted
	// cout << prevEle->name << endl;

	for(int i=1;i<pos;i++){
		delVar = delVar->next;
	}

	for(int i=1;i<pos+1;i++){
		nextEle = nextEle->next;
	}	
	// arriving one positon after the element is to be added
	// cout << nextEle->name << endl;

	// now the prev value must point to the value next to it
	prevEle->next = nextEle;

	delete delVar;  // deleting the node at that position1

	cout << endl;
}	


int main(){
	node *list;
	list = NULL;
	int count =0;

	node *start;

	bool running = true;
	while(running){
		int choice;
		cout << "1. Add a new node" << endl;
		cout << "2. Display the linked list" << endl;
		cout << "3. Delete the last node" << endl;
		cout << "4. Delete the first node" << endl;
		cout << "5. Delete a node from a position" << endl;
		cout << "6. Delete node from a position user enters" << endl;
		cout << "7. Exit" << endl;
		cout << "Enter your choice:";
		cin >> choice;

		switch(choice){
			case 1:
				node *temp;
				temp = addNewNode();

				if(list==NULL){
					list = temp;
					start = temp;
				} else{
					list->next = temp;
					list = list->next;
				}
				count++;
				cout << endl;
				break;

			case 2:
				displayLinkedList(start,count);
				break;

			case 3:
				// deleting the last node
				deleteLastNode(start,count);
				count--;
				break;

			case 4:
				// deleting the first node
				node *delFirstNode;
				delFirstNode = start;
				delete delFirstNode;
				start = start->next;
				count--;
				cout << endl;
				break;

			case 5:
				// deleting the node from a position
				int pos;
				cout << "Enter the position of the node to be deleted:" ;
				cin >> pos;
				deleteNodePos(start,pos);
				count--;
				break;

			case 6:
				cout << "Enter where you want to delete the node in the linked list:";
				int position;
				cin >> position;
				if(position==1){
					// delete the first element
					node *first;
					first = start;
					delete first;
					start = start->next;
				}
				if(position>count){
					// delete the last element
					deleteLastNode(start,count);
				}
				if(position<count && position>1){
					// delete node at one position
					deleteNodePos(start,position);
				}
				count--;
				cout << endl;
				break;

			case 7:
				running = false;
				break;	
			default:
				running = false;
		}
	}



	return 0;
}	