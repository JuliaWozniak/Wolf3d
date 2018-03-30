/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <jwozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 09:33:22 by jwozniak          #+#    #+#             */
/*   Updated: 2018/01/20 10:30:01 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl	*find_fd(int fd, t_gnl **buf, t_gnl *cur)
{
	if (*buf)
	{
		cur = *buf;
		if (cur->fd == fd)
			return (cur);
		while (cur->next)
		{
			cur = cur->next;
			if (cur->fd == fd)
				return (cur);
		}
		cur->next = (t_gnl *)malloc(sizeof(t_gnl));
		cur->next->fd = fd;
		cur->next->f = 1;
		cur->next->rem = NULL;
		cur->next->next = NULL;
		return (cur->next);
	}
	*buf = (t_gnl *)malloc(sizeof(t_gnl));
	(*buf)->fd = fd;
	(*buf)->f = 1;
	(*buf)->rem = NULL;
	(*buf)->next = NULL;
	return (*buf);
}

void	ft_copy_to_n(char **line, t_gnl *bb)
{
	char	*her;
	int		i;

	i = 0;
	while (bb->rem[i] != '\n' && bb->rem[i])
		i++;
	*line = ft_strsub(bb->rem, 0, i);
	if (bb->rem[i] == '\0')
	{
		free(bb->rem);
		bb->rem = NULL;
		return ;
	}
	her = bb->rem;
	bb->rem = ft_strdup(ft_strchr(bb->rem, '\n') + 1);
	free(her);
	if (ft_strlen(bb->rem) == 0)
	{
		free(bb->rem);
		bb->rem = NULL;
	}
}

int		ft_read(t_gnl *bb)
{
	int		n;
	char	buff[BUFF_SIZE + 1];
	char	*data;

	n = read(bb->fd, buff, BUFF_SIZE);
	if (n <= 0)
		return (n);
	buff[n] = '\0';
	if (!bb->rem)
		bb->rem = ft_strdup("");
	data = bb->rem;
	bb->rem = ft_strjoin(bb->rem, buff);
	free(data);
	return (n);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*buf;
	t_gnl			*bb;
	int				n;

	n = 1;
	if (!line || fd < 0)
		return (-1);
	bb = find_fd(fd, &buf, NULL);
	if (bb->f == 0 || bb->f == -1)
		return (bb->f);
	while (!ft_strchr(bb->rem, '\n'))
	{
		n = ft_read(bb);
		if (n <= 0)
			break ;
	}
	if (n == -1 || (bb->rem == NULL && n == 0))
	{
		bb->f = n;
		return (n);
	}
	ft_copy_to_n(line, bb);
	return (1);
}
