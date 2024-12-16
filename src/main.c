/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:21:10 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 12:03:16 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	load_hooks(t_fractol *f);

int	main(int argc, char **argv)
{
	t_fractol	f;
	int			set;

	if (argc < 2)
		error_msg("No fractal type provided.\nUse 1(Mandelbrot) or 2(Julia).");
	set = ft_atoi(argv[1]);
	check_input(argc, argv, set);
	init(&f);
	set_fractal_range(&f, set, argc, argv);
	load_hooks(&f);
	generate_palette(f.palette);
	render(&f);
	mlx_loop(f.mlx);
	return (0);
}

static int	load_hooks(t_fractol *f)
{
	mlx_key_hook(f->win, key_hook, (void *)f);
	mlx_mouse_hook(f->win, zoom_hook, (void *)f);
	mlx_hook(f->win, 17, 0, close_windows_hook, (void *)f);
	return (0);
}
