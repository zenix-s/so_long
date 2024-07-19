#include "../../include/so_long.h"

void ft_player_move(t_game *game, char direction, int total) {
  int new_x;
  int new_y;

  new_x = game->player->img->instances[0].x;
  new_y = game->player->img->instances[0].y;
  if (direction == 'u')
    new_y -= total;
  else if (direction == 'd')
    new_y += total;
  else if (direction == 'l')
    new_x -= total;
  else if (direction == 'r')
    new_x += total;
  game->player->img->instances[0].x = new_x;
  game->player->img->instances[0].y = new_y;
}
