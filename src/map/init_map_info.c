#include "../../include/so_long.h"

void	init_map_info(t_map_info *validate_map)
{
	validate_map->player = FALSE;
	validate_map->exit = FALSE;
	validate_map->collectible = FALSE;
}
