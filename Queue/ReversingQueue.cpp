#include <bits/stdc++.h>
using namespace std;

queue<int> reverseQueueIterative(queue<int> Q)
{
	stack<int> QStack;

	while(Q.empty() == false) {
		QStack.push(Q.front());
		Q.pop();
	}

	while(QStack.empty() == false) {
		Q.push(QStack.top());
		QStack.pop();
	}
	
	return Q;
}

queue<int> reverseQueue(queue<int> Q)
{
	if(Q.size() == 1)
		return Q;

	int data = Q.front();
	Q.pop();
	queue<int> revQ = reverseQueue(Q);
	revQ.push(data);
	return revQ;
}

std::ostream& operator<<(std::ostream& out, std::queue<int> Q)
{
	while(Q.empty() == false) {
		out << Q.front() << " ";
		Q.pop();
	}
	return out;
}

int main() {
	queue<int> testQ;
	testQ.push(4);
	testQ.push(3);
	testQ.push(2);
	testQ.push(1);

	cout << "Input Queue: " << testQ << endl;
	cout << "Reversed Queue Recursive: " << reverseQueue(testQ) << endl;
	cout << "Reversed Queue Iterative: " << reverseQueueIterative(testQ) << endl;

	return 0;
}