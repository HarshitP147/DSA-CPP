#include <iostream>
using namespace std;

#define len 7

struct node{
	string name;
	node *next;
} *top = nullptr;


void push(){
	node *newNode = new node;
	string nName;
	cout << "Enter node name:";
	cin >> nName;
	newNode->name = nName;

	newNode->next = nullptr;

	if(top==nullptr){
		top = newNode;
	} else{
		newNode->next = top;
		top = newNode;
	}
}

void pop(){
	node *delNode;
	delNode = top;
	top = top->next;

	delNode->next = nullptr;

	cout << "Deleting node with node name:" << delNode->name << endl;

	delete delNode;
}

void displayStackList(){
	node *display = top;

	while(top!=nullptr){
		cout << "Node name:" << top->name << endl;
		top = top->next;
	}
	cout << endl;
}


int main(){
	int count = 0;
	bool running = true;

	while(running){
		cout << endl;
		cout << "1. Push a new node to the stack list" << endl;
		cout << "2. Pop a new node from the stack list" << endl;
		cout << "3. Peek into the top node from the stack list" << endl;
		cout << "4. Display the stack list" << endl;
		cout << "5. Exit" << endl;
		int choice;
		cout << "Enter your choice:";
		cin >> choice;
		cout << endl;

		switch(choice){
			case 1:
				push();
				break;

			case 2:
				if(top==nullptr){
					cout << "Stack underflow, cannot delete any nodes !!" << endl;
				} else{
					pop();
				}
				break;

			case 3:
				if(top==nullptr){
					cout << "Stack list is empty" << endl;
				} else{
					cout << "Top node with the name:" << top->name << endl;
				}
				break;

			case 4:
				if(top==nullptr){
					cout << "Stack list is empty, no nodes to display!!" << endl;
				} else{
					displayStackList();
				}
				break;

			case 5:
				running = false;
				break;
		}
	}




	return 0;
}