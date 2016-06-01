#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node {
    int data;
    struct node * next;
}NODE;

NODE * init() {
    NODE * head = (NODE*) malloc (sizeof (NODE));
    head -> next = NULL;
    head -> data = 10;
    return head;
}

int main() {
    cout << "Single - Link List"<< endl;
    cout << "==================";
    NODE * head;
    head = init();
    cout << head->data;
}

