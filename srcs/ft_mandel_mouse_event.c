#include "fractol.h"

static void		ft_mandel_dezoom(int x, int y, t_mand *mand)
{
	mand->zoom -= 20;
	if (x >= 0 && x <= 200 && y >= 180 && y <= 320)
		mand->x_one += 0.05;
	if (x <= 500 && x >= 400 && y >= 220 && y <= 350)
		mand->x_one -= 0.05;
	if (x <= 250 && y < 180)
	{
		mand->x_one += 0.05;
		mand->y_one += 0.05;
	}
	else if (x > 250 && y < 180)
	{
		mand->x_one -= 0.05;
		mand->y_one += 0.05;
	}
	else if (x > 250 && y > 320)
	{
		mand->x_one -= 0.05;
		mand->y_one -= 0.05;
	}
	else if (x <= 250 && y > 320)
	{
		mand->x_one += 0.05;
		mand->y_one -= 0.05;
	}
}

static void		ft_mandel_zoom(int x, int y, t_mand *mand)
{
	mand->zoom += 20;
	if (x >= 0 && x <= 200 && y >= 180 && y <= 320)
		mand->x_one -= 0.05;
	if (x <= 500 && x >= 400 && y >= 220 && y <= 350)
		mand->x_one += 0.05;
	if (x <= 250 && y < 180)
	{
		mand->x_one -= 0.05;
		mand->y_one -= 0.05;
	}
	else if (x > 250 && y < 180)
	{
		mand->x_one += 0.05;
		mand->y_one -= 0.05;
	}
	else if (x > 250 && y > 320)
	{
		mand->x_one += 0.05;
		mand->y_one += 0.05;
	}
	else if (x <= 250 && y > 320)
	{
		mand->x_one -= 0.05;
		mand->y_one += 0.05;
	}
}

int				ft_mandel_mouse_button(int button, int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *)param;
	if (button == ZOOMPLUS)
		ft_mandel_zoom(x, y, &(fract->mand));
	else if (button == ZOOMMINUS)
	{
		if (fract->mand.zoom > 100)
			ft_mandel_dezoom(x, y, &(fract->mand));
	}
	else if (button == RIGHTCLICK)
	{
		fract->mand.block = fract->mand.block == 1 ? 0 : 1;
		return (0);
	}
	else
		return (-1);
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_clear_window(fract->mlx, fract->win);
	ft_mandel_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	return (0);
}

int				ft_mandel_mouse_position(int x, int y, void *param)
{
	t_fract		*fract;

	fract = (t_fract *)param;
	if(x < 0 || y < 0 || x > fract->x_sizewin || y > fract->y_sizewin ||
		fract->mand.block == 1)
		return (-1);
	fract->mand.c_i = (double)x / 10000;
	fract->mand.c_r = (double)y / 1000;
	mlx_destroy_image(fract->mlx, fract->image);
	mlx_clear_window(fract->mlx, fract->win);
	ft_mandel_image(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	return (0);
}
