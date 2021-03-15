#include "bsq.h"

int	ft_check_height(char *mass, int a)
{
	int count;
	int visota;
	visota = 0;
	count = a;
	a = 0;
	if (mass[a] > '9' || mass[a] < '0')
		return (-1);
	while (a < (count - 4))
	{
		if (mass[a] > '9' || mass[a] < '0')
			return (-1);
		visota *= 10;
		visota = visota + (mass[a] - 48);
		a++;
	}
	return (visota);
}

int	ft_check_width(int desc)
{
	char	temp;
	int		point;

	temp = 'x';
	point = 0;
	while (temp != '\n')
	{
		read(desc, &temp, 1);
		point++;
	}
	close(desc);
	return (point);
}

int	ft_check(int desc, char *argv, t_rules *rules)
{
	char	height;
	char	mass[1024];
	int		a;
	height = 'L';
	a = 0;
	while (height != '\n')
	{
		read(desc, &height, 1);
		mass[a] = height;
		a++;
	}
	mass[a] = '\0';
	if (a < 4)
		return (-1);
	if ((rules->height = ft_check_height(mass, a)) == -1)
		return (-1);
	rules->point = mass[a - 4];
	rules->o = mass[a - 3];
	rules->x = mass[a - 2];
	rules->width = ft_check_width(desc);
	desc = open(argv, O_RDONLY);
	read(desc, &height, a);
	return (desc);
}
