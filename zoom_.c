/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:52:32 by snagat            #+#    #+#             */
/*   Updated: 2022/02/20 15:54:37 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in2(t_data *data, double n_x, double n_y, int interp)
{
	data->ref->num_im_max = (data->ref->num_im_max - n_y) / interp + n_y ;
	data->ref->num_im_min = (data->ref->num_im_min - n_y) / interp + n_y;
	data->ref->num_re_max = (data->ref->num_re_max - n_x) / interp + n_x;
	data->ref->num_re_min = (data->ref->num_re_min - n_x) / interp + n_x;
	data->iterations += 20;
}

void	zoom_out(t_data *data, double n_x, double n_y, int interp)
{
	data->ref->num_im_max = (data->ref->num_im_max - n_y) * interp + n_y;
	data->ref->num_im_min = (data->ref->num_im_min - n_y) * interp + n_y;
	data->ref->num_re_max = (data->ref->num_re_max - n_x) * interp + n_x;
	data->ref->num_re_min = (data->ref->num_re_min - n_x) * interp + n_x;
	data->iterations -= 20;
}

int	zoom_(int key, int x, int y, t_data *data)
{
	double	interp;
	double	n_y;
	double	n_x;

	interp = 2;
	n_x = scale(x, SQUARE, data->ref->num_re_max,
			data->ref->num_re_min);
	n_y = scale(y, SQUARE, data->ref->num_im_max,
			data->ref->num_im_min);
	if (key == ZOOM_IN)
		zoom_in2(data, n_x, n_y, interp);
	else if (key == 4)
		zoom_out(data, n_x, n_y, interp);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, SQUARE, SQUARE);
	psh_pixl(data, &eqt_);
	return (0);
}
