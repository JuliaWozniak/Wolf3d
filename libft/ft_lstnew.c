/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:27:29 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/15 17:27:41 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *temp;

	temp = (t_list*)malloc(sizeof(t_list));
	if (temp)
	{
		if (content == NULL)
		{
			temp->content = NULL;
			temp->content_size = 0;
		}
		else
		{
			if ((temp->content = (void *)malloc(content_size)) == NULL)
			{
				free(temp);
				temp = NULL;
				return (NULL);
			}
			ft_memcpy(temp->content, content, content_size);
			temp->content_size = content_size;
		}
		temp->next = NULL;
	}
	return (temp);
}
