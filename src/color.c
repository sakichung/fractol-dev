/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:59:48 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 10:59:52 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iterations(double cr, double ci, int max_iter)
{
	int		iter;
	double	tmp;
	double	zr;
	double	zi;

	zr = 0.0;
	zi = 0.0;
	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < max_iter)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	int	index;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	index = (y * WIDTH + x) * 4;
	f->buf[index] = color;
	f->buf[index + 1] = color >> 8;
	f->buf[index + 2] = color >> 16;
	f->buf[index + 3] = color >> 24;
}

void	generate_palette(int *palette)
{
	double	t;
	int		red;
	int		green;
	int		blue;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		t = pow((double)i / (MAX_ITER - 1) + 0.005, 0.5);
		if (t < 0.4)
		{
			red = (int)(2 * t * 255);
			green = (int)(2 * t * 255);
			blue = 255 - (int)(2 * t * 255);
		}
		else
		{
			red = 255;
			green = (int)((1 - (t - 0.5) * 2) * 255);
			blue = 0;
		}
		palette[i] = (red << 16) | (green << 8) | blue;
		i++;
	}
}
