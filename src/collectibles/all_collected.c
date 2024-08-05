#include "../../include/so_long.h"

t_bool	all_collected(t_game *game)
{
	if (game->player->score == game->collectibles->n_collectibles)
		return (TRUE);
	return (FALSE);
}
