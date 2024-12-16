/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:55:55 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 12:48:30 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	safe_atof(char *str);

static int	calculate_fractal(t_fractol *f, double pr, double pi)
{
	int	nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot((t_complex){pr, pi}, MAX_ITER);
	else if (f->set == JULIA)
		nb_iter = julia((t_complex){pr, pi}, f->julia_c, MAX_ITER);
	else
		nb_iter = 0;
	return (nb_iter);
}

void	render_fractal(t_fractol *f)
{
	double	cr;
	double	ci;
	int		iter;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cr = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
			ci = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;
			iter = calculate_fractal(f, cr, ci);
			if (iter == MAX_ITER)
				set_pixel_color(f, x, y, 0x000000);
			else
				set_pixel_color(f, x, y, f->palette[iter % MAX_ITER]);
			x++;
		}
		y++;
	}
}

void	set_fractal_range(t_fractol *f, int set, int argc, char **argv)
{
	f->set = set;
	if (set == MANDELBROT)
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = 1.5;
	}
	else if (set == JULIA)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
		if (argc == 4)
		{
			f->julia_c.real = safe_atof(argv[2]);
			f->julia_c.imag = safe_atof(argv[3]);
		}
		else
			f->julia_c = (t_complex){.real = -0.7, .imag = 0.27015};
	}
	else
		error_msg("Invalid fractal set value");
}

void	render(t_fractol *f)
{
	render_fractal(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

static double	safe_atof(char *str)
{
	char	*endptr;
	double	ret;

	endptr = NULL;
	ret = ft_atof(str, &endptr);
	return (ret);
}
