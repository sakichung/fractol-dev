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

static int calculate_fractal(t_fractol *f, double pr, double pi)
{
	int nb_iter;

	if (f->set == MANDELBROT)
		nb_iter = mandelbrot(pr, pi);
	else if (f->set == JULIA)
		nb_iter = julia(f, pr, pi);
	return (nb_iter);
}