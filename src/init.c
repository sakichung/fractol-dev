/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:49 by pchung            #+#    #+#             */
/*   Updated: 2024/12/13 11:09:06 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


t_fractol *search_fractal(char *name)
{
	int			i;
	t_fractol	*fractol;

	fractol = select_fractal(0);
	i = 0;
	while (fractol[i].name != NULL)
	{
		if (!ft_strncmp(fractol[i].name, str, 5))
			return (&fractol[i]);
		i++;
	}
	return (&fractol[i]);
}

t_fractol *select_fractal(int i){
	static t_fractol fractol[] = {
		{"mandelbrot", NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0},
		{"julia", NULL, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0},
	};
	return (&fractol[i]);
}

void	init(t_fractol *f){
	f->mix = mlx_init();
	if(!f->mlx)	error_msg("error connecting");
	f->win = mlx_new_window(f->mlx,WIDHT,HEIGHT,"Fractol"); //todo:‚±‚±‚Ì–ß‚è’l‚Í‚È‚ÉH
	if(!f->win) error_msf("error createing window");
	
}