/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:55:52 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 15:05:54 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	end_fractol(t_fractol *f)
{
	if (f->mlx == NULL)
		return (0);
	if (f->img != NULL)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win != NULL)
		mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	return (0);
}

static int	strip_space_sign(const char *str, int *sign)
{
	int	i;

	*sign = 1;
	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str, char **endptr)
{
	double	nb;
	int		sign;
	double	div;

	nb = 0;
	div = 0.1;
	sign = 1;
	if (str == NULL)
		return (0);
	*endptr = str;
	*endptr += strip_space_sign(*endptr, &sign);
	while (**endptr && ft_isdigit(**endptr) && **endptr != '.')
	{
		nb = (nb * 10.0) + ((int)(**endptr) - (int) '0');
		(*endptr)++;
	}
	if ((**endptr) == '.')
		(*endptr)++;
	while (**endptr && ft_isdigit(**endptr))
	{
		nb = nb + ((**endptr - '0') * div);
		div *= 0.1;
		(*endptr)++;
	}
	return (nb * sign);
}
