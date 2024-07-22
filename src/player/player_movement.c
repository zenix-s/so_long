#include "../../include/so_long.h"

// Function prototypes
int is_within_bounds(int new_x, int new_y, t_game *game);
int is_walkable_tile(int new_x, int new_y, t_game *game);
void update_player_position(int new_x, int new_y, t_game *game);

void ft_player_move(t_game *game, char direction, int total)
{
    if (!game || !game->player || !game->player->img) {
        printf("Error: game or game->player or game->player->img is NULL\n");
        return;
    }

    int new_x = game->player->img->instances[0].x;
    int new_y = game->player->img->instances[0].y;

    // Determine new position based on direction
    if (direction == 'u')
        new_y -= total;
    else if (direction == 'd')
        new_y += total;
    else if (direction == 'l')
        new_x -= total;
    else if (direction == 'r')
        new_x += total;

    printf("New position: (%d, %d)\n", new_x, new_y);

    // Check if new position is within bounds and walkable
    if (is_within_bounds(new_x, new_y, game) && is_walkable_tile(new_x, new_y, game))
    {
        update_player_position(new_x, new_y, game);
    }
}

int is_within_bounds(int new_x, int new_y, t_game *game)
{
    if (!game || !game->map) {
        printf("Error: game or game->map is NULL\n");
        return 0;
    }

    unsigned long map_width_in_pixels = game->map->width * TILE_SIZE;
    unsigned long map_height_in_pixels = game->map->height * TILE_SIZE;

    if (new_x < 0 || (unsigned int)new_x >= map_width_in_pixels ||
        new_y < 0 || (unsigned int)new_y >= map_height_in_pixels)
    {
        printf("Position out of bounds\n");
        return 0; // Out of bounds
    }
    return 1; // Within bounds
}

int is_walkable_tile(int new_x, int new_y, t_game *game)
{
    if (!game || !game->map || !game->map->tiles) {
        printf("Error: game or game->map or game->map->tiles is NULL\n");
        return 0;
    }

    size_t i = 0;
    while (i < (game->map->height * game->map->width))
    {
        t_tile *tile = game->map->tiles[i];
        if (!tile || !tile->img) {
            printf("Error: tile or tile->img is NULL at index %zu\n", i);
            return 0;
        }

        unsigned int tile_x = tile->img->instances[0].x;
        unsigned int tile_y = tile->img->instances[0].y;
        unsigned int tile_width = tile->img->width;
        unsigned int tile_height = tile->img->height;

        if ((unsigned int)new_x >= tile_x && (unsigned int)new_x + game->player->img->width <= tile_x + tile_width &&
            (unsigned int)new_y >= tile_y && (unsigned int)new_y + game->player->img->height <= tile_y + tile_height)
        {
            if (tile->type == '0') // Assuming '0' means walkable
            {
                return 1; // Tile is walkable
            }
            else
            {
                return 0; // Tile is not walkable
            }
        }
        i++;
    }
    printf("No matching tile found\n");
    return 0; // No matching tile found (should not happen)
}

void update_player_position(int new_x, int new_y, t_game *game)
{
    if (!game || !game->player || !game->player->img) {
        printf("Error: game or game->player or game->player->img is NULL\n");
        return;
    }

    game->player->img->instances[0].x = new_x;
    game->player->img->instances[0].y = new_y;
}
