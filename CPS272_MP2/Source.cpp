#include <iostream>
#include <iomanip>
#include "Queue.h"

int main()
{
	time_t seed;
	srand(time(&seed));

	Queue queue;
		
	int arrivalTime = (rand() % 4) + 1;
	int customerServiceTime = (rand() % 4) + 1;
	int customersServed = 0;
	int maxCustomers = 0;
	for (int i = 0; i <= 119; i++)
	{
		std::cout << i << " minutes elapsed. ";
		if (arrivalTime != 0)
		{
			arrivalTime -= 1;
		}

		if (arrivalTime == 0 && !queue.IsFull())
		{
			queue.Enqueue(customerServiceTime);
			std::cout << std::left << "New customer in queue. ";
			
			if (queue.Count() > maxCustomers)
				maxCustomers = queue.Count();

			arrivalTime = (rand() % 4) + 1;
			customerServiceTime = (rand() % 4) + 1;
		}
		
		if (!queue.IsEmpty())
		{
			if (queue.Front() != 0)
			{
				queue.Front() -= 1;
			}
			if (queue.Front() == 0)
			{
				queue.Dequeue();
				std::cout << std::left << "Customer served. ";
				customersServed++;
			}
		}	
		std::cout << std::endl;
	}
	std::cout << "Simulation complete." << std::endl << "Customers served : " << customersServed << std::endl << "Longest wait time by one customer : " << std::endl << "Maximum number of customers in queue : " << maxCustomers;
}