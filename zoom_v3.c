/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_v3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:34:33 by snagat            #+#    #+#             */
/*   Updated: 2022/02/17 17:40:23 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in4(t_data *data, double n_x, double n_y, int interp)
{
	data->ref->num_im_max = (data->ref->num_im_max - n_y) / interp + n_y;
	data->ref->num_im_min = (data->ref->num_im_min - n_y) / interp + n_y;
	data->ref->num_re_max = (data->ref->num_re_max - n_x) / interp + n_x;
	data->ref->num_re_min = (data->ref->num_re_min - n_x) / interp + n_x;
	data->iterations += 20;
}

void	zoom_out3(t_data *data, double n_x, double n_y, int interp)
{
	data->ref->num_im_max = (data->ref->num_im_max - n_y) * interp + n_y;
	data->ref->num_im_min = (data->ref->num_im_min - n_y) * interp + n_y;
	data->ref->num_re_max = (data->ref->num_re_max - n_x) * interp + n_x;
	data->ref->num_re_min = (data->ref->num_re_min - n_x) * interp + n_x;
	data->iterations -= 20;
}

int	zoom_v3(int key, int x, int y, t_data *data)
{
	int		interp;
	double	n_y;
	double	n_x;

	interp = 2;
	n_x = scale(x, SQUARE, data->ref->num_re_max,
			data->ref->num_re_min);
	n_y = scale(y, SQUARE, data->ref->num_im_max,
			data->ref->num_im_min);
	if (key == ZOOM_IN)
		zoom_in4(data, n_x, n_y, interp);
	else if (key == ZOOM_OUT)
		zoom_out3(data, n_x, n_y, interp);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	psh_pixl(data, &eqt_3);
	return (0);
}
