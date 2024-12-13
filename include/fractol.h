/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:22:05 by pchung            #+#    #+#             */
/*   Updated: 2024/12/13 11:10:58 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
/*-----------------------------------*/
/*	Libraries	*/
/*-----------------------------------*/
#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

/*-----------------------------------*/
/*	Keys Dataes	*/
/*-----------------------------------*/
#include <X11/keysym.h>
#include <X11/X.h>

/*-----------------------------------*/
/*	Default Dimensions*/
/*-----------------------------------*/
/*	Window Size	*/
#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define WIDTH 1280
#define HEIGHT 720
/*	Viewport	*/
#define MANDELBROT 1
#define JULIA 2

/*-----------------------------------*/
/*	Fractal Rendering Settings	*/
/*-----------------------------------*/
// to do dele later(JP)
/*	MiniLibX関連 (mlx, win, img)	*/
/*	画像データ関連 (addr, bits_per_pixel, line_length, endian)	*/
/*	描画範囲関連 (sx, rx, ry)	*/
/*	最大反復回数 (max_iterations)	*/
/*	フラクタル名 (fractal_name)	*/
/*	色相シフト (color_shift)	*/
typedef struct s_fractol
{
	char *name;
	void *mlx;
	void *win;
	void *img;
	char *addr;
	int set;
	int bits_per_pixel;
	int line_length;
	int endian;
	double sx;
	double rx;
	double ry;
	int max_iterations;
	char *fractal_name;
	int color_shift;
} t_fractol;

/*-----------------------------------*/
/*	Functions	*/
/*-----------------------------------*/
/*	msg.c	*/
void help_msg(void);
void error_msg(char *msg);

/*	utils.c	*/
int end_fractol(t_fractol *mlx);

/*	init.c	 */
t_fractol *search_fractal(char *name);
t_fractol *select_fractal(int i);

/*	render.c	*/
void render(t_fractol *f);

/*	calc.c	*/
int julia(double z[2], double c[2], int max_iterations);
int mandelbrot(double c[2], int max_iterations);

#endif