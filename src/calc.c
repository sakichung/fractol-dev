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
int julia(double z[2], double c[2], int max_iterations)
{
    int i = 0;

    while (i < max_iterations)
    {
        double tmp = z[0] * z[0] - z[1] * z[1] + c[0];

        z[1] = 2.0 * z[0] * z[1] + c[1];

        z[0] = tmp;

        if (z[0] * z[0] + z[1] * z[1] >= 4.0)
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
int mandelbrot(double c[2], int max_iterations)
{
    int i = 0;
    double z[2] = {0.0, 0.0};

    while (i < max_iterations)
    {
        double tmp = z[0] * z[0] - z[1] * z[1] + c[0];
        z[1] = 2.0 * z[0] * z[1] + c[1];
        z[0] = tmp;

        if (z[0] * z[0] + z[1] * z[1] >= 4.0)
            return i;

        i++;
    }

    return max_iterations;
}
