#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *head = NULL;
int N;

node *create_node(int data) {
    node *new_node = new node;
    new_node -> data = data;
    new_node -> next = NULL;
    return new_node;
}

void push(node *new_node) {
    if (head == NULL) {
        head = new_node;
    } else {
        new_node -> next = head;
        head = new_node;
    }
}

bool isEmpty() {
    return(head == NULL);
}

int pop() {
    if(isEmpty()) {
        cout << "stack underflow\n";
        return -1;
    }
    node *temp = head;
    head = head -> next;
    int x = temp -> data;
    free(temp);
    return x;
}

int peek() {
    if(isEmpty()) {
        cout << "stack underflow";
        return -1;
    }  
    else {
        return head -> data;
    }
}


bool isFull() {
    int len = 0;
    node *temp = head;
    while(temp) {
        ++len;
        temp = temp -> next;
    }
    return (len == N);
}

void display() {
    node *temp = head;
    while (temp) {
        cout << temp -> data;
        temp = temp->next; 
    }
}

int main() {
    cin >> N; 
    while(N--) {
        int data;
        cin >> data;
        node *new_node = create_node(data);
        push(new_node);
    }
    display();
    cout << "top element = " << peek();
    cout << "popped ele = " << pop();
    cout << "peek element = " << peek();
    display();
    return 0;
}
