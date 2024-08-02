#include "../include/so_long.h"

t_bool load_textures(t_game *game)
{
	game->textures = malloc(sizeof(t_textures));
	if (game->textures == NULL)
		return (ft_error("Failed to allocate memory for textures"), FALSE);
	game->textures->player = mlx_load_png("textures/player.png");
	if (game->textures->player == NULL)
		return (ft_error("Failed to load player texture"), FALSE);
	game->textures->wall = mlx_load_png("textures/wall.png");
	if (game->textures->wall == NULL)
		return (ft_error("Failed to load wall texture"), FALSE);
	game->textures->floor = mlx_load_png("textures/floor.png");
	if (game->textures->floor == NULL)
		return (ft_error("Failed to load floor texture"), FALSE);
	game->textures->collectible = mlx_load_png("textures/collectible.png");
	if (game->textures->collectible == NULL)
		return (ft_error("Failed to load collectible texture"), FALSE);
	ft_printf("TODO: Load textures\n");
	return (TRUE);
}
