#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	front = -1;
	rear = -1;
	for (int i = 0; i < 20; i++)
	{
		arr[i] = 0;
	}
}

bool Queue::IsEmpty()
{
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

bool Queue::IsFull()
{
	if (rear == 19)
		return true;
	else
		return false;
}

void Queue::Enqueue(int serviceTime)
{
	if (IsFull())
	{
		std::cout << "Queue is full. " << std::endl;
		return;
	}
	else if (IsEmpty())
	{
		front = 0;
		rear = 0;
		arr[rear] = serviceTime;
	}
	else
		rear = (rear + 1) % 20;
		arr[rear] = serviceTime;
}

int Queue::Dequeue()
{
	int x;
	if (IsEmpty())
	{
		std::cout << "Queue is empty. " << std::endl;
		return 0;
	}
	else if (front == rear)
	{
		x = arr[front];
		arr[front] = 0;
		rear = -1;
		front = -1;
		return x;
	}
	else
	{
		x = arr[front];
		arr[front] = 0;
		front = (front + 1) % 20;
		return x;
	}
}

int Queue::Count()
{
	return (rear - front + 1);
}

int& Queue::operator [](int index)
{
	return arr[index];
}

int& Queue::Front()
{
	return arr[front];
}


