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
 * �t���N�^���̔����񐔂��v�Z���܂��B
 * @f: �t���N�^���\���́B
 * @pr: ���f���̎����B
 * @pi: ���f���̋����B
 *
 * �߂�l: �����񐔁B
 */
static int calculate_fractal(t_fractol *f, double pr, double pi)
{
	int nb_iter;

	if (f->set == MANDELBROT) // MANDELBROT
		nb_iter = mandelbrot((t_complex){pr, pi}, MAX_ITER);
	else if (f->set == JULIA) // JULIA
		nb_iter = julia((t_complex){pr, pi}, f->julia_c, MAX_ITER);
	else
		nb_iter = 0; // �s���ȃZ�b�g�̏ꍇ
	return nb_iter;
}

/**
 * render_fractal:
 * �t���N�^����`�悷��֐����Ăяo���܂��B
 * @f: �t���N�^���\���́B
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
 * �t���N�^����ނɉ����ĕ`��͈͂�ݒ肵�܂��B
 * @f: �t���N�^���\���́B
 * @set: �t���N�^���̎�ށi1 = MANDELBROT, 2 = JULIA�j�B
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
		f->julia_c = (t_complex){.real = -0.7, .imag = 0.27015}; // �Œ�l
	}
	else
	{
		error_msg("Invalid fractal set value");
	}
}

/**
 * render:
 * �t���N�^����`�悵�ăE�B���h�E�ɕ\�����܂��B
 * @f: �t���N�^���\���́B
 */
void render(t_fractol *f)
{
	// �t���N�^���`��
	render_fractal(f);

	// �摜���E�B���h�E�ɕ\��
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
