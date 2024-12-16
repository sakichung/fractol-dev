/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:38 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:13:45 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	if (write(fd, s, len) == -1)
		return ;
	return ;
}

// int main()
// {
// 	ft_putstr_fd("abcdefg\n", STDOUT_FILENO);
// 	ft_putstr_fd("abcdefg\n", STDERR_FILENO);
// }
