#include <iostream>
using namespace std;

#define maxNodes 7

struct node{
	int data;
	node *next;
};


int main(){
	// queues using linked list
	node *front,*rear;

	front=nullptr;
	rear=nullptr;

	int count = 0;

	bool running = true;


	while(running){
		cout << endl;
		cout << "1. Enqueue a node into the queue list" << endl;
		cout << "2. Dequeue a node from the queue list" << endl;
		cout << "3. Peek the nodes into the queue list" << endl;
		cout << "4. Display the queue using linked list" << endl;
		cout << "5. Exit " << endl;
		int choice;
		cout << "Enter your choice:";
		cin >> choice;
		cout << endl;

		switch(choice){
			case 1:
				if(front==rear || count==maxNodes){
					cout << "Queue overflow, cannot add more nodes !!" << endl;
					break;
				}

				node *newNode = new node;
				cout << "Enter node value:";
				cin >> newNode->data;

				if(front==rear && front==nullptr){
					front=newNode;
				}
				rear = newNode;
				count++;

				break;

			case 2:
				break;

			case 3:
				break;

			case 4:
				break;

			case 5:
				running = false;
				break;
		}
	}

	return 0;
}