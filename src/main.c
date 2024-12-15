/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:21:10 by pchung            #+#    #+#             */
/*   Updated: 2024/12/15 23:39:32 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char **argv)
{
	t_fractol fractol;

	if (argc < 2)
		error_msg("No fractal type provided. Use 1 (Mandelbrot) or 2 (Julia).");

	// MLX������
	fractol.mlx = mlx_init();
	fractol.win = mlx_new_window(fractol.mlx, WIDTH, HEIGHT, "Fractal Viewer");
	fractol.img = mlx_new_image(fractol.mlx, WIDTH, HEIGHT);
	fractol.buf = mlx_get_data_addr(fractol.img, &(int){0}, &(int){0}, &(int){0});

	// �t���N�^����ނ�ݒ�
	int set = atoi(argv[1]); // �����𝮝��Ƃ��ĉ���
	set_fractal_range(&fractol, set);

	// �p���b�g����
	generate_palette(fractol.palette);

	// �t���N�^����`��
	render(&fractol);

	// �C�x���g���[�v
	mlx_loop(fractol.mlx);
	return 0;
}
