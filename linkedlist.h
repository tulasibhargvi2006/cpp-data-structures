#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
using namespace std;

struct LinkedListNode {
    int data;
    LinkedListNode* next;
    LinkedListNode(int val) : data(val), next(nullptr) {}
};

struct LinkedList {
    LinkedListNode* head = nullptr;
    LinkedListNode* tail = nullptr;

    void insertbeg(int val) {
        LinkedListNode* newNode = new LinkedListNode(val);
        if (!head) head = tail = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertend(int val) {
        LinkedListNode* newNode = new LinkedListNode(val);
        if (!head) head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertposition(int val, int pos) {
        LinkedListNode* newNode = new LinkedListNode(val);
        if (pos <= 1 || !head) {
            insertbeg(val);
            return;
        }

        LinkedListNode* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != nullptr; ++i) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == nullptr) tail = newNode;
    }

    void deletebeg() {
        if (!head) {
            cout << "Linked List is Empty\n";
            return;
        }
        LinkedListNode* temp = head;
        head = head->next;
        delete temp;
        if (!head) tail = nullptr;
    }

    void deleteend() {
        if (!head) {
            cout << "Linked List is Empty\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = tail = nullptr;
            return;
        }
        LinkedListNode* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }

    void deleteposition(int pos) {
        if (!head) {
            cout << "Linked List is Empty\n";
            return;
        }
        if (pos <= 1) {
            deletebeg();
            return;
        }

        LinkedListNode* prev = head;
        LinkedListNode* curr = head->next;
        for (int i = 2; i < pos && curr != nullptr; ++i) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) {
            cout << "Position out of bounds\n";
            return;
        }

        prev->next = curr->next;
        if (curr == tail) tail = prev;
        delete curr;
    }

    void display() {
        LinkedListNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

#endif 
