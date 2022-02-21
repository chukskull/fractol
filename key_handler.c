/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:38:11 by snagat            #+#    #+#             */
/*   Updated: 2022/02/20 20:36:24 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == 24)
		data->color += 0xf8e4b2;
	if (keycode == 27)
		data->color -= 0xf8e4b2;
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	psh_pixl(data, &eqt_);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

int	key_handler2(int keycode, t_data *data)
{
	if (keycode == 24)
		data->color += 0xf8e4b2;
	if (keycode == 27)
		data->color -= 0xf8e4b2;
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	psh_pixl(data, &eqt_2);
	if (keycode == 35)
	{
		if (data->paused == 1)
			data->paused = 0;
		else
			data->paused = 1;
	}
	else if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
