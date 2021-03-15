#include "bsq.h"

int		ft_strlen(char *buff)
{
	int ind;

	ind = 0;
	while (buff[ind] != '\n')
	{
		ind++;
	}
	return (ind);
}

char	*ft_mass_o(int count, int **mass, char *buff, t_rules *rules)
{
	while (*buff)
	{
		if (*buff == rules->point)
			mass[rules->i][rules->j] = 1;
		else if (*buff == rules->o)
			mass[rules->i][rules->j] = 0;
		else if (*buff == '\n')
		{
			rules->i++;
			if (rules->j != rules->width - 1)
				return (NULL);
			count++;
			rules->j = -1;
		}
		else
			return (NULL);
		rules->j++;
		buff++;
	}
	if (rules->j > 0)
		count++;
	if (count != rules->height)
		return (NULL);
	return (buff);
}

char	*ft_insert_o(int desc, t_rules *rules, int **mass)
{
	int		count;
	int		size;
	char	*buff;
	count = 0;
	size = rules->width * rules->height;
	buff = malloc((size) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	read(desc, buff, size);

	buff[size - 1] = '\0';
	if ((buff = ft_mass_o(count, mass, buff, rules)) == NULL)
		return NULL;
	buff -= (size - 1);
	return (buff);
}
