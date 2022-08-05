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


void addNodePos(node *start,node *temp,int pos){
    node *trav,*rear;
    rear = start;

    int x = 1;
    while(x<pos-1){
        rear = rear->next;
        x++;
    }
    // rear is one position behind where we want to add the new node
    trav = rear->next; // trav is at the position where we want to add

    temp->prev = rear; // temp now points to rear from behind
    temp->next = trav; // temp next now points to trav 

    trav->prev = temp; // trav also points to the temp from behind
    rear->next = temp; // rear now further points to temp
}   

int main(){
    node *list;
    list = NULL;

    int count=0;
    node *start;

    int len;
    cout << "Enter number of nodes you want to add:";
    cin >> len;

    node *temp;
    for(int i=0;i<len;i++){
        temp = new node;
        cout << "Enter node name:";
        cin >> temp->name ;

        temp->next = NULL;
        if(list==NULL){
            list = temp;
            start = temp;
        } else{
            temp->prev = list;
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
    cout << "Enter the position where you want to add a new node:";
    cin >> pos;

    temp = new node;
    cout << "Enter node name:" ;
    cin >> temp->name;

    if(pos==1){
        // add at the start
        start->prev = temp;
        temp->next = start;
        start = temp;
        count++;
    } else if(pos>count){
        // add at the end
        count++;
        if(list==NULL){
            list = temp;
            start = temp;
        } else{
            list->next = temp;
            temp->prev = list;
            list = list->next;
        }
    } else{
        // add at the specified position
        count++;
        addNodePos(start,temp,pos);
    }
    cout << endl;

    cout << "Linked list with new node:" << endl;
    displayLinkedList(start,count);





    return 0;
}