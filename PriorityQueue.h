#include <vector>

class PriorityQueue {
	std::vector<int> pq;

public:
	
	PriorityQueue() {}

	void insert(int element) {

		int childIndex = pq.size() - 1;
		pq.push_back(element);

		while(childIndex > 0) {

			int parentIndex = (childIndex - 1) / 2;

			if(pq[childIndex] < pq[parentIndex]) {
				int temp = pq[childIndex];
				pq[childIndex] = pq[parentIndex];
				pq[parentIndex] = temp;
			}

			else {
				break;
			}

			childIndex = parentIndex;
		}
	}

	int removeMin() {

		int ans  = pq[0];
		pq[0] = pq[pq.size()- 1];
		pq.pop_back();

		int parentIndex = 0;
		int leftChildIndex = 2*parentIndex + 1;
		int rightChildIndex = 2*parentIndex + 2;

		while(leftChildIndex < pq.size()) {
			int minIndex = parentIndex;

			if(rightChildIndex > pq.size())
				minIndex = rightChildIndex;

			if(pq[minIndex] > pq[leftChildIndex])
				minIndex = leftChildIndex;

			if(pq[minIndex] > pq[rightChildIndex])
				minIndex = rightChildIndex;

			if(minIndex == parentIndex)
				break;

			int temp = pq[minIndex];
			pq[minIndex] = pq[parentIndex];
			pq[parentIndex] = temp;

			parentIndex = minIndex;
			leftChildIndex = 2 * parentIndex + 1;
			rightChildIndex = 2 * parentIndex + 2;

		}
		return ans;
	}

	int getSize() {
		return pq.size();
	}

	int getMin() {
		//If Priority Queue is empty
		if(isEmpty()) return 0; 

		return pq[0];
	}

	bool isEmpty() {
		return pq.size() == 0;
	}
	
};