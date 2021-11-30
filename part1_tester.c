/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:18:18 by charles           #+#    #+#             */
/*   Updated: 2021/11/27 22:37:38 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

void	delay1(float i)
{
	clock_t	start;

	start = clock();
	while((clock() - start) <= i * CLOCKS_PER_SEC)
		;
}

void	part1_tester(int details_mode, int ft_start, int ft_end)
{
	int	fonction = 0;
	int	test;
	int	i;
	char	ft_name[100];

	printf("\n#########################################\n");
	printf("##############    PART 1   ##############\n");
	printf("############ LIBC FONCTIONS  ############\n");
	printf("#########################################\n\n");

	/*
	 ** Fonction 1 : ft_memset
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "   ", "", "         ", NULL};
		int	c[] = {'a', 't', 'q', '\0'};
		size_t	n[] = {3, 3, 1, 5};

		char	*str;
		char	*strft;

		i = 0;
		test = 1;
		strcpy(ft_name, "void *ft_memset(void *s, int c, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			str = strdup(strs[i]);
			strft = strdup(strs[i]);
			if (memcmp(memset(str, c[i], n[i]), ft_memset(strft, c[i], n[i]), n[i]) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	c  :%c#\n", c[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s  :%s#\n", strs[i]);
				printf("	c  :%c#\n", c[i]);
				printf("	n  : %ld\n", n[i]);
				printf("	Your return :%s#\n", strft);
				printf("	Good return :%s#\n", str);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 2 : ft_bzero
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "   ", "", NULL};
		size_t	n[] = {3, 3, 1};

		char	*str;
		char	*strft;

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_bzero(void *s, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			str = strdup(strs[i]);
			strft = strdup(strs[i]);
			bzero(str, n[i]);
			ft_bzero(strft, n[i]);
			if (memcmp(str, strft, n[i]) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{	
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s  :%s#\n", strs[i]);
				printf("	n  : %ld\n", n[i]);
				printf("	Your return :%s#\n", strft);
				printf("	Good return :%s#\n", str);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 3 : ft_memcpy
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*dests[] = {"     ", "     ", "     ", "test\0\0test", NULL};
		char	*srcs[] = {"test", "test2", "", "testtest", NULL};
		size_t	n[] = {3, 3, 1, 3, 8};

		char	*dest;
		char	*destft;
		char	*src;

		i = 0;
		test = 1;
		strcpy(ft_name, "void *ft_memcpy(void *dest, const void *src, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (dests[i])
		{
			dest = strdup(dests[i]);
			destft = strdup(dests[i]);
			src = strdup(srcs[i]);
			memcpy(dest, src, n[i]);
			ft_memcpy(destft, src, n[i]);
			if (memcmp(dest, destft, n[i]) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	dest  :%s#\n", dests[i]);
					printf("	src  :%s#\n", srcs[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your return :%s#\n", destft);
					printf("	Good return :%s#\n", dest);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	dest  :%s#\n", dests[i]);
				printf("	src  :%s#\n", srcs[i]);
				printf("	n  : %ld\n", n[i]);
				printf("	Your return :%s#\n", destft);
				printf("	Good return :%s#\n", dest);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}

	/*
	 ** Fonction 4 : ft_memmove
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*dests[] = {"aaaaaaa", "aaaaaaa", "aaaaaaa", "test\0\0test", "aaaa"};
		char	*srcs[] = {"testt", "test2", "", "testtest", "test", NULL};
		size_t	n[] = {3, 3, 1, 8, 0};

		char	*dest;
		char	*destft;
		char	*src;

		i = 0;
		test = 1;
		strcpy(ft_name, "void *ft_memmove(void *dest, const void *src, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (srcs[i])
		{
			dest = strdup(dests[i]);
			destft = strdup(dests[i]);
			src = strdup(srcs[i]);
			memmove(dest, src, n[i]);
			ft_memmove(destft, src, n[i]);
			if (memcmp(dest, destft, strlen(destft)) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	dest  :%s#\n", dests[i]);
					printf("	src   :%s#\n", srcs[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your return :%s#\n", destft);
					printf("	Good return :%s#\n", dest);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	dest  :%s#\n", dests[i]);
				printf("	src   :%s#\n", srcs[i]);
				printf("	n  : %ld\n", n[i]);
				printf("	Your return :%s#\n", destft);
				printf("	Good return :%s#\n", dest);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 5 : ft_memchr
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "test", "test", "test", "test", "test", "test", NULL};
		int	c[] = {'e', 's', 't', 'z', 't', 'e', 't'};
		size_t	n[] = {4, 4, 4, 4, 1, 0, 0};

		char	*str;
		char	*strft;

		i = 0;
		test = 1;
		strcpy(ft_name, "void *ft_memchr(void *s, int c, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			str = memchr(strdup(strs[i]), c[i], n[i]);
			strft = ft_memchr(strdup(strs[i]), c[i], n[i]);
			if (i == 3 || i == 5 || i == 6)
			{
				if (str == strft)
				{
					printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
					if (details_mode == 1)
					{
						printf("	\e[1;32mSuccess details :\e[0m\n");
						printf("	s  :%s#\n", strs[i]);
						printf("	c  :%c#\n", c[i]);
						printf("	n  : %ld\n", n[i]);
						printf("	Your return :%s#\n", strft);
						printf("	Good return :%s#\n", str);
					}
				}
				else
				{
					printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
					printf("	\e[1;31mFail details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	c  :%c#\n", c[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else if (strcmp(str, strft) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	c  :%c#\n", c[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s  :%s#\n", strs[i]);
				printf("	c  :%c#\n", c[i]);
				printf("	n  : %ld\n", n[i]);
				printf("	Your return :%s#\n", strft);
				printf("	Good return :%s#\n", str);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 6 : ft_memcmp
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*dests[] = {"test", "test ", "test", "test", "", "Test", "test", "t\200", NULL};
		char	*srcs[] = {"test", "test", "test ", "", "test", "test", "tast", "t\0"};
		size_t	n[] = {4, 5, 4, 4, 1, 4, 0, 2};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_memcmp(const void *s1, const void *s2, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (dests[i])
		{
			if (memcmp(dests[i], srcs[i], n[i]) == ft_memcmp(dests[i], srcs[i], n[i])
					|| memcmp(dests[i], srcs[i], n[i]) > 0 && ft_memcmp(dests[i], srcs[i], n[i]) > 0
					|| memcmp(dests[i], srcs[i], n[i]) < 0 && ft_memcmp(dests[i], srcs[i], n[i]) < 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	dest :%s#\n", dests[i]);
					printf("	src  :%s#\n", srcs[i]);
					printf("	n    : %ld\n", n[i]);
					printf("	Your output : %d\n", ft_memcmp(dests[i], srcs[i], n[i]));
					printf("	Good output : %d\n", memcmp(dests[i], srcs[i], n[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	dest :%s#\n", dests[i]);
				printf("	src  :%s#\n", srcs[i]);
				printf("	n    : %ld\n", n[i]);
				printf("	Your output : %d\n", ft_memcmp(dests[i], srcs[i], n[i]));
				printf("	Good output : %d\n", memcmp(dests[i], srcs[i], n[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 7 : ft_strlen
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "test ", "", "test\ttest", "\n\t\f\r", "    ", "1", NULL};

		i = 0;
		test = 1;
		strcpy(ft_name, "size_t ft_strlen(const char *s)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			if (strlen(strs[i]) == ft_strlen(strs[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	str :%s#\n", strs[i]);
					printf("	Your output : %ld\n", ft_strlen(strs[i]));
					printf("	Good output : %ld\n", strlen(strs[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	str :%s#\n", strs[i]);
				printf("	Your output : %ld\n", ft_strlen(strs[i]));
				printf("	Good output : %ld\n", strlen(strs[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 8 : ft_strdup
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "test ", "", "Test", NULL};

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strdup(const char *s)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			if (strcmp(strdup(strs[i]), ft_strdup(strs[i])) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	str :%s#\n", strs[i]);
					printf("	Your output :%s#\n", ft_strdup(strs[i]));
					printf("	Good output :%s#\n", strdup(strs[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	str :%s#\n", strs[i]);
				printf("	Your output :%s#\n", ft_strdup(strs[i]));
				printf("	Good output :%s#\n", strdup(strs[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 9 : ft_strlcpy
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*dests[] = {"aaaaaaa", "aa\0aaaaaa", "aaaaaaa", "aaaaaaa"};
		char	*srcs[] = {"test", "test2", "", "test", NULL};
		size_t	n[] = {3, 3, 1, 0};

		char	*dest;
		char	*destft;
		char	*src;
		size_t	ft_return;
		size_t	g_return;

		i = 0;
		test = 1;
		strcpy(ft_name, "size_t ft_strlcpy(char *dest, const char *src, size_t size)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (srcs[i])
		{
			dest = strdup(dests[i]);
			destft = strdup(dests[i]);
			src = strdup(srcs[i]);
			g_return = strlcpy(dest, src, n[i]);
			ft_return = ft_strlcpy(destft, src, n[i]);
			if (strcmp(dest, destft) == 0 && g_return == ft_return)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	dest  :%s#\n", dests[i]);
					printf("	src  :%s#\n", srcs[i]);
					printf("	Your dst :%s#\n", destft);
					printf("	Good dst :%s#\n", dest);
					printf("	Your return : %ld\n", ft_return);
					printf("	Good return : %ld\n", g_return);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	dest  :%s#\n", dests[i]);
				printf("	src  :%s#\n", srcs[i]);
				printf("	Your return :%s#\n", destft);
				printf("	Good return :%s#\n", dest);
				printf("	Your return : %ld\n", ft_return);
				printf("	Good return : %ld\n", g_return);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 10 : ft_strlcat
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*dests[] = {"aaaaaaa", "aa\0aaaaaa", "aaaaaaa", "rrrrrr\0\0\0\0\0a\0\0\0"};
		char	*srcs[] = {"test", "test2", "", "lorem", NULL};
		size_t	n[] = {2, 5, 1, 15};

		char	*dest;
		char	*destft;
		char	*src;
		size_t	sizelibc;
		size_t	sizeft;

		i = 0;
		test = 1;
		strcpy(ft_name, "size_t ft_strlcat(char *dest, const char *src, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (srcs[i])
		{
			dest = strdup(dests[i]);
			destft = strdup(dests[i]);
			src = strdup(srcs[i]);
			sizelibc = strlcat(dest, src, n[i]);
			sizeft = ft_strlcat(destft, src, n[i]);
			if (strcmp(dest, destft) == 0 && sizelibc == sizeft)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	dest  :%s#\n", dests[i]);
					printf("	src  :%s#\n", srcs[i]);
					printf("	n    : %ld\n", n[i]);
					printf("	Your dest   :%s#\n", destft);
					printf("	Your return :%ld#\n", sizeft);
					printf("	Good dest   :%s#\n", dest);
					printf("	Good return :%ld#\n", sizelibc);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	dest  :%s#\n", dests[i]);
				printf("	src  :%s#\n", srcs[i]);
				printf("	n    : %ld\n", n[i]);
				printf("	Your return :%s#\n", destft);
				printf("	Your return :%ld#\n", sizeft);
				printf("	Good return :%s#\n", dest);
				printf("	Good return :%ld#\n", sizelibc);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 11 : ft_strchr
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "test", "test", "test", "test", "", NULL};
		int	c[] = {'e', 's', 't', 'z', '\0', '\0'};

		char	*str;
		char	*strft;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strchr(const char *s, int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			str = strchr(strdup(strs[i]), c[i]);
			strft = ft_strchr(strdup(strs[i]), c[i]);
			if (test == 4)
			{

				if (str == strft)
				{
					printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
					if (details_mode == 1)
					{
						printf("	\e[1;32mSuccess details :\e[0m\n");
						printf("	s  :%s#\n", strs[i]);
						printf("	c  :%c#\n", c[i]);
						printf("	Your return :%s#\n", strft);
						printf("	Good return :%s#\n", str);
					}
				}
				else
				{
					printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
					printf("	\e[1;31mFail details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	c  :%c#\n", c[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else if (strcmp(str, strft) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	c  :%c#\n", c[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s  :%s#\n", strs[i]);
				printf("	c  :%c#\n", c[i]);
				printf("	Your return :%s#\n", strft);
				printf("	Good return :%s#\n", str);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 12 : ft_strrchr
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"testest", "tesst", "test", "test", "testtest", "test", "", NULL};
		int	c[] = {'e', 's', 't', 'z', 'e', '\0', '\0'};

		char	*str;
		char	*strft;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strrchr(const char *s, int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			str = strrchr(strs[i], c[i]);
			strft = ft_strrchr(strs[i], c[i]);
			if (test == 4)
			{
				if (str == strft)
				{
					printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
					if (details_mode == 1)
					{
						printf("	\e[1;32mSuccess details :\e[0m\n");
						printf("	s  :%s#\n", strs[i]);
						printf("	c  :%c#\n", c[i]);
						printf("	Your return :%s#\n", strft);
						printf("	Good return :%s#\n", str);
					}
				}
				else
				{
					printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
					printf("	\e[1;31mFail details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	c  :%c#\n", c[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else if (strcmp(str, strft) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s  :%s#\n", strs[i]);
					printf("	c  :%c#\n", c[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s  :%s#\n", strs[i]);
				printf("	c  :%c#\n", c[i]);
				printf("	Your return :%s#\n", strft);
				printf("	Good return :%s#\n", str);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 13 : ft_strnstr
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		const char	*haystacks[] = {"test", "test", "test", "test", "test", "test", "test", NULL};
		const char	*needles[] = {"st", "es", "te", "", "tee", "te", "\0", NULL};
		size_t		len[] = {2, 4, 4, 4, 4, 4, 5};

		const char	*str;
		const char	*strft;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strnstr(const char *haystack, const char *needle, size_t len)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (haystacks[i])
		{
			str = strnstr(haystacks[i], needles[i], len[i]);
			strft = strnstr(haystacks[i], needles[i], len[i]);
			if (strcmp(str == NULL ? "ok" : str, strft == NULL ? "ok" : strft) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	str     :%s#\n", haystacks[i]);
					printf("	tofind  :%s#\n", needles[i]);
					printf("	len     : %ld\n", len[i]);
					printf("	Your return :%s#\n", strft);
					printf("	Good return :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	str     :%s#\n", haystacks[i]);
				printf("	tofind  :%s#\n", needles[i]);
				printf("	len     : %ld\n", len[i]);
				printf("	Your return :%s#\n", strft);
				printf("	Good return :%s#\n", str);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 14 : ft_strncmp
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*dests[] = {"test", "test ", "test", "test", "", "Test", "test", "tast", "test\200", NULL};
		char	*srcs[] = {"test", "test", "test ", "", "test", "test", "tast", "test", "test\0", NULL};
		size_t	n[] = {4, 5, 4, 1, 0, 4, 2, 1, 6};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_strncmp(const char *s1, const char *s2, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (dests[i])
		{
			if (strncmp(dests[i], srcs[i], n[i]) == ft_strncmp(dests[i], srcs[i], n[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s1 :%s#\n", dests[i]);
					printf("	s2 :%s#\n", srcs[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your output : %d\n", ft_strncmp(dests[i], srcs[i], n[i]));
					printf("	Good output : %d\n", strncmp(dests[i], srcs[i], n[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s1 :%s#\n", dests[i]);
				printf("	s2 :%s#\n", srcs[i]);
				printf("	n  : %ld\n", n[i]);
				printf("	Your output : %d\n", ft_strncmp(dests[i], srcs[i], n[i]));
				printf("	Good output : %d\n", strncmp(dests[i], srcs[i], n[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 15 : ft_atoi
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		const char	*ascii[] = {"  +123abc", "   -123abc", "   --123abc", "  -+123abc", 
			"   +-123abc", "\t\n\r123", "  -2147483648", "    +2147483647", "  -0abc", NULL};

		int	toi;
		int	toift;

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_atoi(const char *nptr)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			toi = atoi(ascii[i]);
			toift = ft_atoi(ascii[i]);
			if (toi == toift)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	str :%s#\n", ascii[i]);
					printf("	Your output : %d\n", toift);
					printf("	Good output : %d\n", toi);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	str :%s#\n", ascii[i]);
				printf("	Your output : %d\n", toift);
				printf("	Good output : %d\n", toi);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 16 : ft_isalpha
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	ascii[] = {'a', 'A', 'z', 'Z', '1', '@', '[', '_', '{', '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_isalpha(int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			if ((isalpha(ascii[i]) != 0 && ft_isalpha(ascii[i]) != 0) || 
					(isalpha(ascii[i]) == ft_isalpha(ascii[i])))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	c :%c#\n", ascii[i]);
					printf("	Your output : %d\n", ft_isalpha(ascii[i]));
					printf("	Good output : %d\n", isalpha(ascii[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	c :%c#\n", ascii[i]);
				printf("	Your output : %d\n", ft_isalpha(ascii[i]));
				printf("	Good output : %d\n", isalpha(ascii[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 17 : ft_isdigit
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	ascii[] = {'a', 'A', 'z', 'Z', '1', '@', '[', '_', '{', '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_isdigit(int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			if ((isdigit(ascii[i]) != 0 && ft_isdigit(ascii[i]) != 0) || 
					(isdigit(ascii[i]) == ft_isdigit(ascii[i])))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	c :%c#\n", ascii[i]);
					printf("	Your output : %d\n", ft_isdigit(ascii[i]));
					printf("	Good output : %d\n", isdigit(ascii[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	c :%c#\n", ascii[i]);
				printf("	Your output : %d\n", ft_isdigit(ascii[i]));
				printf("	Good output : %d\n", isdigit(ascii[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 18 : ft_isalnum
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	ascii[] = {'a', 'A', 'z', 'Z', '1', '@', '[', '_', '{', '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_isalnum(int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			if ((isalnum(ascii[i]) != 0 && ft_isalnum(ascii[i]) != 0) || 
					(isalnum(ascii[i]) == ft_isalnum(ascii[i])))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	c :%c#\n", ascii[i]);
					printf("	Your output : %d\n", ft_isalnum(ascii[i]));
					printf("	Good output : %d\n", isalnum(ascii[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	c :%c#\n", ascii[i]);
				printf("	Your output : %d\n", ft_isalnum(ascii[i]));
				printf("	Good output : %d\n", isalnum(ascii[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 19 : ft_isascii
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	ascii[] = {'a', 'A', 'z', 'Z', '1', '@', '[', '_', '{', 466, 2048, 127, '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_isascii(int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			if ((isascii(ascii[i]) != 0 && ft_isascii(ascii[i]) != 0) || 
					(isascii(ascii[i]) == ft_isascii(ascii[i])))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	c :%c#\n", ascii[i]);
					printf("	Your output : %d\n", ft_isascii(ascii[i]));
					printf("	Good output : %d\n", isascii(ascii[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	c :%c#\n", ascii[i]);
				printf("	Your output : %d\n", ft_isascii(ascii[i]));
				printf("	Good output : %d\n", isascii(ascii[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 20 : ft_isprint
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	ascii[] = {'a', 20, 127, 'Z', '1', '@', 31, '_', '{', 466, 2048, 127, '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_isprint(int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			if ((isprint(ascii[i]) != 0 && ft_isprint(ascii[i]) != 0) || 
					(isprint(ascii[i]) == ft_isprint(ascii[i])))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	c :%c#\n", ascii[i]);
					printf("	Your output : %d\n", ft_isprint(ascii[i]));
					printf("	Good output : %d\n", isprint(ascii[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	c :%c#\n", ascii[i]);
				printf("	Your output : %d\n", ft_isprint(ascii[i]));
				printf("	Good output : %d\n", isprint(ascii[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 21 : ft_toupper
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	ascii[] = {'a', 20, 'z', 'Z', 'm', '@', 31, '_', '{', '9', '1', 127, '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_toupper(int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			if (toupper(ascii[i]) == ft_toupper(ascii[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	c :%c#\n", ascii[i]);
					printf("	Your output :%c#\n", ft_toupper(ascii[i]));
					printf("	Good output :%c#\n", toupper(ascii[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	c :%c#\n", ascii[i]);
				printf("	Your output :%c#\n", ft_toupper(ascii[i]));
				printf("	Good output :%c#\n", toupper(ascii[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}


	/*
	 ** Fonction 22 : ft_tolower
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	ascii[] = {'A', 20, 'z', 'Z', 'M', '@', 31, '_', '{', '9', '1', 127, '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_tolower(int c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (ascii[i])
		{
			if (tolower(ascii[i]) == ft_tolower(ascii[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	c :%c#\n", ascii[i]);
					printf("	Your output :%c#\n", ft_tolower(ascii[i]));
					printf("	Good output :%c#\n", tolower(ascii[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	c :%c#\n", ascii[i]);
				printf("	Your output :%c#\n", ft_tolower(ascii[i]));
				printf("	Good output :%c#\n", tolower(ascii[i]));
			}
			i++;
			test++;
		}
		delay1(0.33);
	}

	/*
	 ** Fonction 23 : ft_calloc
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		size_t	nmemb[] = {2, 5, 10, 15, 1, 1, 23};
		size_t	size[] = {3, 25, 41, 57, 856, 857, 73, 666};

		unsigned int	k;
		unsigned int	j;
		char	*str_ft;
		char	*str_g;

		i = 0;
		test = 1;
		strcpy(ft_name, "void *ft_calloc(size_t nmemb, size_t size)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (size[i] != 666)
		{
			k = 0;
			j = 0;
			str_ft = (char *)ft_calloc(nmemb[i], size[i]);
			str_g = (char *)calloc(nmemb[i], size[i]);
			if (str_g)
			{
				while (str_g[k] == '\0')
					k++;
			}
			if (str_ft)
			{
				while (str_ft[j] == '\0')
					j++;
			}
			if (/*k == j*/1)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	nmemb : %ld\n", nmemb[i]);
					printf("	size : %ld\n", size[i]);
					printf("	nmemb * size : %ld\n", size[i] * nmemb[i]);
					printf("	Your calloc : %d\n", j);
					printf("	True calloc : %d\n", k);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	nmemb : %ld\n", nmemb[i]);
				printf("	size : %ld\n", size[i]);
				printf("	nmemb * size : %ld\n", size[i] * nmemb[i]);
				printf("	Your calloc : %d\n", j);
				printf("	True calloc : %d\n", k);
			}
			i++;
			test++;
		}
		delay1(0.33);
	}
	printf("\n");
}
