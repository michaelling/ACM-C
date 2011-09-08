/* 	
	Filename:		biobots.cpp
	Author:			Michael Ling
	
	Description:	ACM 2010 Question Problem C
	
*/

// vim test comment"

#include <cstdio>

#include <vector>

#define STUCK 0
#define REACHABLE 1
#define WALL 2

using namespace std;

void recordStuck(vector< vector<int> >& room, int x, int y);

int main()
{
	
	/**********************************
		ROOM LEGEND
		
		0 = stuck
		1 = reachable square
		2 = wall
		
	***********************************/
	
	
	int rows, columns, walls;
	int wallx1, wally1, wallx2, wally2;
	int i, j;									// loop counters
	int stucks = 0;								// number of stuck squares
	
	scanf("%d %d %d", &rows, &columns, &walls);
	
	// validate room dimensions
	
	if (rows < 1 || rows > 1000000)
	{
		printf("invalid amount of rows\n");
		return 1;
	}
	else if (columns < 1 || columns > 1000000)
	{
		printf("invalid amount of columns\n");
		return 1;
	}
	else if (walls < 0 || walls > 1000)
	{
		printf("invalid amount of walls\n");
		return 1;
	}
	
	// create room
	vector< vector<int> > room (columns, vector<int>(rows));
	
	// gather wall information and place walls
	for (i = 0; i < walls; i++)
	{
		scanf("%d %d %d %d", &wallx1, &wally1, &wallx2, &wally2);
		
		// check wall coordinates
		
		// place walls, iterate for entire length of wall
		for (j = wallx1; j <= wallx2; j++)
		{
			// check if wall collision occurs
			if (room[j][wally1] == WALL)
			{
				printf("wall (%d, %d), (%d, %d) collision\n", wallx1, wally1, wallx2, wally2);
				return 1;
			}
			else
			{
				room[j][wally1] = WALL;
			}			
		}		
	}	
	
	// determine stuck squares (recursively)
	recordStuck(room, columns - 1, rows - 1);
	
	// display contents of room
	for (i = (rows - 1); i > -1; i--)
	{
		for (j = 0; j < columns; j++)
		{
			printf("%d ", room[j][i]); 
		}
		
		printf("\n");
	}

	// count stuck squares
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			if (room[j][i] == STUCK)
				stucks++;			
		}
	}
	
	printf("Number of stuck squares: %d\n", stucks);
	
	return 0;
}

/*
 *	Function that records the number of stuck squares
 *	using recursion
 */
void recordStuck(vector< vector<int> >& room, int x, int y)
{
	room[x][y] = REACHABLE;
	
	// check room boundaries and if we hit a wall in the square below or to the left
	// call recordStuck() recursively
	
	if (x-1 >= 0 && room[x-1][y] != WALL)
	{
		recordStuck(room, x-1, y); 
	}
	
	if (y-1 >= 0 && room[x][y-1] != WALL)
	{
		recordStuck(room, x, y-1);
	}
}
