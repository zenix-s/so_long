#include "../../include/so_long.h"

t_bool	alloc_collectibles(t_game *game, size_t n_collectibles)
{
	game->collectibles = (t_collectibles *)malloc(sizeof(t_collectibles));
	if (game->collectibles == NULL)
		return (ft_error("Failed to allocate memory for collectibles"), FALSE);
	game->collectibles->collectibles = (t_collectible **)malloc(sizeof(t_collectible *)
			* n_collectibles);
	if (game->collectibles->collectibles == NULL)
		return (ft_error("Failed to allocate memory for collectibles"), FALSE);
	game->collectibles->n_collectibles = n_collectibles;
	return (TRUE);
}
