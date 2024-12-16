/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchung <pchung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 13:10:47 by pchung            #+#    #+#             */
/*   Updated: 2024/12/16 13:14:04 by pchung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

// int	main(void){
// 	t_list	test1 = {(void *) "abcdefg", NULL};
// 	t_list	*test2 = ft_lstnew((void *) "abcdefg");
// 	free(test2);
// }
