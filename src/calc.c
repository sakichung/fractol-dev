/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:47:04 by pchung            #+#    #+#             */
/*   Updated: 2024/12/13 11:09:02 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * julia - ジュリア集合の反復回数を計算します。
 * @z: 複素数を表す2つのダブルの配列。
 * @c: 定数複素数を表す2つのダブルの配列。
 * @max_iterations: 実行する最大反復回数。
 *
 * 戻り値: zの大きさが2.0を超えるまでの反復回数、
 *         または大きさが2.0を超えない場合はmax_iterations。
 */
int julia(t_complex z, t_complex c, int max_iterations)
{
    int i = 0;

    while (i < max_iterations)
    {
        double tmp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        z.real = tmp;

        if (z.real * z.real + z.imag * z.imag >= 4.0)
            return i;

        i++;
    }

    return max_iterations;
}

/**
 * mandelbrot - マンデルブロ集合の反復回数を計算します。
 * @c: 複素数を表す2つのダブルの配列。
 * @max_iterations: 実行する最大反復回数。
 *
 * 戻り値: zの大きさが2.0を超えるまでの反復回数、
 *         または大きさが2.0を超えない場合はmax_iterations。
 */
int mandelbrot(t_complex c, int max_iterations)
{
    int i = 0;
    t_complex z = {0.0, 0.0}; // zの初期値

    while (i < max_iterations)
    {
        double tmp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2.0 * z.real * z.imag + c.imag;
        z.real = tmp;

        if (z.real * z.real + z.imag * z.imag >= 4.0)
            return i;

        i++;
    }

    return max_iterations;
}
