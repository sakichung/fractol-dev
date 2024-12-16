/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:25 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:13:50 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return ;
	return ;
}

// int main()
// {
// 	ft_putchar_fd('c', STDOUT_FILENO);
// 	ft_putchar_fd('c', STDERR_FILENO);
// }
