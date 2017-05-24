/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 09:57:11 by houssana          #+#    #+#             */
/*   Updated: 2017/05/22 14:53:45 by houssana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

# define PRINT_FUNC(func, is_ft) \
	printf(#func); \
if (is_ft) \
{printf(" : ");} \
else \
{printf("    : ");}

# define TEST_FUNC(func, is_ft, type, ...) \
	PRINT_FUNC(func, is_ft) \
ft_dup(t, argv, argc); \
printf("%" #type, (func)( __VA_ARGS__)); \
printf("\n");

# define TEST(func, type, ...) if (!strcmp(#func, argv[1])) { \
	if (id_test == 0 || id_test == 2) \
	{TEST_FUNC(func, 0, type, __VA_ARGS__)} \
	if (id_test == 1 || id_test == 2) \
	{TEST_FUNC(ft_ ## func, 1, type, __VA_ARGS__)}}

# define VTEST_FUNC(func, is_ft, type, what, ...) \
	PRINT_FUNC(func, is_ft) \
ft_dup(t, argv, argc); \
(func)(__VA_ARGS__); \
printf("%" #type, what); \
printf("\n");

# define VTEST(func, type, what, ...) if (!strcmp(#func, argv[1])) { \
	if (id_test == 0 || id_test == 2) \
	{VTEST_FUNC(func, 0, type, what, __VA_ARGS__)} \
	if (id_test == 1 || id_test == 2) \
	{VTEST_FUNC(ft_ ## func, 1, type, what, __VA_ARGS__)}}

# define SVTEST(func, type, what, ...) if (!strcmp(#func, argv[1])) { \
	VTEST_FUNC(func, 0, type, what, __VA_ARGS__)} \

# define STEST(func, type, ...) if (!strcmp(#func, argv[1])) { \
	TEST_FUNC(func, 0, type, __VA_ARGS__)} \

void	ft_dup(char **t, char **argv, int argc)
{
	argc -= 3;
	t[argc] = 0;
	while (argc--)
		t[argc] = strdup(argv[argc + 3]);
}

void	add_one(char *c)
{
	*c = *c + 1;
}

void	add_one2(unsigned int i, char * s)
{
	s[i] = s[i] + 1;
}

char	add_one3(char c)
{
	return (++c);
}

char	add_one4(unsigned int i, char c)
{
	i++;
	return (++c);
}

t_list	*f(t_list *elem)
{
	char *c;
	c = (char *)elem->content;
	c[0] = 'r';
	return (elem);
}

t_list *		lstmap_f(t_list *m) {
	t_list *	r = ft_lstnew("OK !", 5);
	(void)m;
	return (r);
}


int		main(int argc, char **argv)
{
	int		id_test;
	char	**t;
	char	**tab;

	t = malloc(sizeof(char*) * (argc - 2));
	id_test = atoi(argv[2]);
	TEST(memset, s, t[0], atoi(t[1]), atoi(t[2]))
		VTEST(bzero, s, t[0], t[0], atoi(t[1]));
	TEST(memcpy, s, t[0], t[1], atoi(t[2]));
	TEST(memccpy, s, t[0], t[1], atoi(t[2]), atoi(t[3]));
	VTEST(memccpy, s, t[0], t[0], t[1], atoi(t[2]), atoi(t[3]));
	TEST(memmove, s, t[0], t[1], atoi(t[2]));
	TEST(memchr, s, t[0], atoi(t[1]), atoi(t[2]));
	TEST(memcmp, d, t[0], t[1], atoi(t[2]));
	TEST(strlen, lu, t[0]);
	TEST(strdup, s, t[0]);
	TEST(strcpy, s, t[0], t[1]);
	TEST(strncpy, s, t[0], t[1], atoi(t[2]));
	TEST(strcat, s, t[0], t[1]);
	TEST(strncat, s, t[0], t[1], atoi(t[2]));
	VTEST(strlcat, s, t[0], t[0], t[1], atoi(t[2]));
	TEST(strlcat, lu, t[0], t[1], atoi(t[2]));
	TEST(strchr, s, t[0], atoi(t[1]));
	TEST(strrchr, s, t[0], atoi(t[1]));
	TEST(strstr, s, t[0], t[1]);
	TEST(strnstr, s, t[0], t[1], atoi(t[2]));
	TEST(strcmp, d, t[0], t[1]);
	TEST(strncmp, d, t[0], t[1], atoi(t[2]));
	TEST(atoi, d, t[0]);
	TEST(isalpha, d, atoi(t[0]));
	TEST(isdigit, d, atoi(t[0]));
	TEST(isalnum, d, atoi(t[0]));
	TEST(isascii, d, atoi(t[0]));
	TEST(isprint, d, atoi(t[0]));
	TEST(tolower, d, atoi(t[0]));
	TEST(toupper, d, atoi(t[0]));

	STEST(ft_memalloc, s, atoi(t[0]));
	STEST(ft_intlen_base, d, atoi(t[0]), atoi(t[1]));
	SVTEST(ft_memdel, s, t[0], (void**)&t[0]);
	SVTEST(ft_memdel, s, (void*)&t[0], (void**)&t[0]);
	STEST(ft_strnew, s, atoi(t[0]));
	SVTEST(ft_strdel, s, t[0], &t[0]);
	SVTEST(ft_strclr, s, t[0], t[0]);
	SVTEST(ft_striter, s, t[0], t[0], &add_one);
	SVTEST(ft_striteri, s, t[0], t[0], &add_one2);
	STEST(ft_strmap, s, t[0], &add_one3);
	STEST(ft_strmapi, s, t[0], &add_one4);
	STEST(ft_strequ, d, t[0], t[1]);
	STEST(ft_strnequ, d, t[0], t[1], atoi(t[2]));
	STEST(ft_strsub, s, t[0], atoi(t[1]), atoi(t[2]));
	STEST(ft_strjoin, s, t[0], t[1]);
	STEST(ft_strtrim, s, t[0]);
	if (!strcmp(argv[1], "ft_strsplit"))
	{
		tab = ft_strsplit(argv[3], argv[4][0]);
		while (*(tab++))
			printf("%s", *(tab - 1));
	}
	STEST(ft_itoa, s, atoi(t[0]));
	SVTEST(ft_putchar, s, "", *t[0]);
	SVTEST(ft_putstr, s, "", t[0]);
	SVTEST(ft_putendl, s, "", t[0]);
	SVTEST(ft_putnbr, s, "", atoi(t[0]));
	t_list	*l;
	t_list	*d;

	if (!strcmp(argv[1], "ft_lstmap"))
	{
		while (--argc > 1)
		{
			l = ft_lstnew(argv[argc], 3);
			ft_lstadd(&d, l);	
		}
		l = ft_lstmap(d, &lstmap_f);
		while (d)
		{
			printf("%s\n", d->content);
			d = d->next;
		}
		ft_putchar('\n');
		while (l)
		{
			printf("%s\n", l->content);
			l = l->next;
		}
	}

	if (!strcmp(argv[1], "get_next_line"))
	{
	char	*line;
	int		fd;

			fd = open(argv[2], O_RDONLY);
			while (get_next_line(fd, &line))
			{
				ft_putstr(line);
				ft_putstr("\n");
				free(line);
			}
			close(fd);
	}
	return (0);
}
