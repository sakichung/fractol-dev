/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:21:10 by pchung            #+#    #+#             */
/*   Updated: 2024/12/15 23:39:32 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractol fractol;

	if (argc < 2)
		error_msg("No fractal type provided. Use 1 (Mandelbrot) or 2 (Julia).");

	// MLX揄期化
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fractal Viewer");
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	fractol.buf = mlx_get_data_addr(fractol.img, &(int){0}, &(int){0}, &(int){0});

	// フラクタル種類を昊定
	int set = atoi(argv[1]); // 引摧を攬摧として解釈
	set_fractal_range(&fractol, set);

	// パレット攜擣
	generate_palette(fractol.palette);

	// フラクタルを描画
	render(&fractol);

	// イベントル拏プ
	mlx_loop(fractol.mlx);
	return 0;
}
