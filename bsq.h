#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define MAPERR write(2, "map error\n", 10)

typedef struct		s_rules
{
	int				height;
	char			point;
	char			o;
	char			x;
	int				width;
	int				end_i;
	int				end_j;
	int				nbr;
	int				i;
	int				j;
}					t_rules;

int					ft_origin_input();

int					ft_file_input(char *argv);

void				ft_func(int desc, char *argv);

int					ft_check(int desc, char *argv, t_rules *rules);

int					**ft_malloc(t_rules *rules);

char				*ft_insert_o(int desc, t_rules *rules, int **mass);

void				ft_insert(int **mass, int i, char *buff, t_rules *rules);

void				ft_start(char *buff, t_rules *rules);

void				ft_print_fin(char *buff, t_rules *rules);

void				ft_clean(t_rules *rules, int desc, int **mass);

#endif
