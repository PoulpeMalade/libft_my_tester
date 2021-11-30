/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:34:15 by charles           #+#    #+#             */
/*   Updated: 2021/11/28 13:02:54 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

/*
** Usefull fonctions
*/

void	delay2(float i)
{
	clock_t	start;

	start = clock();
	while((clock() - start) <= i * CLOCKS_PER_SEC)
		;
}

static void to_upper(char *s)
{
	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
}

static void to_upper2(unsigned int i, char *s)
{
	if (*s >= 'a' && *s <= 'z')
		*s -= 32;
}

static char to_upper3(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

static char to_upper4(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

static void printchar(unsigned char theChar) {

    switch (theChar) {

        case '\n':
            printf("\\n");
            break;
        case '\b':
            printf("\\b");
            break;
        case '\t':
            printf("\\t");
            break;
        case '\v':
            printf("\\v");
            break;
        default:
            if ((theChar < 0x20) || (theChar > 0x7f)) {
                printf("\\%03o", (unsigned char)theChar);
            } else {
                printf("%c", theChar);
            }
        break;
   }
}

static void printer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printchar((unsigned char)str[i]);
		i++;
	}
}

static int	ft_arrlen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	part2_tester(int details_mode, int ft_start, int ft_end)
{
	int	fonction = 0;
	int	test;
	int	i;
	char	ft_name[100];


	printf("\n#########################################\n");
	printf("##############    PART 2   ##############\n");
	printf("####### COMPLEMENTARY  FONCTIONS  #######\n");
	printf("#########################################\n\n");


	/*
	 ** Fonction 1 : ft_substr
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char		*strs[] = {"Ceci est un test", "test", "", "test", "Ceci est un test", NULL};
		char		*strsok[] = {"est un", "est", "", "", ""};
		unsigned int	start[] = {5, 1, 0, 0, 400};
		size_t		len[] = {6, 3, 1, 0, 20};

		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_substr(char const *s, unsigned int start, size_t len)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			str = ft_substr(strs[i], start[i], len[i]);
			if (strcmp(str, strsok[i]) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s     :%s#\n", strs[i]);
					printf("	start : %d\n", start[i]);
					printf("	len   : %ld\n", len[i]);
					printf("	Your output :%s#\n", str);
					printf("	Good output :%s#\n", strsok[i]);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s :%s#\n", strs[i]);
				printf("	start : %d\n", start[i]);
				printf("	len   : %ld\n", len[i]);
				printf("	Your output :%s#\n", str);
				printf("	Good output :%s#\n", strsok[i]);
			}
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	/*
	 ** Fonction 2 : ft_strjoin
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char		*s1s[] = {"Ceci est", "test", "", "\0", NULL};
		char		*s2s[] = {" un test", "Test", "", "\0", NULL};
		char		*strsok[] = {"Ceci est un test", "testTest", "", ""};

		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strjoin(char const *s1, char const *s2)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s1s[i])
		{
			str = ft_strjoin(s1s[i], s2s[i]);
			if (strcmp(str, strsok[i]) == 0 && str != (char *)&s1s[i] && str != (char *)&s2s[i])
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s1     :%s#\n", s1s[i]);
					printf("	s2     :%s#\n", s2s[i]);
					printf("	Your output :%s#\n", str);
					printf("	Good output :%s#\n", strsok[i]);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s1     :%s#\n", s1s[i]);
				printf("	s2     :%s#\n", s2s[i]);
				printf("	Your output :%s#\n", str);
				printf("	Good output :%s#\n", strsok[i]);
				if (str == (char *)&s1s[i] || str == (char *)&s2s[i])
					printf("Your fonction does not return a new string\n");
			}
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	/*
	 ** Fonction 3 : ft_strtrim
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char		*s1s[] = {"test", "test", "     ", "   Ceci est un test    ", "\ntest\n", "\ttest\t", "\t \n test\n \n\n",
						 "\n\t\b\v test \b\v\n \t   ", "  \t \t \n   \n\n\n\t", NULL};
		char		*strsok[] = {"test", "e", "", "Ceci est un test", "test", "test", "test", "\b\v test \b\v", "", NULL};
		char		*set[] = {" ", "ts", " ", "\n\t ", "\n\t ", "\n\t ", "\n\t ", "\n\t ", " \n\t", NULL};

		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strtrim(char const *s, char const *set)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s1s[i])
		{
			str = ft_strtrim(s1s[i], set[i]);
			if (strcmp(str, strsok[i]) == 0 && str != (char *)&s1s[i])
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s           :");
					printer(s1s[i]);
					printf("#\n	set         :");
					printer(set[i]);
					printf("#\n	Your output :");
					printer(str);
					printf("#\n	Good output :");
					printer(strsok[i]);
					printf("#\n");
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s           :");
				printer(s1s[i]);
				printf("#\n	set         :");
				printer(set[i]);
				printf("#\n	Your output :");
				printer(str);
				printf("#\n	Good output :");
				printer(strsok[i]);
				printf("#\n");
				if (str == (char *)&s1s[i])
					printf("Your fonction does not return a new string\n");

			}
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	/*
	 ** Fonction 4 : ft_split
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char		*s[] = {"Ceci est un test", "&Ceci&est&un&&&test&&", "---Ceci---est---un---test---",
					 "-Ceci---est-un-test---", "        ", "", NULL};
		char		sep[] = {'-', '&', '-', '-', ' ', 'z'};
		char		*strok1[] = {"Ceci est un test", NULL};
		char		*strok2[] = {"Ceci", "est", "un", "test", NULL};
		char		*strok3[] = {"Ceci", "est", "un", "test", NULL};
		char		*strok4[] = {"Ceci", "est", "un", "test", NULL};
		char		*strok5[] = {NULL};
		char		*strok6[] = {NULL};
		char		**strsok[] = {strok1, strok2, strok3, strok4, strok5, strok6};

		char	**str;
		int	j;
		int	result;

		i = 0;
		test = 1;
		strcpy(ft_name, "char **ft_split(char const *s, char c)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s[i])
		{
			j = 0;
			result = 1;
			str = ft_split(s[i], sep[i]);
			while (str[j])
			{
				if (strcmp(str[j], strsok[i][j]) != 0)
					result = 0;
				j++;
			}
			if (result == 1 && j == ft_arrlen(strsok[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s     :%s#\n", s[i]);
					printf("	c     :%c#\n", sep[i]);
					printf("	Your output : {");
					while (*str)
					{
						printf("\"%s\", ", *str);
						str++;
					}
					printf("NULL}\n");
					printf("	Good output : {");
					while (*strsok[i])
					{
						printf("\"%s\", ", *strsok[i]);	
						strsok[i]++;
					}	
					printf("NULL}\n");
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	s     :%s#\n", s[i]);
				printf("	c     :%c#\n", sep[i]);
				printf("	Your output : {");
				while (*str)
				{
					printf("\"%s\", ", *str);
					str++;
				}
				printf("NULL}\n");
				printf("	Good output : {");
				while (*strsok[i])
				{
					printf("\"%s\", ", *strsok[i]);	
					strsok[i]++;
				}	
				printf("NULL}\n");
			}
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	/*
	 ** Fonction 5 : ft_itoa
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int		n[] = {123, -123, 0, 2147483647, -2147483648, 1, -1};
		char		*s[] = {"123", "-123", "0", "2147483647", "-2147483648", "1", "-1", NULL};

		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_itoa(int n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s[i])
		{
			str = ft_itoa(n[i]);
			if (strcmp(str, s[i]) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	int         :%d\n", n[i]);
					printf("	Your output :%s#\n", str);
					printf("	Good output :%s#\n", s[i]);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	int         :%d\n", n[i]);
				printf("	Your output :%s#\n", str);
				printf("	Good output :%s#\n", s[i]);
			}
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	/*
	 ** Fonction 6 : ft_strmapi
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "", "testesttesttest", NULL};

		int	j;
		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strmapi(const char *s, char (*f)(unsigned int, char))");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			j = 0;
			str = ft_strmapi(strs[i], to_upper4);
			while (str[j])
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					j++;
				else
					break;
			}
			if (j == strlen(strs[i]) && str != (char *)&strs[i])
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	Input  :%s#\n", strs[i]);
					printf("	Your output :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	Input  :%s#\n", strs[i]);
				printf("	Your output :%s#\n", str);
				if (str == (char *)&strs[i])
					printf("Your fonction does not return a new string\n");
			}
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	
	/*
	 ** Fonction 7 : ft_striteri
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "", "testesttesttest", NULL};
		char	*strsok[] = {"TEST", "", "TESTESTTESTTEST"};

		int	j;
		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_striteri(char *s, void (*f)(unsigned int, char *))");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			j = 0;
			str = strdup(strs[i]);
			ft_striteri(str, to_upper2);
			while (j < strlen(strs[i]))
			{
				if (str[j] >= 'A' && str[j] <= 'Z')
					j++;
				else
					break;
			}
			if (j == strlen(strs[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	Input  :%s#\n", strs[i]);
					printf("	Your output :%s#\n", str);
					printf("	Good output :%s#\n", strsok[i]);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	Input  :%s#\n", strs[i]);
				printf("	Your output :%s#\n", str);
				printf("	Good output :%s#\n", strsok[i]);
			}
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	
	/*
	 ** Fonction 8 : ft_putchar_fd
	*/
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char		c[] = {'a', '1', '-', ' ', '\0'};

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_putchar_fd(char c, int fd)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (c[i] != '\0')
		{
			printf("   Test %d ---> \e[1;36m[TO CHECK]\e[0m\n", test);
			write(1, "	Your output :", 14);
			ft_putchar_fd(c[i], 1);
			printf("#\n	Good output :%c#\n", c[i]);
			i++;
			test++;
		}
		delay2(0.33);
	}


	/*
	 ** Fonction 9 : ft_putstr_fd
	*/
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char		*s[] = {"test", "Ceci est un test", "\ttest", "", "test\0test", NULL};

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_putstr_fd(char const *s, int fd)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s[i])
		{
			printf("   Test %d ---> \e[1;36m[TO CHECK]\e[0m\n", test);
			write(1, "	Your output :", 14);
			ft_putstr_fd(s[i], 1);
			printf("#\n	Good output :%s#\n", s[i]);
			i++;
			test++;
		}
		delay2(0.33);
	}

	
	/*
	 ** Fonction 10 : ft_putendl_fd
	*/
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char		*s[] = {"test", "Ceci est un test", "\ttest", "", NULL};

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_putendl_fd(char const *s, int fd)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s[i])
		{
			printf("   Test %d ---> \e[1;36m[TO CHECK]\e[0m\n", test);
			write(1, "	Your output :", 14);
			ft_putendl_fd(s[i], 1);
			printf("#\n	Good output :%s\n#\n", s[i]);
			i++;
			test++;
		}
		delay2(0.33);
	}


	/*
	 ** Fonction 11 : ft_putnbr_fd
	*/
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		int	n[] = {0, -0, 1, -1, 123, -123, 2147483647, -2147483648, 666};

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_putnbr_fd(int n, int fd)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (n[i] != 666)
		{
			printf("   Test %d ---> \e[1;36m[TO CHECK]\e[0m\n", test);
			write(1, "	Your output :", 14);
			ft_putnbr_fd(n[i], 1);
			printf("#\n	Good output :%d#\n", n[i]);
			i++;
			test++;
		}
		delay2(0.33);
	}
	
	
	/*
	 ** Fonction 8 : ft_strmap
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "", "testesttesttest", NULL};

		int	j;
		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strmap(const char *s, char (*f)(char))");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			j = 0;
			str = ft_strmap(strs[i], to_upper3);
			while (str[j])
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					j++;
				else
					break;
			}
			if (j == strlen(strs[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	Input  :%s#\n", strs[i]);
					printf("	Your output :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	Input  :%s#\n", strs[i]);
				printf("	Your output :%s#\n", str);
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/
	
	/*
	 ** Fonction 10 : ft_strequ
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*s1s[] = {"test", "test ", "test", "test", "", "Test", "test", NULL};
		char	*s2s[] = {"test", "test", "test ", "", "test", "test", "tast"};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_strequ(const char *s1, const char *s2)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s1s[i])
		{
			if ((strcmp(s1s[i], s2s[i]) == 0 && ft_strequ(s1s[i], s2s[i]) == 1)
				|| (strcmp(s1s[i], s2s[i]) != 0 && ft_strequ(s1s[i], s2s[i]) == 0))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s1 :%s#\n", s1s[i]);
					printf("	s2 :%s#\n", s2s[i]);
					printf("	Your output : %d\n", ft_strequ(s1s[i], s2s[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	dest :%s#\n", s1s[i]);
				printf("	src  :%s#\n", s2s[i]);
				printf("	Your output : %d\n", ft_strequ(s1s[i], s2s[i]));
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/


	/*
	 ** Fonction 11 : ft_strnequ
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*s1s[] = {"test", "test ", "test", "test", "", "Test", "test", NULL};
		char	*s2s[] = {"test", "test", "test ", "", "test", "test", "tast"};
		size_t	n[] = {3, 4, 5, 4, 4, 0, 2};

		i = 0;
		test = 1;
		strcpy(ft_name, "int ft_strnequ(const char *s1, const char *s2, size_t n)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (s1s[i])
		{
			if ((strncmp(s1s[i], s2s[i], n[i]) == 0 && ft_strnequ(s1s[i], s2s[i], n[i]) == 1)
				|| (strncmp(s1s[i], s2s[i], n[i]) != 0 && ft_strnequ(s1s[i], s2s[i], n[i]) == 0))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	s1 :%s#\n", s1s[i]);
					printf("	s2 :%s#\n", s2s[i]);
					printf("	n  : %ld\n", n[i]);
					printf("	Your output : %d\n", ft_strnequ(s1s[i], s2s[i], n[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	dest :%s#\n", s1s[i]);
				printf("	src  :%s#\n", s2s[i]);
				printf("	n  : %ld\n", n[i]);
				printf("	Your output : %d\n", ft_strnequ(s1s[i], s2s[i], n[i]));
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/

	/*
	 ** Fonction 1 : ft_memalloc
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		size_t	size[] = {3, 25, 41, 57, 73, 40, 256, 240, 239, 10, 666};

		int	j;
		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "void *ft_memalloc(size_t size)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (size[i] != 666)
		{
			j = 0;
			str = ft_memalloc(size[i]);
			if (str)
			{
				while (str[j] == '\0')
					j++;
			}
			if (j + 1 >= size[i] || !str)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	size : %ld\n", size[i]);
					printf("	Your size : %d\n", j);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	size : %ld\n", size[i]);
				printf("	Your size : %d\n", j);
			}
			i++;
			test++;
 		delay2(0.1);
		}
		delay2(0.33);
	}
	*/

	
	/*
	 ** Fonction 2 : ft_memdel
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test1", "test2", "test3", NULL};
		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_memdel(void **ap)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		
		while (strs[i])
		{
			char	*str3;
			char	**ptr = &str3;
			void	**p = (void **)ptr;
			str3 = malloc(strlen(strs[i]) + 1 * sizeof(char));
			if (!str3)
			{
				printf("Malloc error on test %d.\n", test);
				break;
			}
			strcpy(str3, strs[i]);
			ft_memdel(p);
			if (*p == NULL && str3 == NULL)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	Your pointer :%p#\n", *p);
					printf("	Your str     :%s#\n", str3);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	Your pointer :%p#\n", *p);
				printf("	Your str     :%s#\n", str3);
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/


	/*
	 ** Fonction 3 : ft_strnew
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		size_t	size[] = {3, 25, 41, 57, 73, 40, 256, 240, 239, 10, 666};

		int	j;
		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "char *ft_strnew(size_t size)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (size[i] != 666)
		{
			j = 0;
			str = ft_strnew(size[i]);
			if (str)
			{
				while (str[j] == '\0')
					j++;
			}
			if (j + 1 >= size[i] || !str)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	size : %ld\n", size[i]);
					printf("	Your size : %d\n", j);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	size : %ld\n", size[i]);
				printf("	Your size : %d\n", j);
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/


	/*
	 ** Fonction 4 : ft_strdel
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test1", "test2", "test3", NULL};
		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_strdel(void **as)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		
		while (strs[i])
		{
			char	*str3;
			char	**ptr = &str3;
			str3 = malloc(strlen(strs[i]) + 1 * sizeof(char));
			if (!str3)
			{
				printf("Malloc error on test %d.\n", test);
				break;
			}
			strcpy(str3, strs[i]);
			ft_strdel(ptr);
			if (*ptr == NULL && str3 == NULL)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	Your pointer :%p#\n", *ptr);
					printf("	Your str     :%s#\n", str3);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	Your pointer :%p#\n", *ptr);
				printf("	Your str     :%s#\n", str3);
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/

	
	/*
	 ** Fonction 5 : ft_strclr
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "", "testesttesttest", NULL};

		int	j;
		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_strclr(char *s)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			j = 0;
			str = strdup(strs[i]);
			ft_strclr(str);
			while (j < strlen(strs[i]))
			{
				if (str[i] == '\0')
					j++;
				else
					break;
			}
			if (j == strlen(strs[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	input  :%s#\n", strs[i]);
					printf("	size cleared  : %d\n", j);
					printf("	size to clear : %ld\n", strlen(strs[i]));
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	input  :%s#\n", strs[i]);
				printf("	size cleared  : %d\n", j);
				printf("	size to clear : %ld\n", strlen(strs[i]));
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/


	/*
	 ** Fonction 6 : ft_striter
	 
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*strs[] = {"test", "", "testesttesttest", NULL};

		int	j;
		char	*str;

		i = 0;
		test = 1;
		strcpy(ft_name, "void ft_striter(char *s, void (*f)(char *))");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strs[i])
		{
			j = 0;
			str = strdup(strs[i]);
			ft_striter(str, to_upper);
			while (j < strlen(strs[i]))
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					j++;
				else
					break;
			}
			if (j == strlen(strs[i]))
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	Input  :%s#\n", strs[i]);
					printf("	Your output :%s#\n", str);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	Input  :%s#\n", strs[i]);
				printf("	Your output :%s#\n", str);
			}
			i++;
			test++;
      		delay2(0.1);
		}
		delay2(0.33);
	}
	*/
	printf("\n");
}
