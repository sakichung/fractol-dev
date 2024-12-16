/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:27 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 11:04:53 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_windows_hook(void *param)
{
	if (param != NULL)
		end_fractol(param);
	exit(0);
	return (0);
}

int	zoom_hook(int button, int x, int y, void *param)
{
	t_fractol	*f;

	(void)x;
	(void)y;
	f = (t_fractol *)param;
	if (button == WHEEL_DOWN)
	{
		f->max_i = f->max_i * 0.8;
		f->min_i = f->min_i * 0.8;
		f->max_r = f->max_r * 0.8;
		f->min_r = f->min_r * 0.8;
	}
	else if (button == WHEEL_UP)
	{
		f->max_i = f->max_i / 0.8;
		f->min_i = f->min_i / 0.8;
		f->max_r = f->max_r / 0.8;
		f->min_r = f->min_r / 0.8;
	}
	render(f);
	return (0);
}

static void	shift_vert_and_render(t_fractol *f, int shift_pixel)
{
	double	real_height;
	double	pixel_per_real_length;

	real_height = f->max_i - f->min_i;
	pixel_per_real_length = real_height / HEIGHT;
	f->max_i -= pixel_per_real_length * shift_pixel;
	f->min_i -= pixel_per_real_length * shift_pixel;
	render(f);
	return ;
}

static void	shift_horiz_and_render(t_fractol *f, int shift_pixel)
{
	double	real_width;
	double	pixel_per_real_length;

	real_width = f->max_r - f->min_r;
	pixel_per_real_length = real_width / WIDTH;
	f->max_r -= pixel_per_real_length * shift_pixel;
	f->min_r -= pixel_per_real_length * shift_pixel;
	render(f);
	return ;
}

int	key_hook(int keycode, void *param)
{
	t_fractol	*f;
	int			shift_pixel;

	f = (t_fractol *)param;
	if (keycode == ESC)
	{
		end_fractol(f);
		exit(0);
	}
	shift_pixel = MOVEMENT;
	if (keycode == MV_UP)
		shift_vert_and_render(f, shift_pixel);
	else if (keycode == MV_RIGHT)
		shift_horiz_and_render(f, -1 * shift_pixel);
	else if (keycode == MV_DOWN)
		shift_vert_and_render(f, -1 * shift_pixel);
	else if (keycode == MV_LEFT)
		shift_horiz_and_render(f, shift_pixel);
	return (0);
}
