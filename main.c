#include "bsq.h"

int	main(int argc, char **argv)
{
	int	ind;
	int	desc;

	ind = 1;
	if (argc == 1)								//Choosing between standard and file input
	{
		desc = ft_origin_input();				//Creating a file from origin input
		ft_func(desc, "map");
	}
	else
	{
		while (ind < argc)						//Loop for multiple arguments
		{
			if ((desc = ft_file_input(argv[ind])) > 0)
				ft_func(desc, argv[ind]);		//Main process
			if (ind != (argc - 1))
				write(1, "\n\n", 2);
			ind++;
		}
	}
	exit(0);
}
