#include "bsq.h"

int	ft_origin_input(void)
{
	char	temp2[1024];
	int		desc;
	int		size;

	desc = open("map", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	while ((size = read(0, temp2, 10000)) != 0)						//Read from origin input to the "map" file
		write(desc, temp2, size);
	close(desc);
	desc = open("map", O_RDONLY);
	return (desc);
}
