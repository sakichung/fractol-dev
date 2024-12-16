/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:22:05 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 12:31:04 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"

/*-----------------------------------*/
/*	Libraries	*/
/*-----------------------------------*/
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

/*-----------------------------------*/
/*	Keys Dataes	*/
/*-----------------------------------*/
# include <X11/X.h>
# include <X11/keysym.h>

/*-----------------------------------*/
/*	Default Dimensions*/
/*-----------------------------------*/
/*	Window Size	*/
# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITER 100
# define MOVEMENT 25

/*	Viewport	*/
# define MANDELBROT 1
# define JULIA 2

/*-----------------------------------*/
/*	Fractal Rendering Settings	*/
/*-----------------------------------*/
typedef struct s_complex
{
	double		real;
	double		imag;
}				t_complex;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*buf;
	int			palette[MAX_ITER];
	int			set;
	t_complex	julia_c;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		zoom_level;
}				t_fractol;

enum			e_interface
{
	ESC = XK_Escape,
	MV_UP = XK_w,
	MV_LEFT = XK_a,
	MV_DOWN = XK_s,
	MV_RIGHT = XK_d,
	WHEEL_UP = Button4,
	WHEEL_DOWN = Button5
};

/*-----------------------------------*/
/*	Functions	*/
/*-----------------------------------*/
void			set_pixel_color(t_fractol *f, int x, int y, int color);
void			error_msg(char *msg);
int				mandelbrot(t_complex c, int max_iterations);
int				julia(t_complex z, t_complex c, int max_iterations);
void			set_fractal_range(t_fractol *f, int set, int argc, char **argv);
void			render_fractal(t_fractol *f);
void			render(t_fractol *f);
void			generate_palette(int *palette);
void			init(t_fractol *f);
int				close_windows_hook(void *param);
int				zoom_hook(int button, int x, int y, void *param);
int				key_hook(int keycode, void *param);
void			check_input(int argc, char **argv, int set);
int				end_fractol(t_fractol *mlx);

double			ft_atof(char *str, char **endptr);

#endif