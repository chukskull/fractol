/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Equation_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:31:07 by snagat            #+#    #+#             */
/*   Updated: 2022/02/19 16:03:29 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// z = z^2 + c;

int	eqt_(double num_r, double num_I, int max_interations, t_data *data)
{
	double	temp;
	double	zr;
	double	zi;
	int		i;

	i = 0;
	zr = num_r;
	zi = num_I;
	while (i < max_interations && zr * zr + zi * zi < 4.0)
	{
		temp = zr * zr - zi * zi + num_r;
		zi = 2.0 * zr * zi + num_I;
		zr = temp;
		i++;
	}
	if (i == max_interations)
		return (i * 0x7fffd4);
	return (i * 2 * data->color);
}
