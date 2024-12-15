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
#define MAX_ITER 100

/*	Viewport	*/
#define MANDELBROT 1
#define JULIA 2

/*-----------------------------------*/
/*	Fractal Rendering Settings	*/
/*-----------------------------------*/
typedef struct s_complex
{
	double real; // 実部
	double imag; // 虚部
} t_complex;

typedef struct s_fractol
{
	void *mlx;
	void *win;
	void *img;
	char *buf;
	int palette[MAX_ITER];
	int set;			 // フラクタルの種類（1 = Mandelbrot, 2 = Julia）
	t_complex julia_c;	 // Julia用の定数
	double min_r, max_r; // 実数軸の範囲
	double min_i, max_i; // 虚数軸の範囲
} t_fractol;

/*-----------------------------------*/
/*	Functions	*/
/*-----------------------------------*/
void set_pixel_color(t_fractol *f, int x, int y, int color);
void error_msg(const char *msg);
int mandelbrot(t_complex c, int max_iterations);
int julia(t_complex z, t_complex c, int max_iterations);
void set_fractal_range(t_fractol *f, int set);
void render_fractal(t_fractol *f);
void render(t_fractol *f);

#endif