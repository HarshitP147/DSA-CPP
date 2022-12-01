#include <iostream>
using namespace std;

struct node{
    node *prev;
    int val;
    node *next;
};

int main(){
    node *list;
    list = nullptr;

    node *start;
    int count = 0;

    int len;
    cout << "Enter the number of nodes you want to enter:";
    cin >> len;

    node *temp;
    for(int i=0;i<len;i++){
        temp = new node;
        cout << "Enter node value:" ;
        cin >> temp->val;

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
    cout << "Double linked list is as follows:" << endl;
    node *display;
    display = start;
    for(int i=0;i<count;i++){
        cout << "Node value:" << display->val << endl;
        display =  display->next;
    }
    cout << endl;

    return 0;
}