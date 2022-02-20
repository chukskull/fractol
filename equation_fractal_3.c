/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_fractal_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:28:44 by snagat            #+#    #+#             */
/*   Updated: 2022/02/18 16:11:38 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// z = z^2 + c;

double	valeur_absolue(double num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	eqt_3(double num_r, double num_I, int max_interations, t_data *data)
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
		temp = valeur_absolue(zr * zr - zi * zi + num_r);
		zi = valeur_absolue(2 * zr * zi + num_I);
		zr = temp;
		i++;
	}
	if (i == max_interations)
		return (0x7fffd4);
	return (i * data->color);
}
