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
    cout << "What would you like to do ? \n" <<endl;
    cout << "(1) Initialize an empty link list."<<endl;
    cout << "(2) Exit." << endl;
    cout << "\nEnter Choice : ";
    cin >> ch;
    while (ch<1 || ch >2) {
        cout << "Please enter choice between (1) to (2) : " << endl;
        cin >> ch;
    }
    return ch;
}

// Code to initialize the link list

NODE * init() {
    NODE * head = (NODE*) malloc (sizeof (NODE));
    head -> next = NULL;
    head -> data = 10;
    return head;
}


// Main function

int main() {
    cout << "Single - Link List"<< endl;
    cout << "==================";
    int c;
    NODE * head = NULL;
    while (1) {
        c = choices();
        switch(c) {
            case 1:
                if (head == NULL) {
                    head = init();
                    cout << head->data;
                }
                else {
                    cout << "Link list already exist." << endl;
                }
                break;
            case 2:
                return 0;
        }
    }
}

