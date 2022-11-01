#pragma once
#include <iostream>

class Customer
{
	int customerServiceTime;
	int arrivalTime;
	int timeWaiting;
	bool empty;
public:
	Customer();
	int GetArrival();
	int GetService();
	int GetWaitTime();
	void SetEmpty();
	void Arriving();
	void Waiting();
	void BeingServed();
	void Reroll();
};

