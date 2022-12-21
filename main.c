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

int check_user_input()
{
	int check;
	putchar('3');
	system("/bin/stty raw");
	check = getchar();
	system("/bin/stty cooked");

	if (check != EOF)
	{
		return (1);
	}
	return (0);
}

int main()
{
	const int height = 40;
	const int width = 40;
	int speed = 1000;
	int count = 0;
	int screen_map[height][width];
	int i = 0;
	int k = 0;
	int direction = ' ';

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
		printf("COUNT: %d\n", count);
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

		putchar('1');

		if (count > speed)
		{
			count = 0;
			putchar('2');
			if (check_user_input())
			{
				putchar('4');
				system("/bin/stty raw");
				direction = getchar();
				//fflush(stdin);
				system("/bin/stty cooked");
			}
			putchar('5');
			if (direction == 27)
			{
				return(0);
			}
			printf("Direction: %d", direction);
		}

		screen_map[1][1] = direction;
		screen_map[0][1] = 'd';
		count = count + 1;

		//check if a food was eaten, update length and score
		//calulate position of next movement
	}
}
