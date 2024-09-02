#include "../include/so_long.h"
#include <time.h>

t_bool	init_game(t_game **game)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (*game == NULL)
		return (ft_error("Failed to allocate memory for game\n"), FALSE);
	(*game)->mlx = NULL;
	(*game)->map = NULL;
	(*game)->enemies = NULL;
	(*game)->tileset = NULL;
	(*game)->collectibles = NULL;
	(*game)->player = NULL;
	(*game)->exit = NULL;
	(*game)->movement = NULL;
	(*game)->textures = NULL;
	(*game)->time_accumulated = 0.0;
	(*game)->last_time = 0.0;
	(*game)->rand_seed = 123456789;
	return (TRUE);
}
