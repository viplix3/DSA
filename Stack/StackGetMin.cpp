#include <bits/stdc++.h>

template<typename T, int S>
class Stack
{
private:
	int m_top_ptr = -1;
	T m_stack_arr[S];
	T m_curr_min = INT_MAX;

public:
	bool isFull() {
		if(m_top_ptr >= S-1)
			return true;
		return false;
	}

	bool isEmpty() {
		if(m_top_ptr <= -1)
			return true;
		return false;
	}

	int top() {
		if(isEmpty())
			return INT_MIN;

		int data = m_stack_arr[m_top_ptr];

		if(data <= m_curr_min)
			data = m_curr_min;

		return data;
	}

	void push(T data) {
		if(isFull()) {
			std::cerr << "\nCannot push into the stack, stack aleady full" << std::endl;
			return;
		}

		if(isEmpty()) {
			m_curr_min = data;
		}
		else if(data <= m_curr_min) {
			int data_modified = 2 * data - m_curr_min;
			m_curr_min = data;
			data = data_modified;
		}

		m_top_ptr += 1;
		m_stack_arr[m_top_ptr] = data;
	}

	int pop() {
		if(isEmpty()) {
			std::cerr << "\nCannot pop from the stack, stack already empty" << std::endl;
			return INT_MIN;
		}
		
		int data = top();
		
		if(data <= m_curr_min) {
			data = m_curr_min;
			m_curr_min = 2 * m_curr_min - data;
		}
		m_top_ptr -= 1;
		
		return data;
	}

	int getMin() {
		if(isEmpty()) {
			std::cerr << "\nConnot get minimum element, stack is empty" << std::endl;
			return INT_MAX;
		}

		return m_curr_min;
	}

};


int main() {
	Stack<int, 6> stackWithMin;
	int data, num_items;

	std::cout << "\nTrying pop on empty stack" << std::endl;
	data = stackWithMin.pop();
	std::cout << data << std::endl;

	std::cout << "\n\nEnter number of items to be pushed into the stack: ";
	std::cin >> num_items;

	while(num_items--) {
		std::cout << "Enter item to be pushed into the stack: ";
		std::cin >> data;

		std::cout << "Pushing " << data << " into the stack" << std::endl;
		stackWithMin.push(data);

		std::cout << "Current stack" << std::endl;
	
		Stack<int, 6> stackWithMinCopy = stackWithMin;

		while(stackWithMinCopy.isEmpty() == false) {
			data = stackWithMinCopy.top();
			std::cout << data << " ";
			data = stackWithMinCopy.pop();
		}

		std::cout << "\nCurrent minimum in the stack: " << stackWithMin.getMin() << std::endl;

		std::cout << "\n\n";
	}
	return 0;
}