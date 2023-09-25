#include <iostream>
using namespace std;

struct node{
    string name;
    node *next;
};

node *addNewNode(){
	node *temp;
	temp = new node;
	cout << endl;
	cout << "Enter the name:";
	cin >> temp->name;

	return temp;
}

void addNodePos(node *start,int &count,int pos){
	node *traversal;
	traversal = start;

	node *countinue;
	countinue = start;

	// traversal arrives at one point before to addition
	for(int i=1;i<pos;i++){
		traversal = traversal->next;
	}

	// continue arrives at the point where the addtion takes place
	for(int i=1;i<=pos;i++){
		countinue = countinue->next;
	}

	node *btwNode;
	btwNode = addNewNode();
	count++;

	btwNode->next = countinue;  // btwNode points to the further list

	traversal->next = btwNode; // the previous list points to the present node added
}


void displayLinkedList(node *start,int count){
    node *display = start;

    int x = count;
    while(x--){
        cout << "Node name:" << display->name << endl;
        display = display->next;
    }
    cout << endl;
}


int main(){
    // program to add a new node into a specific position of the linked list
    node *list;
    list = nullptr;

    node *start;
    int count = 0;

    int n;
    cout << "Enter the number of nodes you want to add:";
    cin >> n;

    node *temp;
    for(int i=0;i<n;i++){
        temp = new node;
        cout << "Enter node name:";
        cin >> temp->name;

        if(list==nullptr){
            list = temp;
            start = temp;
        }
        else{
            list->next = temp;
            list = list->next;
        }
        count++;
    }
    // now that we have the entire list let's ask the user where we want to add the new node
    cout << endl;
    int pos;
    cout << "Enter where you want to add the new node:";
    cin >> pos;

    if(pos==1){
        // add the new node to the start of the linked list 
        node *firstNode;
        firstNode = addNewNode();

        firstNode->next = start;
        start = firstNode;
        count++;
    }
    if(pos>count){
        // if the position entered is more than the count value then add it to the last of the linked list
        node *newNode;
        newNode = addNewNode();
        count++;

        list->next = newNode;
        list = list->next;
    }
    if(pos<count && pos>1){
        // if we want to add the node somewhere in btw the linked list
        pos--;
        addNodePos(start,count,pos);
    }

    cout << "\nNew Linked list:" << endl;
    displayLinkedList(start,count);

    return 0;
}
