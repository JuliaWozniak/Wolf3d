/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:43:55 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/16 13:43:56 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst == NULL || (*del) == NULL || *alst == NULL)
		return ;
	temp = *alst;
	*alst = temp->next;
	(*del)(temp->content, temp->content_size);
	free(temp);
	temp = NULL;
}
