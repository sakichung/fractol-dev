/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:11:02 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:14:00 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	target;

	target = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == target)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	// char *s = "Hello World";
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	char *p = ft_memchr(s, 2 + 256, 3);
// }
