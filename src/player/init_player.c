#include "../../include/so_long.h"

static void draw_player(t_game *game) {
  for (int i = 0; i < TILE_SIZE; i++) {
    for (int x = 0; x < TILE_SIZE; x++) {
      mlx_put_pixel(game->player->img, x, i, 0xFF0000FF);
    }
  }
}

void init_player(t_game *game) {
  game->player = malloc(sizeof(t_player));
  game->player->img = mlx_new_image(game->mlx, TILE_SIZE, TILE_SIZE);
  if (game->player->img == NULL ||
      mlx_image_to_window(game->mlx, game->player->img, 0, 0) < 0)
    ft_error("Failed to create and display player image");
  draw_player(game);
}
