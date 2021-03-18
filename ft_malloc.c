#include "bsq.h"

int	**ft_malloc(t_rules *rules)
{
	int **mass;
	int p;

	p = rules->height;
	mass = malloc((rules->height) * sizeof(int*));				//Allocating memory for *int[][]
	if (mass == NULL)
		return (NULL);
	while (p > 0)
	{
		mass[p - 1] = malloc((rules->width) * sizeof(int));
		if (mass[p - 1] == NULL)
			return (NULL);
		p--;
	}
	return (mass);
}
