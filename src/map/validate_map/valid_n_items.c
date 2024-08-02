#include "../../../include/so_long.h"


t_bool	valid_n_items(t_validate_map *validate_map)
{
	if (!validate_map->player)
		return (ft_error("Player not found"), FALSE);
	if (!validate_map->exit)
		return (ft_error("Exit not found"), FALSE);
	if (!validate_map->collectible)
		return (ft_error("Collectible not found"), FALSE);
	return (TRUE);
}
