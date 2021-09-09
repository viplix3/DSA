#include<bits/stdc++.h>
using namespace std;

class MinHeap {
private:
	int arr[];
	int size, capacity;

public:
	MinHeap(int c)
		: size(0), capacity(0)
	{
		arr = new int[c];
	}

	int left(int idx) {
		return (2 * idx + 1);
	}

	int right(int idx) {
		return (2 * idx + 2);
	}

	int parent(int idx) {
		return (idx - 1) / 2;
	}

	void insert(int data) {
		if(size == capacity) {
			std::cerr << "Heap is at its capacity, cannot insert more items" << std::endl;
			return;
		}

		size += 1;
		int currIdx = size-1;
		arr[currIdx] = data;
		while(currIdx != 0 && arr[parent(currIdx)] > arr[currIdx]) {
			swap(arr[parent(currIdx)], arr[currIdx]);
			currIdx = parent(currIdx);
		}
	}

	void minHeapify(int currIdx) {
		int leftIdx = left(currIdx);
		int rightIdx = right(currIdx);

		int minIdx = currIdx;

		if((0 <= leftIdx < size) && (arr[leftIdx] < arr[currIdx]))
			minIdx = leftIdx;
		if((0 <= rightIdx < size) && (arr[rightIdx] < arr[currIdx]))
			minIdx = rightIdx;
		
		if(minIdx != currIdx) {
			swap(arr[currIdx], arr[minIdx]);
			minHeapify(minIdx);
		}
	}

	int extractMin() {
		if(size == 0)
			return INT_MAX;
		
		if(size == 1) {
			size -= 1;
			return arr[0];
		}

		int minElem = arr[0];
		swap(arr[0], arr[size-1]);
		size -= 1;
		minHeapify(0);

		return minElem;
	}
};