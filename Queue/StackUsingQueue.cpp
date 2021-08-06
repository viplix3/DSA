#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Stack
{
private:
	queue<T> Q1, Q2;

public:
	T top() {
		return Q1.front();
	}

	T pop()
	{
		T data = Q1.front();
		Q1.pop();
		return data;
	}

	int size() {
		return Q1.size();
	}

	void push(T data)
	{
		while(Q1.empty() == false) {
			Q2.push(Q1.front());
			Q1.pop();
		}

		Q1.push(data);

		while(Q2.empty() == false) {
			Q1.push(Q2.front());
			Q2.pop();
		}
	}

};

int main() {
	Stack<int> selfStack;

	cout << "Pushing items into stack" << endl;
	selfStack.push(10);
	selfStack.push(19);
	selfStack.push(70);
	selfStack.push(1);

	cout << "Stack top: " << selfStack.top() << endl;

	cout << "Popping items from stack" << endl;
	
	while(selfStack.size())
		cout << selfStack.pop() << "\t";
	cout << endl;


	return 0;
}