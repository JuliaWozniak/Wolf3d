/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:43:48 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/16 13:43:50 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst == NULL || (*del) == NULL)
		return ;
	while (*alst)
	{
		temp = *alst;
		*alst = temp->next;
		(*del)(temp->content, temp->content_size);
		free(temp);
		temp = NULL;
	}
}
