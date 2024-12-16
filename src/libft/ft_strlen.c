/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:12:12 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:13:30 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}

// #include <string.h>
// #include <stdio.h>
// int main(){
// 	int a = (int) ft_strlen("Hello");
// 	printf("%d\n", a);
// 	// a = (int) strlen(NULL); // Error
// }
