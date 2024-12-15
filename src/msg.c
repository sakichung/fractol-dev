/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:14:20 by pchung            #+#    #+#             */
/*   Updated: 2024/12/15 23:52:39 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/**
 * help_msg - ヘルプメッセージを表示します。
 */
void help_msg(void)
{
    ft_putstr_fd("usage: ./fractol ", 2);
    ft_putstr_fd("\"fractal_name\" {\"julia\", ", 2);
}

/**
 * error_msg - エラーメッセージとヘルプメッセージを表示します。
 * @msg: 表示するエラーメッセージ。
 */
void error_msg(char *msg)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(msg, 2);
    help_msg();
}