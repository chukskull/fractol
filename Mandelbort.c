/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:56:36 by snagat            #+#    #+#             */
/*   Updated: 2022/02/20 15:49:33 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	array_up(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->ref->num_im_max -= (data->ref->num_im_max
			-data->ref->num_im_min) / 50;
	data->ref->num_im_min += (data->ref->num_im_min
			-data->ref->num_im_max) / 50;
	psh_pixl(data, &eqt_);
}

void	array_down(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->ref->num_im_max += (data->ref->num_im_max
			-data->ref->num_im_min) / 50;
	data->ref->num_im_min -= (data->ref->num_im_min
			-data->ref->num_im_max) / 50;
	psh_pixl(data, &eqt_);
}

int	move(int key, t_data *data)
{
	if (key == ARROW_RIGHT)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->ref->num_re_max += (data->ref->num_re_max
				-data->ref->num_re_min) / 50;
		data->ref->num_re_min -= (data->ref->num_re_min
				-data->ref->num_re_max) / 50;
		psh_pixl(data, &eqt_);
	}
	else if (key == ARROW_LEFT)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->ref->num_re_max -= (data->ref->num_re_max
				-data->ref->num_re_min) / 50;
		data->ref->num_re_min += (data->ref->num_re_min
				-data->ref->num_re_max) / 50;
		psh_pixl(data, &eqt_);
	}
	else if (key == ARROW_DOWN)
		array_down(data);
	else if (key == ARROW_UP)
		array_up(data);
	return (0);
}

void	psh_pixl(t_data *data, int (*fun)(double, double, int, t_data *data))
{
	double	n_i;
	double	n_r;
	int		n;
	int		x;
	int		y;

	x = 0;
	while (x < SQUARE)
	{
		n_r = scale(x, SQUARE, data->ref->num_re_max, data->ref->num_re_min);
		y = 0;
		while (y < SQUARE)
		{
			n_i = scale(y, SQUARE, data->ref->num_im_max,
					data->ref->num_im_min);
			n = (*fun)(n_r, n_i, data->iterations, data);
			my_mlx_pixel_put(data, x, y, n);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
}

void	mandelbrot(t_data *data, t_ref *ref)
{
	ref = malloc(sizeof(t_ref));
	if (!ref || !data)
		exit(0);
	ref->num_im_max = 2;
	ref->num_re_max = 2;
	ref->num_re_min = -2;
	ref->num_im_min = -2;
	data->iterations = 100;
	data->color = 0xfff5ee;
	data->ref = ref;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "Mandelbort");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	psh_pixl(data, &eqt_);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_hook(data->win, 2, 1L << 0, move, data);
	mlx_mouse_hook(data->win, zoom_, data);
	mlx_key_hook(data->win, key_handler, data);
	mlx_loop(data->mlx);
}
