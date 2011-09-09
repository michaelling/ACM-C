/* 	
	Filename:	containers.cpp
	Author:		Michael Ling	
	
	Purpose:	ACM 2007 Problem B: containers
	
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int i, j = 0;		// loop counters
	
	string containerOrder;	// order of containers as collected from input
	
	int containers;			// number of containers
	int stacksUsed = 0;
	int placed = 1;			// 0 = placed, 1 = not placed
	
	char container;

	stack<char> stacks[1000];			// an array of 1000 stacks
	
	cin >> containerOrder;					
	
	containers = containerOrder.size(); 		
	
	// for each container
	for (i = 0; i < containers; i++)
	{
		
		placed = 1;		
		
		container = containerOrder[i];		
		
		while (placed == 1)
		{
			cout << "HERE " <<  endl;

			// check if current stack is occupied
			if (stacks[j].size() > 0)
			{	
				cout << "OCCUPIED" << endl;
				// check if container can fit on stack
				if (stacks[j].top() >= container)	
				{
					stacks[j].push(container);
					placed = 0;
				}	
				else
				{
					// move to next stack 
					j++;
				}			
			}
			else
			{
				stacks[j].push(container);
				placed = 0;
			}
		}
		
	}
	
	for (i = 0; i < 1000; i++)
	{
		if (stacks[i].size() > 0)
		{
			stacksUsed++;
		}
	}
	
	cout << "stacks used: " << stacksUsed << endl;
	
	return 0;
}
