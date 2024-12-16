/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:47:04 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 10:55:42 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_complex z, t_complex c, int max_iterations)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < max_iterations)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp;
		if (z.real * z.real + z.imag * z.imag >= 4.0)
			return (i);
		i++;
	}
	return (max_iterations);
}

int	mandelbrot(t_complex c, int max_iterations)
{
	int			i;
	double		tmp;
	t_complex	z;

	z.imag = 0.0;
	z.real = 0.0;
	i = 0;
	while (i < max_iterations)
	{
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2.0 * z.real * z.imag + c.imag;
		z.real = tmp;
		if (z.real * z.real + z.imag * z.imag >= 4.0)
			return (i);
		i++;
	}
	return (max_iterations);
}
