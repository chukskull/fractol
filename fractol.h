/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:43:24 by snagat            #+#    #+#             */
/*   Updated: 2022/02/19 18:54:27 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define SQUARE 720
# define ZOOM_IN 5
# define ZOOM_OUT 4
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_RIGHT 124
# define ARROW_LEFT 123
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>

typedef struct numr
{
	double	x;
	double	y;
}t_num;
typedef struct Ref
{
	double	num_re_max;
	double	num_im_max;
	double	num_re_min;
	double	num_im_min;
}t_ref;

typedef struct p_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	initial;
	double	initialy;
	int		iterations;
	t_ref	*ref;
	t_num	julia;
	int		paused;
	int		color;
}t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		eqt_3(double num_r, double num_I, int max_interations, t_data *data);
double	scale(double val, double max, double range, double range2);
int		eqt_(double num_r, double num_I, int max_interations, t_data *data);
void	psh_pixl(t_data *data, int (*fun)(double, double, int, t_data *data));
int		zoom_(int key, int x, int y, t_data *data);
int		move(int key, t_data *data);
int		ft_close(int keycode, t_data *p);
int		key_handler(int keycode, t_data *data);
void	mandelbrot(t_data *data, t_ref *ref);
void	julia(t_data *data, t_ref *ref);
void	burning_ship(t_data *data, t_ref *ref);
int		eqt_2(double num_r, double num_I, int max_interations, t_data *data);
int		zoom_v2(int key, int x, int y, t_data *data);
int		zoom_v3(int key, int x, int y, t_data *data);
int		ft_strcmp(char *s1, char *s2);
int		key_handler2(int keycode, t_data *data);
int		key_handler3(int keycode, t_data *data);

#endif