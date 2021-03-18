#include "bsq.h"

void	ft_clean(t_rules *rules, int desc, int **mass)
{
	while (rules->height > 0)								//Free string pointers
	{
		free(mass[rules->height - 1]);
		rules->height--;
	}
	free(mass);												//Free pointers pointer
	free(rules);
	close(desc);
}
