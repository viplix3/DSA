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

		if((leftIdx < size) && (arr[leftIdx] < arr[currIdx]))
			minIdx = leftIdx;
		if((rightIdx < size) && (arr[rightIdx] < arr[currIdx]))
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

	void decreaseKey(int idx, int newValue) {
		if(idx >= size) {
			std::cerr << "Out of bounds index, heap size is " << size-1 << ", provided index" << idx << std::endl;
			return;
		}

		arr[idx] = newValue;
		whle(idx != 0 && arr[parent(idx)] > arr[idx]) {
			swap(arr[idx], arr[parent(idx)]);
			idx = parent(idx);
		}
	}

	void delete_key(int idx) {
		if(idx >= size) {
			std::cerr << "Invalid index provided" << std::endl;
			return;
		}

		decreaseKey(idx, INT_MIN);
		extractMin();
	}

	void buildHeap() {
		for(int i = (size-1)/2; i>=0; i--)
			minHeapify(i);
	}
};