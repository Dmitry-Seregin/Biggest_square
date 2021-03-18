#include "bsq.h"

void	ft_start(char *buff, t_rules *rules)
{
	if (rules->nbr != 0)
	{
		rules->end_i = rules->end_i - (rules->nbr - 1);
		rules->end_j = rules->end_j - (rules->nbr - 1);
	}
	ft_print_fin(buff, rules);
}

int		ft_min(int **mass, int i, int j)								//Main algorythm
{
	int min;
	min = 2147483647;
	if (min > mass[i][j - 1])
		min = mass[i][j - 1];
	if (min > mass[i - 1][j])
		min = mass[i - 1][j];
	if (min > mass[i - 1][j - 1])
		min = mass[i - 1][j - 1];
	return (min + 1);
}

void	ft_insert(int **mass, int i, char *buff, t_rules *rules)
{
	int j;

	while (i != rules->height)
	{
		j = 0;
		while (j != rules->width - 1)
		{
			if (mass[i][j] != 0)
			{
				if (i == 0 || j == 0)									//Set 0 on the x[0] and y[0]
					mass[i][j] = 1;
				else
					mass[i][j] = ft_min(mass, i, j);					//Check algorythm
				if (rules->nbr < mass[i][j])
				{
					rules->nbr = mass[i][j];
					rules->end_i = i;
					rules->end_j = j;
				}
			}
			j++;
		}
		i++;
	}
	ft_start(buff, rules);
}
