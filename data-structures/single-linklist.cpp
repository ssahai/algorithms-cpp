#include <iostream>
#include <cstdlib>

using namespace std;


// Definition of a node of Link List 

typedef struct node {
    int data;
    struct node * next;
}NODE;


// Code for presenting choices for operations to be performed

int choices() {
    int ch = 0;
    cout << "\n\nWhat would you like to do ? \n" <<endl;
    cout << "\t(1) Initialize an empty link list."<<endl;
    cout << "\t(2) Insert a node." << endl;
    cout << "\t(3) Print Linklist." << endl;
    cout << "\t(4) Exit." << endl;
    cout << "\nEnter Choice : ";
    cin >> ch;
    while (ch<1 || ch >4) {
        cout << "Please enter choice between (1) to (4) : " << endl;
        cin >> ch;
    }
    return ch;
}

// Code to initialize the link list

NODE * init() {
    NODE * head = (NODE*) malloc (sizeof (NODE));
    head -> next = NULL;
    head -> data = 0;
    cout << "Link List initialized"<<endl;
    return head;
}

// Code to insert a node in the link list. 

void insert (NODE * head) {
    int ch;
    int d;
    cout << "Enter the data you want to insert ? ";
    cin  >> d;
    cout << "Where do you want to insert the node ?"<<endl;
    cout << "\t(1) At the beginning of the list."<<endl;
    cout << "\t(2) At the end of the list."<<endl;
    cout << "Enter choice : ";
    cin  >> ch;
    NODE * ctr;
    NODE * temp = (NODE*) malloc (sizeof (NODE));
    temp -> data = d;
    switch(ch) {
        case 1:
            temp -> next = head -> next;
            head -> next = temp;
            cout << "\nNode inserted at the beginning of the list" <<endl;
            break;
        case 2:
            ctr = head;
            while (ctr->next != NULL) {
                ctr = ctr -> next;
            }
            temp -> next = NULL;
            ctr  -> next = temp;
            cout << "\nNode inserted at the beginning of the list" <<endl;
            break;
    }
} 

void display(NODE * head) {
    cout << "HEAD --> ";
    NODE * ctr = head -> next;
    while(ctr != NULL) {
        cout << ctr -> data << " --> ";
        ctr  = ctr -> next;
    }
    cout << "END"<<endl;
}
    
// Main function

int main() {
    cout << "Single - Link List"<< endl;
    cout << "==================";
    int c;
    NODE * head = NULL;
    NODE * ctr = head;
    while (1) {
        c = choices();
        switch(c) {
            case 1:
                if (head == NULL) {
                    head = init();
                }
                else {
                    cout << "\nERROR : Link list already exist." << endl;
                }
                break;
            case 2:
                if (head == NULL) {
                    cout << "\nERROR : Linklist not initialized! Initialize linklist to insert node." <<endl;
                }
                else {
                    insert (head);
                }
                break;
            case 3:
                display(head);
                break;
            case 4:
                return 0;
            default:
                cout << "Wrong choice entered ! "<<endl;
        }
    }
}
