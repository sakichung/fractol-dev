/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:27 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 04:40:10 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

static int	close_windows_hook(void *param)
{
	if (param != NULL)
        end_fractol(param);
	exit(0);
	return (0);
}

int	load_hooks(t_fractol *f)
{
	// t_mlx_meta	*mlx_meta;

	// mlx_meta = &(f->mlx_meta);
	// mlx_key_hook(mlx_meta->win_ptr, key_hook, (void *) f);
	// mlx_mouse_hook(mlx_meta->win_ptr, zoom_hook, (void *) f);
	mlx_hook(f->win, 17, 0, close_windows_hook, (void *) f);
	return (0);
}

// int	zoom_hook(int button, int x, int y, void *param)
// {
// 	t_fractol		*f;

// 	f = (t_fractol *)param;
// 	if (button == WHEEL_DOWN)
// 	{
// 		f->zoom_level = 0.8;
// 		update_real_range(f, x, y);
// 		render_image(f);
// 	}
// 	else if (button == WHEEL_UP)
// 	{
// 		f->zoom_level = 1 / 0.8;
// 		update_real_range(f, x, y);
// 		render_image(f);
// 	}
// 	return (0);
// }

// int	key_hook(int keycode, void *param)
// {
// 	t_fractol	*f;
// 	int				shift_pixel;

// 	f = (t_fractol *)param;
// 	if (keycode == ESC)
// 	{
// 		close_mlx(&(f->mlx_meta));
// 		exit(0);
// 	}
// 	// shift_pixel = f->pixels_per_move;
// 	// if (keycode == MV_UP)
// 	// 	shift_vert_and_render(f, shift_pixel);
// 	// else if (keycode == MV_LEFT)
// 	// 	shift_horiz_and_render(f, -1 * shift_pixel);
// 	// else if (keycode == MV_DOWN)
// 	// 	shift_vert_and_render(f, -1 * shift_pixel);
// 	// else if (keycode == MV_RIGHT)
// 	// 	shift_horiz_and_render(f, shift_pixel);
// 	// return (0);
// }

// static void	shift_vert_and_render(t_fractol *f, int shift_pixel)
// {
// 	double	real_height;
// 	double	pixel_per_real_length;

// 	real_height = f->max_i - f->min_i;
// 	pixel_per_real_length = real_height / f->display_height;
// 	f->max_i -= pixel_per_real_length * shift_pixel;
// 	f->min_i -= pixel_per_real_length * shift_pixel;
// 	render_image(f);
// 	return ;
// }

// static void	shift_horiz_and_render(t_fractol *f, int shift_pixel)
// {
// 	double	real_width;
// 	double	pixel_per_real_length;

// 	real_width = f->max_r - f->min_r;
// 	pixel_per_real_length = real_width / f->display_width;
// 	f->max_r -= pixel_per_real_length * shift_pixel;
// 	f->min_r -= pixel_per_real_length * shift_pixel;
// 	render_image(f);
// 	return ;
// }