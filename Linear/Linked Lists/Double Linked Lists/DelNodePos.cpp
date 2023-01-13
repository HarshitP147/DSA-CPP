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
	// program to delete a node in a double linked list in one position
	node *list;
	list = nullptr;
	
	int count=0;
	node *start;

	int len;
	cout << "Enter the number of nodes you to add:";
	cin >> len;

	node *temp;
	for(int i=0;i<len;i++){
		temp = new node;
		cout << "Enter node name:";
		cin >> temp->name ;

		if(list==nullptr){
			list = temp;
			start = temp;
		} else{
			temp -> prev = list;
			list->next = temp;
			list = list->next;
		}
		count++;
	}
	cout << endl;

	cout << "Original linked list:" << endl;
	displayLinkedList(start,count);
	cout << endl;
				
	int pos;
	cout << "Enter the node position to be deleted:";
	cin >> pos;

	if(pos==1){
		// delete the first node
		start = start->next;
		start->prev = nullptr;
		count--;
	} else if(pos>count){
		// delete the last node
		list = list->prev;
		list->next = nullptr;
		count--;
	} else{
		// delete the node at the specified position
		node *p,*n;
		p = start;

		for(int i=1;i<pos-1;i++){
			p = p->next;
		}

		n = p->next;
		n = n->next;

		n->prev = p;
		p->next = n;
		count--;
	}

	cout << endl;
	cout << "Linked list with specified node deleted:" << endl;
	displayLinkedList(start,count);
	cout << endl;

	return 0;
}	