/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:55:55 by pchung            #+#    #+#             */
/*   Updated: 2024/12/13 10:56:52 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * calculate_fractal:
 * フラクタルの反復回数を計算します。
 * @f: フラクタル構造体。
 * @pr: 複素数の実部。
 * @pi: 複素数の虚部。
 *
 * 戻り値: 反復回数。
 */
static int calculate_fractal(t_fractol *f, double pr, double pi)
{
	int nb_iter;

	if (f->set == MANDELBROT) // MANDELBROT
		nb_iter = mandelbrot((t_complex){pr, pi}, MAX_ITER);
	else if (f->set == JULIA) // JULIA
		nb_iter = julia((t_complex){pr, pi}, f->julia_c, MAX_ITER);
	else
		nb_iter = 0; // 不明なセットの場合
	return nb_iter;
}

/**
 * render_fractal:
 * フラクタルを描画する関数を呼び出します。
 * @f: フラクタル構造体。
 */
void render_fractal(t_fractol *f)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			double cr = f->min_r + x * (f->max_r - f->min_r) / WIDTH;
			double ci = f->min_i + y * (f->max_i - f->min_i) / HEIGHT;

			int iter = calculate_fractal(f, cr, ci);
			int color = f->palette[iter % MAX_ITER];
			set_pixel_color(f, x, y, color);
		}
	}
}

/**
 * set_fractal_range:
 * フラクタル種類に応じて描画範囲を設定します。
 * @f: フラクタル構造体。
 * @set: フラクタルの種類（1 = MANDELBROT, 2 = JULIA）。
 */
void set_fractal_range(t_fractol *f, int set)
{
	f->set = set;
	if (set == 1) // MANDELBROT
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = 1.5;
	}
	else if (set == 2) // JULIA
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = 2.0;
		f->julia_c = (t_complex){.real = -0.7, .imag = 0.27015}; // 固定値
	}
	else
	{
		error_msg("Invalid fractal set value");
	}
}

/**
 * render:
 * フラクタルを描画してウィンドウに表示します。
 * @f: フラクタル構造体。
 */
void render(t_fractol *f)
{
	// フラクタル描画
	render_fractal(f);

	// 画像をウィンドウに表示
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
