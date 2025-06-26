#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
    node * next;
    int data;
};


void traversal(node * head){
    node * temp = head;

    while( temp != NULL ){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
}

node * addtwo(node * head1, node * head2){
    node * temp1 = head1;
    node * temp2 = head2;

    node * dummy = new node;
    dummy -> next = NULL;
    dummy -> data = 0;
    node * temp3 = dummy;

    int carry = 0;

    while(temp1 != NULL || temp2 != NULL || carry > 0){
        int sum = carry; // initiation of sum

        if( temp1 != NULL ){
            sum += temp1 -> data;
            temp1 = temp1 -> next;
        }

        if( temp2 != NULL ){
            sum += temp2 -> data;
            temp2 = temp2 -> next;
        }

        carry = sum / 10; // we will get our carry over
        sum = sum % 10; // the remainder that will be added to our answer

        temp3 -> next = new node;
        temp3 -> next -> data = sum;
        temp3 -> next -> next = NULL;
        temp3 = temp3 -> next;
    }
    return dummy -> next;
}

int main(){
     // Creating the first linked list: 6 -> 4 -> 2
    node* head1 = new node;
    node* first = new node;
    node* second = new node;

    head1->data = 6;
    head1->next = first;

    first->data = 4;
    first->next = second;

    second->data = 2;
    second->next = NULL;

    // Creating the second linked list: 7 -> 8 -> 3
    node* head2 = new node;
    node* eighth = new node;
    node* ninth = new node;

    head2->data = 7;
    head2->next = eighth;

    eighth->data = 8;
    eighth->next = ninth;

    ninth->data = 3;
    ninth->next = NULL;

    // Display the input lists
    cout << "First List: ";
    traversal(head1);
    cout<<endl;
    cout << "Second List: ";
    traversal(head2);
    cout<<endl;

    // Add the two linked lists
    node* result = addtwo(head1, head2);

    // Display the result list
    cout << "Result List: ";
    traversal(result);

    return 0;
}