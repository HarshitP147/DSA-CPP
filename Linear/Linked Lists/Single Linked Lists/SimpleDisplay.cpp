#include <iostream>
using namespace std;

struct node{
    int val;    // value of the node
    node *next;  // pointer to the next node 
};

int main(){
    // Program to simply enter and display a linked list
    node *list;
    list = nullptr;
    
    int count = 0; // variable to keep track of number of nodes in the list

    node *start;   // one node pointer that points to the start
    // this could've named as head also

    int len;
    cout << "Enter the number of nodes you want:";
    cin >> len;

    node *temp;
    for(int i=1;i<=len;i++){
        temp = new node;
        cout << "Enter the node value:";
        cin >> temp->val;

        if(list==nullptr){
            start = temp;
            list = temp;
        }
        else{
            list->next = temp;
            list = list->next;
        }
        count++;
    }

    cout << endl;

   // now displaying through the linked list
   node *display;
   display = start;

   for(int i=0;i<count;i++){
        cout << "Node value:" << display->val << endl;
        display = display->next;
   } 

    return 0;
}
