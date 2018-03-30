/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwozniak <jwozniak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:37:01 by jwozniak          #+#    #+#             */
/*   Updated: 2018/01/20 11:14:29 by jwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# define MAX		9223372036854775807U
# define MIN 		9223372036854775808U
# define OUT 		0
# define IN 		1
# define BUFF_SIZE 100

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char			*rem;
	int				fd;
	int				f;
	struct s_gnl	*next;
}					t_gnl;

int					ft_atoi(const char *str);
void				ft_bzero (void *ptr, size_t num);
int					ft_count_words(char const *s, char c);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
char				*ft_itoa(int n);

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstlen(t_list *head);

void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset (void *ptr, int value, size_t num);
void				*ft_memmove(void *dest, const void *src, size_t num);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);

void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char const *s, int fd);

char				*ft_strcat(char *str1, const char *str2);
char				*ft_strchr (const char *str, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);

void				ft_strdel(char **as);
char				*ft_strdup(const char *str);
int					ft_strequ(char const *s1, char const *s2);

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);

size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char(*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));

char				*ft_strncat(char *str1, const char *str2, size_t len);

int					ft_strncmp(const char *s1, const char *s2, size_t num);
char				*ft_strncpy (char *dest, const char *src, size_t num);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, const char *find, size_t len);

char				*ft_strrchr (const char *str, int c);
void				ft_strrev(char **str);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
float				ft_float_01(float f);
int					ft_count_digits(long int i);
int					get_next_line(int fd, char **line);

#endif
