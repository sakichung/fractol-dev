/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:21:10 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 08:12:47 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
    t_fractol f;
    int set;

    if (argc < 2)
        error_msg("No fractal type provided. Use 1 (Mandelbrot) or 2 (Julia).");

    set = ft_atoi(argv[1]); 

    if ((set == JULIA && argc != 4 && argc != 2))
        error_msg("Please enter 2 numbers for Julia set OR nothing for default.");

    init(&f);
    set_fractal_range(&f, set, argc, argv);
    load_hooks(&f);
    generate_palette(f.palette);
    render(&f);
    mlx_loop(f.mlx);

    return 0;
}