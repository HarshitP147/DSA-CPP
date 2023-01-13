#include <iostream>
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

int main(){
    // C++ program to reverse a linked list in the memory
    
    int n;
    cout << "Enter the number of nodes in the linked list:";
    cin >> n;

    node *list;
    list = nullptr;

    node *start;

    node *temp;
    for(int i=0;i<n;i++){
        temp = new node;
        cout << "Enter node name:";
        cin >> temp->name;

        if(list==nullptr){
            start = temp;
            list = temp;
        }
        else{
            list->next = temp;
            list = list->next;
        }
    }

    cout << "Original linked list:" << endl;
    node *display;
    display = start;
    while(display!=nullptr){
        cout << "Node name:" << display->name << endl;
        display = display->next;
    }

    // reversing the linked list
    node *rev;
    rev = start;

    start = start->next;
    rev->next = nullptr;

    node *temp;
    while(start!=nullptr){
        temp = start;
        start = start->next;
        temp->next = rev;
        rev = temp;
    }

    cout << endl;
    cout << "Reversed linked list:" << endl;
    display = rev;
    while(display!=nullptr){
        cout << "Node name:" << display->name << endl;
        display = display->next;
    }








    return 0;
}