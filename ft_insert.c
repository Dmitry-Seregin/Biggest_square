#include "bsq.h"

void	ft_start(char *buff, t_rules *rules)
{
	rules->end_i = rules->end_i - (rules->nbr - 1);
	rules->end_j = rules->end_j - (rules->nbr - 1);
	ft_print_fin(buff, rules);
}

int		ft_kost(int **mass, int i, int j)
{
	if (mass[i][j - 1] <= mass[i - 1][j])
	{
		if (mass[i][j - 1] <= mass[i - 1][j - 1])
			return (mass[i][j] = ((mass[i][j - 1]) + 1));
		else
			return (mass[i][j] = ((mass[i - 1][j - 1]) + 1));
	}
	else if (mass[i - 1][j] <= mass[i][j - 1])
	{
		if (mass[i - 1][j] <= mass[i - 1][j - 1])
			return (mass[i][j] = ((mass[i - 1][j]) + 1));
		else
			return (mass[i][j] = ((mass[i - 1][j - 1]) + 1));
	}
	return (0);
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
				if (i == 0 || j == 0)
					mass[i][j] = 1;
				else
					ft_kost(mass, i, j);
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
