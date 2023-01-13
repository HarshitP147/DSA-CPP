#include <iostream>
using namespace std;

const int len = 7;
// assuming the length of the stack to be 7 fixed

void push(int arr[],int &top,int ele){
	if(top==len-1){
		cout << "Stack overflow!!" << endl;
	} else{
		top++;
		arr[top] = ele;
	}
}

int pop(int arr[],int &top){
	if(top==-1){
		return -30000;  // assuming that we return a very small number becuase we can't return NULL
	} else{
		return arr[top--];
	}
}

void displayStack(int stack[],int top){
	if(top==-1){
		cout << "Emtpy Stack. Nothing to display!!" << endl;
	} else{
		cout << stack[top] << " <-- Top" << endl;
		for(int i=top-1;i>=0;i--){
			cout << stack[i] << endl;
		}
	}
}

int main(){
	// implementing stacks

	int stack[len];
	int top = -1;

	bool running = true;

	while(running){
		// implementing a menu driven program 
		cout << endl;
		cout << "1. Push element to the stack" << endl;
		cout << "2. Pop from the stack" << endl;
		cout << "3. Peek the stack" << endl;
		cout << "4. Display the stack " << endl;
		cout << "5. Exit the menu" << endl;
		int choice;
		cout << "Enter your choice:" ;
		cin >> choice;
		cout << endl;

		switch(choice){
			case 1:
				cout << "Enter value you want to push:";
				int ele;
				cin >> ele;				
				push(stack,top,ele);

				break;

			case 2:
				int x;
				x = pop(stack,top);
				if(x==-30000){
					cout << "Stack underflow!!" << endl;
				} else{
					cout << "Element popped:" << x << endl;
				}

				break;

			case 3:
				if(stack[top]==-1){
					cout << "Stack is empty." << endl;
				} else{
					cout << "Element at the top of the stack:" << stack[top] << endl;
				}

				break;	

			case 4:
				displayStack(stack,top);

				break;

			case 5:
				running = false;	
				break;
		}
	}
}