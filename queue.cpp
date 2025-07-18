#include "Queue.h"

int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.display();
	q.dequeue();
	q.display();
	cout << q.peek() << endl;
	cout << q.isEmpty();
}