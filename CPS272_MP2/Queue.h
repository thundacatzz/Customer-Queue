#pragma once
#include "Customer.h"

class Queue
{
	int front;
	int rear;
	Customer arr[20];
	int* ptr;
public:
	Queue();
	bool IsEmpty();
	bool IsFull();
	void Enqueue(Customer);
	void Dequeue();
	int Count();
	Customer& operator [](int);
	Customer& FrontCust();
	int Front();
	int Rear();
};

