#include <iostream>
using namespace std;

struct node{
    node *prev;
    string name;
    node *next;
};

void displayLinkedList(node *start,int count){
    node *display;
    display = start;

    for(int i=0;i<count;i++){
        cout << "Node name:" << display->name << endl;
        display = display->next;
    }
    cout << endl;
}



int main(){
    node *list;
    list = nullptr;

    node *start;
    int count = 0;

    int len;
    cout << "Enter the number of nodes you want to add:";
    cin >> len;

    node *temp;
    for(int i=0;i<len;i++){
        temp = new node;
        cout << "Enter node name:" ;
        cin >> temp->name;

        if(list==nullptr){
            list = temp;
            start = temp;
            list->prev = nullptr;
        } else{
            list->next = temp;
            temp->prev = list;
            list = list->next; 
        }
        count++;
    }

    cout << endl;
    cout << "Original double linked list:" << endl;
    displayLinkedList(start,count);

	node *rev;
	rev = start;

	rev = rev->next;

	start->next = nullptr;
	rev->prev = nullptr; 
	// start is now isolated from the linked list

	// now reversing from the main linked list
	for(int i=1;i<count;i++){
		temp = new node;
		temp = rev;
		
		rev = rev->next;

		temp->next = start;
		start->prev = temp;
		// the node is now linked with the start from rear

		start = temp;  // now resetting the start value to the first node
	}

    cout << endl;
    cout << "Reversed linked list:" << endl;
    displayLinkedList(start,count);

    return 0;
}