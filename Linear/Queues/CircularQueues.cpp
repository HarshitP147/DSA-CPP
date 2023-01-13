#include <iostream>
using namespace std;

#define len 7

int que[len];
int front = -1,rear = -1;

void push(){
	if( (front==0 && rear==len-1) || front==rear+1 ){
		cout << "Queue overflow, cannot add more elements into the queue !!" << endl;
	} else{
		int ele;
		cout << "Enter element:";
		cin >> ele;

		if(front==-1 && rear==-1){
			front = 0;
			rear = 0;
		} else{
			rear = (rear+1)%len;
		}

		que[rear] = ele;
	}
}

void pop(){
	if( front==-1 && rear==-1 ){
		cout << "Queue underflow, cannot delete any elements from the queue !!" << endl;
	} else{
		int delEle = que[front];
		if(front==rear){
			front = -1;
			rear = -1;
		} else{
			front = (front+1)%len;
		}
		cout << "Element popped from the queue:" << delEle << endl;
	}
}

void displayQueue(){
	if(front==-1 && rear==-1){
		cout << "Emtpy queue, nothing to display !!" << endl;
	} else{
		if(front==rear){
			cout << que[front] << endl;
		} else{
			int i = front;
			cout << "{" << que[i++] << "," ;
			while(i<=rear){
				cout << que[i++] << ",";
			}
			cout << que[front] << "}" << endl;
		}
	}
}

int main(){
	// Circular queues in C++

	bool running = true;
	while(running){
		cout << endl;
		cout << "1. Push an element into the queue" << endl;
		cout << "2. Pop an element from the queue" << endl;
		cout << "3. Peek the front and rear elements" << endl;
		cout << "4. Display the circular queue" << endl;
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
					cout << "Queue is empty, no front and rear to display !!" << endl;
				} else{
					cout << "Element at the queue front:" << que[front] << endl;
					cout << "Element at the queue rear:" << que[rear] << endl;
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