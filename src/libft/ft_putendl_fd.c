/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:29 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:13:48 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	if (write(fd, s, len) == -1)
		return ;
	ft_putchar_fd('\n', fd);
	return ;
}

// int main()
// {
// 	ft_putendl_fd("abcdefg", STDOUT_FILENO);
// 	ft_putendl_fd("abcdefg", STDERR_FILENO);
// }
