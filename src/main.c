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

int	main(int argc, char **argv)
{
	t_fractol	fractal;

	if (argc < 2)
		error_msg("No fractal name provided");
	if (!ft_strncmp(argv[1], "--help", 4))
		help_msg();
	fractal = search_fractal(argv[1]);
	if (fractal->name == NULL)
		error_msg("Wrong fractal name");

	core = new_core("Fract-ol");
	core->ctx->fractal = fractal;
	reset_viewport(core);
	render(core);
	init_loop(core);
	return (0);
}