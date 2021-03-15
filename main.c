#include "bsq.h"

int	main(int argc, char **argv)
{
	int	ind;
	int	desc;

	ind = 1;
	if (argc == 1)
	{
		desc = ft_origin_input();
		ft_func(desc, "map");
	}
	else
	{
		while (ind < argc)
		{
			desc = ft_file_input(argv[ind]);
			ft_func(desc, argv[ind]);
			if (ind != (argc - 1))
				write(1, "\n\n", 2);
			ind++;
		}
	}
	exit(0);
}
