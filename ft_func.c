#include "bsq.h"

void	ft_func(int desc, char *argv)
{
	t_rules *rules;
	char	*buff;
	int		**mass;
	int		i;
	i = 0;
	rules = (t_rules *)malloc(sizeof(t_rules));				//Memory allocation for the rules-structure
	if ((desc = ft_check(desc, argv, rules)) == -1)			//Check, whether rules are valid or not
	{
		MAPERR;
		return ;
	}
	rules->end_i = 0;
	rules->end_j = 0;
	rules->nbr = 0;
	rules->i = 0;
	rules->j = 0;
	mass = ft_malloc(rules);								//Memory allocation for the digit-array
	if ((buff = ft_insert_o(desc, rules, mass)) == NULL)	//Transfer x from the map to the 0
	{
		MAPERR;
		return ;
	}
	ft_insert(mass, i, buff, rules);						//Calculating the biggest square and then printing
	ft_clean(rules, desc, mass);							//Memory clean
}
