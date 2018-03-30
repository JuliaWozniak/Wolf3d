/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:43:38 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/16 13:43:41 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new;
	t_list *temp;
	t_list *curr;

	first = NULL;
	while (lst != NULL && (*f) != NULL)
	{
		temp = (*f)(lst);
		new = ft_lstnew(temp->content, temp->content_size);
		if (!new)
			return (NULL);
		if (!first)
		{
			first = new;
			curr = first;
		}
		else
		{
			curr->next = new;
			curr = curr->next;
		}
		lst = lst->next;
	}
	return (first);
}
