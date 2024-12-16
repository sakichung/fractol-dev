/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:09:22 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:14:24 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*dst;

	i = 0;
	dst = (unsigned char *)s;
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
	return ;
}

// #include <stdio.h>
// int main(){
// 	char str[] = "Hello World";
// 	ft_bzero(str, 10);
// 	printf("%s\n", str);
// }
