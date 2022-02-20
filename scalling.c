/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:35:17 by snagat            #+#    #+#             */
/*   Updated: 2022/02/17 16:33:28 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double val, double max, double range, double range2)
{
	double	r_1;
	double	r_2;

	r_1 = max;
	r_2 = range - range2;
	return (range2 + (val * (r_2 / r_1)));
}
