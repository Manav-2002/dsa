#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[parentIndex] > heap[index]) {
                swap(heap[parentIndex], heap[index]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return -1; // or some other appropriate error value
        }

        int minValue = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);

        return minValue;
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(5);
    minHeap.insert(10);
    minHeap.insert(3);
    minHeap.insert(8);
    minHeap.insert(1);

    cout << "Extracted Minimum: " << minHeap.extractMin() << endl;
    cout << "Extracted Minimum: " << minHeap.extractMin() << endl;

    return 0;
}
