#include "../wolf.h"

t_list		*remove_list(t_list *list)
{
	t_list *next;

	next = list->next;
	free(list->content);
	list->content = NULL;
	free(list);
	list = NULL;
	return (next);
}

void remove_rubbish(char **words, char *str)
{
	int i;

	i = -1;
	while (words[++i])
	{
		free(words[i]);
		words[i] = NULL;
	}
	free(str);
	str = NULL;
	free(words);
	words = NULL;
}

void fill_line(int *arr, int y, t_list *list, int width, int height)
{
	int i;
	char **words;
	int j;
	char *str;

	i = -1;
	j = y * width - 1;
	str = ft_strnew(list->content_size);
	str = ft_memcpy(str, list->content, list->content_size);
	if (ft_count_words(str, ' ') != width)
		show_error("Each line must be of equal length");
	words = ft_strsplit(str, ' ');
	while (words[++i])
	{
		arr[++j] = ft_atoi(words[i]);
		if (arr[j] < 0)
			show_error("please, no negative numbers in the map");
		if ((y == 0 || y == height - 1 ) && arr[j] == 0)
			show_error("please, make sure the outer walls are without gaps");
		if ((i == 0 || i == width - 1) && arr[j] == 0)
			show_error("please, make sure the outer walls are without gaps");
	}
	remove_rubbish(words, str);
}

void fill_array(int *arr, int width, int height, t_list *head)
{
	int y;

	y = 0;
	while (y < height)
	{
		fill_line(arr, y, head, width, height);
		head = remove_list(head);
		y++;
	}
}

int *make_map(t_list *head, t_glob *g)
{
	int height;
	int width;
	int *arr;

	height = ft_lstlen(head);
	g->height = height;
	width = ft_count_words(head->content, ' ');
	g->width = width;
	if (width == 0)
		show_error("empty file");
	if (width < 3 || height < 3)
		show_error("no room for walking");
	arr = (int *)ft_memalloc(sizeof(int) * width * height);
	fill_array(arr, width, height, head);
	return (arr);
}

int *read_map(int fd, int res, t_glob *g)
{
	char	*line;
	t_list	*list;
	t_list	*cur;
	t_list	*start;

	list = NULL;
	while ((res = (get_next_line(fd, &line)) > 0))
	{
		cur = ft_lstnew(line, (ft_strlen(line) + 1));
		if (list == NULL)
		{
			list = cur;
			start = cur;
		}
		else
		{
			list->next = cur;
			list = list->next;
		}
		free(line);
	}
	if (res == -1 || (res == 0 && list == NULL))
		show_error("the file is empty");
	return (make_map(start, g));	
}

