/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:12:17 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:13:28 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	size_t			s_len;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	result = (char *)ft_calloc(sizeof(char), s_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}

// char	my_lower(unsigned int index, char c)
// {
// 	if ('A' <= c && c <= 'Z')
// 		return (c + 'a' - 'A');
// 	return (c);
// }
// #include <stdio.h>
// int main()
// {
// 	char s[] = "ABCDEFG";
// 	char *s2;
// 	s2 = ft_strmapi(s, my_lower);
// 	printf("%s\n", s2);
// 	free(s2);
// 	s2 = ft_strmapi(s, NULL);
// 	printf("%s\n", s2);
// 	free(s2);
// 	s2 = ft_strmapi("", my_lower);
// 	printf("%s\n", s2);
// 	free(s2);
// }
