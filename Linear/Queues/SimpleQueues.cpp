#include <iostream>
using namespace std;

#define len 7

int que[len];
int front = -1,rear = -1;

void push(){
	if(front==0 && rear==len-1){
		cout << "Queue overflow, cannot add more elements!!" << endl;
	} else{
		int ele;
		cout << "Enter element:";
		cin >> ele;

		if(front==-1 && rear==-1){
			front = 0;
			rear = 0;
		} else{
			rear++;
		}
		que[rear] = ele;
	}
}

void pop(){
	if(front==-1 && rear==-1){
		cout << "Queue underflow, cannot delete any elements !!" << endl;
	} else{
		int delEle = que[front];
		if(front==rear){
			front = -1;
			rear = -1;
		} else{
			front++;
		}
		cout << "Element popped from the queue:" << delEle << endl;
	}
}


void displayQueue(){
	if(front==-1 && rear==-1){
		cout << "Emtpy queue, nothing to display !!" << endl;
	} else{
		int i = front;
		cout << "{" ;
		while(i<rear){
			cout << que[i] << ",";
			i++;

		}
		cout << que[rear] << "}" << endl;
	}
}


int main(){
	// Simple Queues in C++

	bool running = true;
	while(running){
		cout << endl;
		cout << "1. Push element to the queue" << endl;
		cout << "2. Pop element from the queue" << endl;
		cout << "3. Peek into front and rear elements" << endl;
		cout << "4. Display the queue" << endl;
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
				pop();
				break;

			case 3:
				if(front==-1 && rear==-1){
					cout << "Queue is empty, no front and rear to peek !!" << endl;
				} else{
					cout << "Element at the front:" << que[front] << endl;
					cout << "Element at the rear:" << que[rear] << endl;
				}
				break;

			case 4:
				displayQueue();
				break;

			case 5:
				running = false;
				break;
		}
	}



	return 0;
}