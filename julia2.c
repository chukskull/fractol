/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:19:35 by snagat            #+#    #+#             */
/*   Updated: 2022/02/20 15:49:49 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	movement(int x, int y, t_data	*data)
{
	if (data->paused)
		return (1);
	data->julia.x = x;
	data->julia.y = y;
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	psh_pixl(data, eqt_2);
	return (1);
}

void	array_up2(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->ref->num_im_max -= (data->ref->num_im_max
			-data->ref->num_im_min) / 50;
	data->ref->num_im_min += (data->ref->num_im_min
			-data->ref->num_im_max) / 50;
	psh_pixl(data, &eqt_2);
}

void	array_down2(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->ref->num_im_max += (data->ref->num_im_max
			-data->ref->num_im_min) / 50;
	data->ref->num_im_min -= (data->ref->num_im_min
			-data->ref->num_im_max) / 50;
	psh_pixl(data, &eqt_2);
}

int	move2(int key, t_data *data)
{
	if (key == ARROW_RIGHT)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->ref->num_re_max += (data->ref->num_re_max
				-data->ref->num_re_min) / 50;
		data->ref->num_re_min -= (data->ref->num_re_min
				-data->ref->num_re_max) / 50;
		psh_pixl(data, &eqt_2);
	}
	else if (key == ARROW_LEFT)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->ref->num_re_max -= (data->ref->num_re_max
				-data->ref->num_re_min) / 50;
		data->ref->num_re_min += (data->ref->num_re_min
				-data->ref->num_re_max) / 50;
		psh_pixl(data, &eqt_2);
	}
	else if (key == ARROW_DOWN)
		array_down2(data);
	else if (key == ARROW_UP)
		array_up2(data);
	return (0);
}

void	julia(t_data *data, t_ref *ref)
{
	ref = malloc(sizeof(t_ref));
	if (!ref || !data)
		exit(0);
	ref->num_im_max = 2;
	ref->num_re_max = 2;
	ref->num_re_min = -2;
	ref->num_im_min = -2;
	data->iterations = 100;
	data->paused = 1;
	data->color = 0xfff5ee;
	data->ref = ref;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "Julia");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	psh_pixl(data, eqt_2);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_hook(data->win, 6, 1, movement, data);
	mlx_hook(data->win, 2, 1L << 0, move2, data);
	mlx_mouse_hook(data->win, zoom_v2, data);
	mlx_key_hook(data->win, key_handler2, data);
	mlx_loop(data->mlx);
}
