#include <iostream>
#include <iomanip>
#include "Queue.h"

int main()
{
	Queue queue;
	Customer nextCustomer;
		
	int customersServed = 0;
	int maxCustomers = 0;
	int longestWait = 0;

	for (int i = 0; i <= 119; i++)
	{
		std::cout << i << " minutes elapsed. ";
		if (nextCustomer.GetArrival() != 0)
		{
			nextCustomer.Arriving();
		}

		if (nextCustomer.GetArrival() == 0 && !queue.IsFull())
		{
			queue.Enqueue(nextCustomer);
			std::cout << std::left << "New customer in queue. ";
			nextCustomer.Reroll();
			
			if (queue.Count() > maxCustomers)
				maxCustomers = queue.Count();
		}
		
		if (!queue.IsEmpty())
		{
			if (queue.FrontCust().GetService() != 0)
			{
				queue.FrontCust().BeingServed();
			}
			if (queue.FrontCust().GetService() == 0)
			{
				queue.Dequeue();
				std::cout << std::left << "Customer served. ";
				customersServed++;
			}
			for (int j = queue.Front() + 1; j <= queue.Rear(); j++)
			{
				queue[j].Waiting();
				if (queue[j].GetWaitTime() > longestWait)
					longestWait = queue[j].GetWaitTime();
			}
		}	
		std::cout << std::endl;
	}
	std::cout << "Simulation complete." << std::endl << "Customers served : " << customersServed << std::endl << "Longest wait time by one customer : " << longestWait << " minutes" << std::endl;
	std::cout << "Maximum number of customers in queue : " << maxCustomers;
}