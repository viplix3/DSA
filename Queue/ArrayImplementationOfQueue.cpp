#include<bits/stdc++.h>
using namespace std;

template<typename T, size_t capacity>
class Queue
{
private:
	int front, rear, size;
	T arr[capacity];

public:
	Queue()
		:front(0), rear(capacity-1), size(0)
	{}

	bool isFull() {
		if(size == capacity) {
			std::cout << "Queue is full" << std::endl;
			return true;
		}
		return false;
	}

	bool isEmpty() {
		if(size == 0) {
			std::cout << "Queue is empty" << std::endl;
			return true;
		}
		return false;
	}

	void enqueue(T data) {
		if(isFull())
			return;
		
		rear = (rear+1) % capacity;
		arr[rear] = data;
		size += 1;
	}

	T dequeue() {
		if(isEmpty())
			return INT_MIN;
		
		T data_dequeued = arr[front];
		front = (front+1) % capacity;
		size -= 1;
		return data_dequeued;
	}

	T getFront() {
		return arr[front];
	}

	T getRear() {
		return arr[rear];
	}
};

int main() {
	Queue<int, 5> Q;
	int data;
	
	cout << "Trying dequeue on empty queue" << endl;
	data = Q.dequeue();

	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.enqueue(40);
	Q.enqueue(50);
	Q.enqueue(60);

	while(Q.isEmpty() == false) {
		cout << "Dequeued " << Q.dequeue() << " from queue" << endl;
	}

	return 0;
}