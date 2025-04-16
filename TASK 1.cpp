#include <iostream>
#include <string>
using namespace std;

class Student 
{
public:
	string name;
	int score;
	int timeTaken;

	Student() {
		name = "";
		score = 0;
		timeTaken = 0;
	}

	Student(string n, int s, int t)
	{
		name = n;
		score = s;
		timeTaken = t;
	}
};

class StudentQueue
{
private:
	Student* arr;
	int front, rear, size, capacity;

public:
	StudentQueue(int cap)
	{
		capacity = cap;
		arr = new Student[capacity];
		front = rear = size = 0;
	}

	void enqueue(Student s) 
	{
		if (isFull()) {
			cout << "Queue is full!\n";
			return;
		}
		arr[rear++] = s;
		size++;
	}

	Student dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty!\n";
			return Student();
		}
		Student temp = arr[front++];
		size--;
		return temp;
	}

	bool isFull() {
		return rear == capacity;
	}

	bool isEmpty() {
		return front == rear;
	}

	int getSize() {
		return size;
	}

	void display() {
		for (int i = front; i < rear; i++) {
			cout << "Name: " << arr[i].name
				<< ", Score: " << arr[i].score
				<< ", Time: " << arr[i].timeTaken << endl;
		}
	}

	~StudentQueue() {
		delete[] arr;
	}
};

int generateScore(int index) {
	return (index * 7 + 13) % 100;
}

int generateTime(int index) {
	return (index * 4 + 10) % 30 + 1;
}

int main() {
	StudentQueue waiting(100);
	StudentQueue completed(100);
	int choice, counter = 1;
	string name;

	do {
		cout << "\n--- Quiz Competition Menu ---\n";
		cout << "1. Add student to waiting queue\n";
		cout << "2. Start quiz (simulate score/time)\n";
		cout << "3. Display completed students\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter student name: ";
			cin >> name;
			waiting.enqueue(Student(name, 0, 0));
			break;

		case 2:
			if (waiting.isEmpty()) {
				cout << "No students in waiting queue.\n";
			}
			else {
				while (!waiting.isEmpty()) {
					Student s = waiting.dequeue();
					s.score = generateScore(counter);
					s.timeTaken = generateTime(counter);
					completed.enqueue(s);
					counter++;
				}
				cout << "Quiz ended. All students evaluated.\n";
			}
			break;

		case 3:
			completed.display();
			break;
		}

	} while (choice != 4);
	system("pause");
	return 0;
}
