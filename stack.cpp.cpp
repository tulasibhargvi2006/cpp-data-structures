#include "Stack.h"
int main(){
	Stack st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.display();
	st.pop();
	st.display();
	cout << st.peek() << endl;
	st.display();
	cout << st.isEmpty() << endl;
}