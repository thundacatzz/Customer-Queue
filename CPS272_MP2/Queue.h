#pragma once

class Queue
{
	int front;
	int rear;
	int arr[20];
	int* ptr;
public:
	Queue();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(int);
	int Dequeue();
	int Count();
	int& operator [](int);
	int& Front();
};

