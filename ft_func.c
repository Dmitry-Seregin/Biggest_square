#include "bsq.h"

void	ft_func(int desc, char *argv)
{
	t_rules *rules;
	char	*buff;
	int		**mass;
	int		i;

	i = 0;
	rules = (t_rules *)malloc(sizeof(t_rules));
	if ((desc = ft_check(desc, argv, rules)) == -1)
	{
		MAPERR;
		return ;
	}
	rules->end_i = 0;
	rules->end_j = 0;
	rules->nbr = 0;
	rules->i = 0;
	rules->j = 0;
	mass = ft_malloc(rules);
	if ((buff = ft_insert_o(desc, rules, mass)) == NULL)
	{
		MAPERR;
		return ;
	}
	ft_insert(mass, i, buff, rules);
	ft_clean(rules, desc, mass);
}
