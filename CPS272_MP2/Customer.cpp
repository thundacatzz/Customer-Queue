#include "Customer.h"

Customer::Customer()
{
	time_t seed;
	srand(time(&seed));
	arrivalTime = (rand() % 4) + 1;
	customerServiceTime = (rand() % 4) + 1;
	timeWaiting = 0;
	empty = false;
}

int Customer::GetArrival()
{
	return arrivalTime;
}

int Customer::GetService()
{
	return customerServiceTime;
}

int Customer::GetWaitTime()
{
	return timeWaiting;
}

void Customer::SetEmpty()
{
	empty = true;
}

void Customer::Arriving()
{
	arrivalTime--;
}

void Customer::Waiting()
{
	timeWaiting++;
}

void Customer::BeingServed()
{
	customerServiceTime--;
}

void Customer::Reroll()
{
	arrivalTime = (rand() % 4) + 1;
	customerServiceTime = (rand() % 4) + 1;
	timeWaiting = 0;
	empty = false;
}