/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:21:10 by pchung            #+#    #+#             */
/*   Updated: 2024/12/13 10:38:38 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractol fractol;

	if (argc < 2)
		error_msg("No fractal type provided. Use 1 (Mandelbrot) or 2 (Julia).");

	// MLX初期化
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fractal Viewer");
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	fractol.buf = mlx_get_data_addr(fractol.img, &(int){0}, &(int){0}, &(int){0});

	// フラクタル種類を設定
	int set = atoi(argv[1]); // 引数を整数として解釈
	set_fractal_range(&fractol, set);

	// パレット生成
	generate_palette(fractol.palette);

	// フラクタルを描画
	render(&fractol);

	// イベントループ
	mlx_loop(fractol.mlx);

	return 0;
}
