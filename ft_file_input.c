#include "bsq.h"

int	ft_file_input(char *argv)
{
	int desc;
	desc = open(argv, O_RDONLY);
	return (desc);
}
