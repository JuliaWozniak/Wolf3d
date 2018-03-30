/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:09:29 by jwozniak          #+#    #+#             */
/*   Updated: 2017/11/17 13:09:32 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list *curr;

	if (alst == NULL || new == NULL)
		return ;
	curr = *alst;
	if (curr == NULL)
		*alst = new;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}
