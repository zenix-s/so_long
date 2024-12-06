#ifndef EXIT_H

# define EXIT_H

// INCLUDES SECTION
# include "../structs.h"

/**
 * Allocates memory for the exit struct and its textures.
 * @param game The game struct.
 */
t_bool	init_exit(t_game *game);

/**
 * Unlocks the exit and changes its texture to the open one.
 * @param game The game struct.
 */
t_bool	open_exit(t_game *game);

/**
 * Renders the exit with the closed texture.
 * @param game The game struct.
 */
t_bool	render_closed_exit(t_game *game);

/**
 * Free the exit struct and all its components
 */
void	free_exit(t_game *game);

#endif
