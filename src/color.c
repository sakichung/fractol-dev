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

#include "fractol.h"

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
 * 青 → 黄色 → 白色のグラデーションを生成します。
 * @palette: カラーパレットを格納する配列。
 */
#include <math.h> // pow関数を使う

#include <math.h> // pow関数を使う

void generate_palette(int *palette)
{
    for (int i = 0; i < MAX_ITER; i++)
    {
        double t = (double)i / (MAX_ITER - 1); // 正規化 (0.0 ~ 1.0)

        // t を非線形に調整（初期の青を明るくする）
        t = pow(t, 0.5); // 0.5: 平方根を使って t を強調

        int red, green, blue;

        if (t < 0.4) // 青 → 黄色
        {
            red   = (int)(2 * t * 255);             // 赤成分: 徐々に増加
            green = (int)(2 * t * 255);             // 緑成分: 徐々に増加
            blue  = 255 - (int)(2 * t * 255);       // 青成分: 徐々に減少
        }
        else // 黄色 → 赤色
        {
            red   = 255;                            // 赤成分: 最大値
            green = (int)((1 - (t - 0.5) * 2) * 255); // 緑成分: 徐々に減少
            blue  = 0;                              // 青成分: 0（完全に赤方向）
        }

        palette[i] = (red << 16) | (green << 8) | blue; // RGB値を結合
    }
}



