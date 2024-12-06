#ifndef COLLECTIBLES_H

# define COLLECTIBLES_H

# include "../structs.h"

t_bool	all_collected(t_game *game);

void	collect_collectible(t_game *game, int32_t x, int32_t y);

t_bool	init_collectibles(t_game *game);

t_bool	render_collectibles(t_game *game);

#endif
