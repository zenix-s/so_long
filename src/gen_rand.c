#include "../include/so_long.h"

unsigned int	gen_rand(unsigned int min, unsigned int max, unsigned int *seed)
{
	*seed = *seed * 1103515245 + 12345;
	return (1 + (((*seed / 65536) % 32768) % (max - min + 1)));
}
