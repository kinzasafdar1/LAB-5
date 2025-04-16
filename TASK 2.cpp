#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
private:
	int front, rear, size, capacity;
	string* arr;

public:
	CircularQueue(int cap) {
		capacity = cap;
		arr = new string[capacity];
		front = -1;
		rear = -1;
		size = 0;
	}

	void enqueue(string name) {
		if (isFull()) {
			cout << "Queue is full.\n";
			return;
		}
		if (isEmpty()) {
			front = rear = 0;
		}
		else {
			rear = (rear + 1) % capacity;
		}
		arr[rear] = name;
		size++;
	}

	void dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty.\n";
			return;
		}
		cout << "Removed customer: " << arr[front] << endl;
		if (front == rear) {
			front = rear = -1; // queue became empty
		}
		else {
			front = (front + 1) % capacity;
		}
		size--;
	}

	bool isFull() {
		return size == capacity;
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	string getFront() {
		if (isEmpty()) return "Queue is empty.";
		return arr[front];
	}

	string getRear() {
		if (isEmpty()) return "Queue is empty.";
		return arr[rear];
	}

	~CircularQueue() {
		delete[] arr;
	}
};

int main() {
	CircularQueue queue(10);
	int choice;
	string name;

	do {
		cout << "\n--- Coffee Shop Menu ---\n";
		cout << "1. Add a customer to the queue\n";
		cout << "2. Remove the first customer\n";
		cout << "3. Display number of customers\n";
		cout << "4. View first customer\n";
		cout << "5. View last customer\n";
		cout << "6. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter customer name: ";
			cin >> name;
			queue.enqueue(name);
			break;
		case 2:
			queue.dequeue();
			break;
		case 3:
			cout << "Number of customers: " << queue.getSize() << endl;
			break;
		case 4:
			cout << "First customer: " << queue.getFront() << endl;
			break;
		case 5:
			cout << "Last customer: " << queue.getRear() << endl;
			break;
		}

	} while (choice != 6);
	system("pause");
	return 0;
}
