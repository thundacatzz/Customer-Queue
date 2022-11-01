#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	front = -1;
	rear = -1;
	for (int i = 0; i < 20; i++)
	{
		arr[i].SetEmpty();
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

void Queue::Enqueue(Customer next)
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
		arr[rear] = next;
	}
	else
		rear = (rear + 1) % 20;
		arr[rear] = next;
}

void Queue::Dequeue()
{
	if (IsEmpty())
	{
		std::cout << "Queue is empty. " << std::endl;
	}
	else if (front == rear)
	{
		FrontCust().SetEmpty();
		rear = -1;
		front = -1;
	}
	else
	{
		FrontCust().SetEmpty();
		front = (front + 1) % 20;
	}
}

int Queue::Count()
{
	return (rear - front + 1);
}

Customer& Queue::operator [](int index)
{
	return arr[index];
}

Customer& Queue::FrontCust()
{
	return arr[front];
}

int Queue::Front()
{
	return front;
}

int Queue::Rear()
{
	return rear;
}

