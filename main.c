#include "snake.h"

/**
 *
 *
 *
*/
//TODO
//Rework program from prototype stage
//Colours
//Score
//Difficulty

int main()
{
	const int height = 40;
	const int width = 40;
	int screen_map[height][width];
	int i = 0;
	int k = 0;
	int direction = '|';

	//initialise array to blank char, this needs to be a sub function
	while (i < height)
	{
		while (k < width)
		{
			screen_map[i][k] = '-';
			k = k + 1;
			printf("k: %d \t i: %d\n", i, k);
		}
		i = i + 1;
		k = 0;
	}
	i = 0;
	k = 0;
	while (1)
	{
		/*this clears the screen, make this a sub function*/
		printf("\e[1;1H\e[2J");
		
		//make this a subfunction
		i = 0;
		k = 0;
		while (i < height)
		{
			while (k < width)
			{
				putchar(screen_map[i][k]);
				putchar(' ');
				k = k + 1;
			}
			putchar('\n');
			i = i + 1;
			k = 0;
		}
		i = 0;


		screen_map[1][1] = direction;
		screen_map[0][1] = 'd';
		printf("Direction: %d", direction);
		direction = getch();
		fflush(stdin);
		//get user input
		//check if a food was eaten, update length and score
		//calulate position of next movement
		//usleep(1000);/* this is the clock speed of the game, I can also use usleep*/
	}
}
