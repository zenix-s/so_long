#include "../include/so_long.h"

t_bool	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_error("Invalid number of arguments\n");
		return (FALSE);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
	{
		ft_error("Invalid file extension\n");
		return (FALSE);
	}
	return (TRUE);
}
