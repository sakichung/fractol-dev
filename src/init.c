/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:49 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:55:11 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->mlx = mlx_init();
	if (f->mlx == NULL)
		error_msg("mlx_init failed.");
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fract-ol");
	if (f->win == NULL)
	{
		end_fractol(f);
		error_msg("mlx_new_window failed");
	}
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (f->img == NULL)
	{
		end_fractol(f);
		error_msg("mlx_new_image failed");
	}
	f->buf = mlx_get_data_addr(f->img, &(int){0}, &(int){0}, &(int){0});
}
