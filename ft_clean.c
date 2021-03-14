#include "bsq.h"

void	ft_clean(t_rules *rules, int desc, int **mass)
{
	while (rules->height > 0)
	{
		free(mass[rules->height - 1]);
		rules->height--;
	}
	free(mass);
	free(rules);
	close(desc);
}
