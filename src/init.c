/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:44:49 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 07:51:12 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fractol.h"

void init(t_fractol *f){
    // MLXの初期化
    f->mlx = mlx_init();
    f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractal Viewer");
    f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
    f->buf = mlx_get_data_addr(f->img, &(int){0}, &(int){0}, &(int){0});

}