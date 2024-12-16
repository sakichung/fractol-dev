/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:14:20 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:01:57 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_msg(void)
{
	ft_putstr_fd("\nusage: ./fractol ", 2);
	ft_putstr_fd("\"fractal_name\" \"1 OR 2\"", 2);
	ft_putstr_fd("\nyou also can use parameters to adjust Julia set ", 2);
}

void	error_msg(char *msg)
{
	ft_putstr_fd("**ERROR**\n", 2);
	ft_putstr_fd(msg, 2);
	help_msg();
	exit(1);
}

void	check_input(int argc, char **argv, int set)
{
	char	*endptr;

	if ((set != MANDELBROT && set != JULIA) || ft_strlen(argv[1]) != 1)
		error_msg("Wrong parameters");
	if ((set == JULIA && argc != 4) && (set == JULIA && argc != 2))
	{
		error_msg("Julia set parameters : 2digit OR none");
	}
	else if ((argc > 2) && (set == JULIA))
	{
		endptr = NULL;
		ft_atof(argv[2], &endptr);
		if (*endptr != '\0')
			error_msg("Please ONLY use digit to adjust Julia set.");
		ft_atof(argv[3], &endptr);
		if (*endptr != '\0')
			error_msg("Please ONLY use digit to adjust Julia set.");
	}
	else if ((set == MANDELBROT && argc != 2))
		error_msg("No parameters for Mandelbrot set");
}
