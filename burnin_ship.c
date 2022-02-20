/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnin_ship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:30:05 by snagat            #+#    #+#             */
/*   Updated: 2022/02/19 19:03:41 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	array_up3(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->ref->num_im_max -= (data->ref->num_im_max
			-data->ref->num_im_min) / 50;
	data->ref->num_im_min += (data->ref->num_im_min
			-data->ref->num_im_max) / 50;
	psh_pixl(data, &eqt_3);
}

void	array_down3(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->ref->num_im_max += (data->ref->num_im_max
			-data->ref->num_im_min) / 50;
	data->ref->num_im_min -= (data->ref->num_im_min
			-data->ref->num_im_max) / 50;
	psh_pixl(data, &eqt_3);
}

int	move3(int key, t_data *data)
{
	if (key == ARROW_RIGHT)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->ref->num_re_max += (data->ref->num_re_max
				-data->ref->num_re_min) / 50;
		data->ref->num_re_min -= (data->ref->num_re_min
				-data->ref->num_re_max) / 50;
		psh_pixl(data, &eqt_3);
	}
	else if (key == ARROW_LEFT)
	{
		mlx_clear_window(data->mlx, data->win);
		data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
		data->ref->num_re_max -= (data->ref->num_re_max
				-data->ref->num_re_min) / 50;
		data->ref->num_re_min += (data->ref->num_re_min
				-data->ref->num_re_max) / 50;
		psh_pixl(data, &eqt_3);
	}
	else if (key == ARROW_DOWN)
		array_down3(data);
	else if (key == ARROW_UP)
		array_up3(data);
	return (0);
}

void	burning_ship(t_data *data, t_ref *ref)
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
	data->win = mlx_new_window(data->mlx, SQUARE, SQUARE, "burning ship ");
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	psh_pixl(data, &eqt_3);
	mlx_hook(data->win, 17, 0, ft_close, data);
	mlx_hook(data->win, 2, 1L << 0, move3, data);
	mlx_mouse_hook(data->win, zoom_v3, data);
	mlx_key_hook(data->win, key_handler3, data);
	mlx_loop(data->mlx);
}
