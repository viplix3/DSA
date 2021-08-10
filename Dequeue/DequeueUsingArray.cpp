#include <bits/stdc++.h>
using namespace std;

template<typename T, int cap>
class DeQueue
{
private:
	int front, rear, size;
	T arr[cap];

public:
	DeQueue()
		:front(0), rear(0), size(0)
		{}

	bool isFull() {
		if(size == cap)
			return true;
		return false;
	}

	bool isEmpty() {
		if(size == 0)
			return true;
		return false;
	}

	void insertFront(T data) {
		if(isFull()) {
			std::cerr << "Insertion failed! DeQueue reached its capacity" << std::endl;
			return;
		}

		front = (front - 1 + cap) % cap;
		arr[front] = data;

		if(isEmpty())
			rear = front;

		size += 1;
	}

	void insertRear(T data) {
		if(isFull()) {
			std::cerr << "Insertion failed! DeQueue reached its capacity" << std::endl;
			return;
		}

		rear = (rear + 1) % cap;
		arr[rear] = data;

		if(isEmpty())
			front = rear;

		size += 1;
	}

	T deleteFront() {
		if(isEmpty()) {
			std::cerr << "Cannot delete from an empty DeQueue" << std::endl;
			return INT_MIN;
		}

		T deleted_data = arr[front];
		front = (front + 1) % cap;
		size -= 1;
		return deleted_data;
	}

	T deleteRear() {
		if(isEmpty()) {
			std::cerr << "Cannot delete from an empty DeQueue" << std::endl;
			return INT_MIN;
		}

		T deleted_data = arr[rear];
		rear = (rear - 1 + cap) % cap;
		size -= 1;
		return deleted_data;
	}

	T getFront() {
		if(isEmpty()) {
			std::cerr << "Empty Dequeue" << std::endl;
			return INT_MIN;
		}

		return arr[front];
	}

	T getRear() {
		if(isEmpty()) {
			std::cerr << "Empty DeQueue" << std::endl;
			return INT_MIN;
		}

		return arr[rear];
	}

	int getSize() {
		return size;
	}

};

int main() {
	DeQueue<int, 5> DQ;
	int data;

	cout << "Trying deleteFront() on empty DeQueue" << endl;
	DQ.deleteFront();

	cout << "\nTrying deleteRear() on empty DeQueue" << endl;
	DQ.deleteRear();
	cout << endl;

	DQ.insertFront(10);
	cout << "Front: " << DQ.getFront();
	cout << "\tRear: " << DQ.getRear();
	cout << "\n" << endl;

	DQ.insertRear(20);
	cout << "Front: " << DQ.getFront();
	cout << "\tRear: " << DQ.getRear();
	cout << "\n" << endl;

	DQ.insertFront(30);
	cout << "Front: " << DQ.getFront();
	cout << "\tRear: " << DQ.getRear();
	cout << "\n" << endl;

	DQ.insertRear(50);
	cout << "Front: " << DQ.getFront();
	cout << "\tRear: " << DQ.getRear();
	cout << "\n" << endl;

	data = DQ.deleteFront();
	cout << "Deleted data: " << data << endl;
	cout << "Front: " << DQ.getFront();
	cout << "\tRear: " << DQ.getRear();
	cout << "\n" << endl;

	data = DQ.deleteRear();
	cout << "Deleted data: " << data << endl;
	cout << "Front: " << DQ.getFront();
	cout << "\tRear: " << DQ.getRear();
	cout << "\n" << endl;

	cout << "DeQueue size: " << DQ.getSize() << endl;

	return 0;
}