#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
using namespace std;

struct QueueNode{
	int data;
	QueueNode *next;
	QueueNode(int val) : data(val), next(nullptr) {}
};
struct Queue{
	QueueNode* rear = nullptr;
	QueueNode* front = nullptr;
	void enqueue(int val){
		QueueNode* newNode = new QueueNode(val);
        if(front == nullptr){
        	front = rear = newNode;
		}
		else{
			rear->next = newNode;
			rear = newNode;
		}
	}
	void dequeue(){
		if(front == nullptr){
			cout << "Queue is Empty" << endl;
			return;
		}
		else{
			QueueNode* temp = front;
			front = front->next;
			if (front == nullptr) {
            rear = nullptr;
        }
			delete temp;	
		}
	}
	bool isEmpty(){
		return front == nullptr;
	}
	
	int peek(){
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return -1; 
    }
    return front->data;
    }
    
	void display(){
		if(front == nullptr){
			cout << "Queue is Empty" << endl;
		}
		else{
			QueueNode *temp=front;
			while (temp != nullptr){
			cout << temp->data << " ";
			temp = temp->next;
			}
			cout << endl;
		}
	}
};
#endif
