#include "fractol.h"

int				ft_escape_key(int keycode, void *param)
{
	if (keycode == ESCAPEKEY)
		exit(EXIT_SUCCESS);
	(void)param;
	return (0);
}
