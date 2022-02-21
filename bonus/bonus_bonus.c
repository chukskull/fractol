/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:18:14 by snagat            #+#    #+#             */
/*   Updated: 2022/02/20 20:18:34 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	*data;
	t_ref	*ref;

	ref = NULL;
	data = malloc(sizeof(t_data));
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "Burningship"))
			burning_ship(data, ref);
		if (!ft_strcmp(av[1], "Mandelbrot"))
			mandelbrot(data, ref);
		else if (!ft_strcmp(av[1], "Julia"))
			julia(data, ref);
		else
			write(1, "Usage : ./fracol Mandelbrot \n", 30);
		write(1, "./fractol Julia\n", 17);
		write(1, "./fractol Burningship\n", 23);
	}
	else
	{
		write(1, "Usage : ./fracol Mandelbrot \n", 30);
		write(1, "./fractol Julia\n", 17);
		write(1, "./fractol Burningship\n", 23);
	}
	return (0);
}
