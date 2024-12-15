/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:49 by pchung            #+#    #+#             */
/*   Updated: 2024/12/13 11:09:06 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fracto.h"

/**
 * mandelbrot_iterations:
 * �s�N�Z�����}���f���u���W���ɑ����邩�v�Z���A
 * ���U����܂ł̔����񐔂�Ԃ��܂��B
 */
int mandelbrot_iterations(double cr, double ci, int max_iter)
{
    double zr = 0.0; // z�̎���
    double zi = 0.0; // z�̋���
    int iter = 0;

    while (zr * zr + zi * zi <= 4.0 && iter < max_iter)
    {
        double tmp = zr * zr - zi * zi + cr;
        zi = 2.0 * zr * zi + ci;
        zr = tmp;
        iter++;
    }
    return iter;
}

/**
 * set_pixel_color:
 * �w�肳�ꂽ�s�N�Z���ɐF��ݒ肵�܂��B
 */
void set_pixel_color(t_fractol *f, int x, int y, int color)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    int index = (y * WIDTH + x) * 4;
    f->buf[index] = color;           // ��
    f->buf[index + 1] = color >> 8;  // ��
    f->buf[index + 2] = color >> 16; // ��
    f->buf[index + 3] = color >> 24; // �A���t�@
}

/**
 * generate_palette:
 * �J���[�p���b�g�𐶐����܂��B
 */
void generate_palette(int *palette)
{
    for (int i = 0; i < MAX_ITER; i++)
    {
        double t = (double)i / MAX_ITER;
        palette[i] = (int)(9 * (1 - t) * t * t * t * 255) << 16 |        // ��
                     (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 8 |  // ��
                     (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255); // ��
    }
}
