/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroux <aroux@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:59:35 by aroux             #+#    #+#             */
/*   Updated: 2025/06/25 14:31:37 by aroux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main (int argc, char ** argv)	{
	if (argc != 4)	{
		putchar('e');
		return 1;
	}
//parse:
	int width = atoi(argv[1]);
	int height = atoi(argv[2]);
	int	iterations = atoi(argv[3]);
	int	arr[2][width + 2][height + 2];

//set 2 grids with all cells initialized to 0:
	for (int i = 0; i < 2; i++)	{
		for (int h = 0; h < height + 2; h++)	{
			for (int w = 0; w < width + 2; w++)	{
				arr[i][w][h] = 0;
			}
		}

	}

//read input and set alive cells in arr[0] to 1
	int	x = 1;
	int y = 1;
	int	pen = 0;
	char cmd;
	while (read(0, &cmd, 1))
	{
		if (cmd == 'w' && y > 1)
			y--;
		if (cmd == 's' && y < height)
			y++;
		if (cmd == 'a' && x > 1)
			x--;
		if (cmd == 'd' && x < width)
			x++;
		if (cmd == 'x')
			pen = !pen;
		if (pen)
			arr[0][x][y] = 1;
	}

	// run stimulation iterations times for each cell within borders
	for (int iter = 0; iter < iterations; iter++)	{
		for (int h = 1; h < height + 1; h++)	{
			for (int w = 1; w < width + 1; w++)	{
				// count alive neighbours
				int nb = 0;
				for (int y = -1; y <= 1; y++)	{
					for (int x = -1; x <= 1; x++)	{
						if (!(x == 0 && y == 0))
							nb += arr[iter % 2][w + x][h + y];
					}
				}
				// apply game rules
				if (arr[iter % 2][w][h] == 1)	{
					if (nb == 2 || nb == 3)
						arr[(iter + 1) % 2][w][h] = 1;
					else
						arr[(iter + 1) % 2][w][h] = 0;
				}
				else	{
					if (nb == 3)
						arr[(iter + 1) % 2][w][h] = 1;
					else
						arr[(iter + 1) % 2][w][h] = 0;
				}
			}
		}
	}

	// print arr[iterations % 2] without borders
	for (int h = 1; h < height + 1; h++)	{
		for (int w = 1; w < width + 1; w++)	{
			if (arr[iterations % 2][w][h] == 1)
				putchar('O'); // careful, this is a capital o, not a zero
			else
				putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}
