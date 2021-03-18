#include "bsq.h"

void	ft_print_x(t_rules *rules)
{
	int		nbr;
	char	x;

	nbr = rules->nbr;
	x = rules->x;
	while (nbr > 0)
	{
		write(1, &x, 1);
		nbr--;
	}
}

void	ft_print_point(int between, char *buff)
{
	while (between > 0)
	{
		write(1, buff, 1);
		buff++;
		between--;
	}
}

char	*ft_print_ox(int nbr, char *buff)
{
	while (nbr > 0)
	{
		write(1, buff, 1);
		buff++;
		nbr--;
	}
	return (buff);
}

void	ft_print_fin(char *buff, t_rules *rules)
{
	int start;
	int end;
	int point;
	int between;

	if (rules->nbr !=0)
		between = rules->width - rules->nbr;							//Count char beetween lines of X
	else
		between = 0;
	point = rules->nbr;
	start = rules->width * rules->end_i + rules->end_j;					//Count char before starting of the cube
	end = rules->width * (rules->height - rules->nbr - rules->end_i)	//Count char after end of the cube
	+ (between - rules->end_j);
	buff = ft_print_ox(start, buff);
	while (point > 0)
	{
		ft_print_x(rules);
		buff += rules->nbr;
		if (point != 1)
		{
			ft_print_point(between, buff);
			buff = buff + between;
		}
		point--;
	}
	buff = ft_print_ox(end, buff);
}
