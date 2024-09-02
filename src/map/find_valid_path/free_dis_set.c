#include "../../../include/so_long.h"

void	free_dis_set(t_dis_set *dis_set)
{
	int32_t	i;

	i = 0;
	while (i < dis_set->size)
	{
		free(dis_set->items[i]);
		i++;
	}
	free(dis_set->items);
	free(dis_set);
}
