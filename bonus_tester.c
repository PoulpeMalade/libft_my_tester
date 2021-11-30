/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:27:56 by charles           #+#    #+#             */
/*   Updated: 2021/11/28 15:18:16 by cberganz         ###   ########.fr       */
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

void	delay3(float i)
{
	clock_t	start;

	start = clock();
	while((clock() - start) <= i * CLOCKS_PER_SEC)
		;
}

static void	ft_del(void *ptr)
{
	if (ptr)
	{
		memset(ptr, 0, 1);
	}
}

static void	ft_f(void *data)
{
	char	*str;
	int	i;

	i = 0;
	str = (char *)data;
	while (str[i])
	{
		if (islower(str[i]))
			str[i] -= 32;
		i++;
	}
}

static void	*ft_fstar(void *data)
{
	char	*str;
	int	i;

	i = 0;
	str = malloc(strlen((char *)data) * sizeof(char));
	strcpy(str, (char *)data);
	while (str[i])
	{
		if (islower(str[i]))
			str[i] -= 32;
		i++;
	}
	return ((void *)str);
}

void	bonus_tester(int details_mode, int ft_start, int ft_end)
{
	int	fonction = 0;
	int	test;
	int	i;
	char	ft_name[100];

	printf("\n#########################################\n");
	printf("##############    PART 3   ##############\n");
	printf("########### BONUS  FONCTIONS  ###########\n");
	printf("#########################################\n\n");


	/*
	 ** Fonction 1 : ft_lstnew
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*content[] = {"test", "Ceci est un test", "", "0"};
		t_list	*nlst;

		i = 0;
		test = 1;
		strcpy(ft_name, "t_list *ft_lstnew(void const *content)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (strcmp(content[i], "0") != 0)
		{
			nlst = ft_lstnew(content[i]);
			if (memcmp(content[i], (char *)nlst->content, strlen(content[i]) + 1) == 0
				&& nlst->next == NULL)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	content      :%s#\n", content[i]);
					printf("	Your return->content :%s#\n", (char *)nlst->content);
					printf("	Your return->next ptr : %p\n", nlst->next);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	content      :%s#\n", content[i]);
				printf("	Your return->content :%s#\n", (char *)nlst->content);
				printf("	Your return->next ptr : %p\n", nlst->next);
			}
			i++;
			test++;
		}
		delay3(0.33);
	}


	/*
	 ** Fonction 2 : ft_lstadd_front
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*content[] = {"test", "Ceci est un test", "", NULL};
		t_list	*alst;
		t_list	*new;

		i = 0;
		test = 1;
		alst = NULL;
		strcpy(ft_name, "void ft_lstadd_front(t_list **alst, t_list *new)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (content[i])
		{
			new = ft_lstnew(content[i]);
			ft_lstadd_front(&alst, new);
			if (memcmp(content[i], (char *)alst->content, strlen(content[i]) + 1) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	content      :%s#\n", content[i]);
					printf("	Your return->content :%s#\n", (char *)alst->content);
					printf("	Your return->next ptr : %p\n", alst->next);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	content      :%s#\n", content[i]);
				printf("	Your return->content :%s#\n", (char *)alst->content);
				printf("	Your return->next ptr : %p\n", alst->next);
			}
			i++;
			test++;
		}
		delay3(0.33);
	}


	/*
	 ** Fonction 3 : ft_lstsize
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*content[] = {"test", "Ceci est un test", "", NULL};
		t_list	*alst;
		t_list	*new;
		int	size;

		i = 0;
		test = 1;
		alst = NULL;
		strcpy(ft_name, "int ft_lstsize(t_list *lst)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (content[i])
		{
			new = ft_lstnew(content[i]);
			ft_lstadd_front(&alst, new);
			size = ft_lstsize(alst);
			if (size = i + 1)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	True size : %d\n", i + 1);
					printf("	Your size : %d\n", size);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	True size : %d\n", i + 1);
				printf("	Your size : %d\n", size);
			}
			i++;
			test++;
		}
		delay3(0.33);
	}


	/*
	 ** Fonction 4 : ft_lstlast
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*content[] = {"test1", "test2", "test3", NULL};
		t_list	*alst;
		t_list	*new;
		char	*last;

		i = 0;
		test = 1;
		alst = NULL;
		strcpy(ft_name, "t_list *ft_lstlast(t_list *lst)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (content[i])
		{
			new = ft_lstnew(content[i]);
			ft_lstadd_front(&alst, new);\
			last = (char *)ft_lstlast(alst)->content;
			if (strcmp(last, "test1") == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	True last :%s#\n", "test1");
					printf("	Your last :%s#\n", last);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	True last :%s#\n", "test1");
				printf("	Your last :%s#\n", last);
			}
			i++;
			test++;
		}
		delay3(0.33);
	}


	/*
	 ** Fonction 5 : ft_lstadd_back
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*content[] = {"test", "Ceci est un test", "", NULL};
		t_list	*alst;
		t_list	*new;
		char	*last;

		i = 0;
		test = 1;
		alst = NULL;
		strcpy(ft_name, "void ft_lstadd_back(t_list **alst, t_list *new)");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (content[i])
		{
			new = ft_lstnew(content[i]);
			ft_lstadd_back(&alst, new);
			last = (char *)ft_lstlast(alst)->content;
			if (memcmp(content[i], last, strlen(content[i]) + 1) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	content :%s#\n", content[i]);
					printf("	Your last->content :%s#\n", last);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	content :%s#\n", content[i]);
				printf("	Your last->content :%s#\n", last);
			}
			i++;
			test++;
		}
		delay3(0.33);
	}


	/*
	 ** Fonction 6 : ft_lstiter
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*content[] = {"test", "Ceci est un test", "", NULL};
		char	*returns[] = {"TEST", "CECI EST UN TEST", "", NULL};
		char	*tmp;
		t_list	*alst;
		t_list	*new;
		t_list	*last;

		i = 0;
		test = 1;
		alst = NULL;
		strcpy(ft_name, "void ft_lstiter(t_list *lst, void (*f)(void *))");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (content[i])
		{
			tmp = strdup(content[i]);
			new = ft_lstnew(tmp);
			ft_lstadd_back(&alst, new);
			i++;
		}
		i = 0;
		ft_lstiter(alst, ft_f);
		while (alst->next != NULL)
		{
			if (strcmp(returns[i], (char *)alst->content) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	content :%s#\n", content[i]);
					printf("	Good lst->content :%s#\n", returns[i]);
					printf("	Your lst->content :%s#\n", (char *)alst->content);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	content :%s#\n", content[i]);
				printf("	Good lst->content :%s#\n", returns[i]);
				printf("	Your lst->content :%s#\n", (char *)alst->content);
			}
			alst = alst->next;
			i++;
			test++;
		}
		delay3(0.33);
	}


	/*
	 ** Fonction 7 : ft_lstmap
	 */
	fonction++;
	if (ft_start <= fonction && fonction <= ft_end)
	{
		char	*content[] = {"test", "Ceci est un test", "", NULL};
		char	*returns[] = {"TEST", "CECI EST UN TEST", "", NULL};
		char	*tmp;
		t_list	*alst;
		t_list	*new;
		t_list	*last;
		t_list	*nlst;

		i = 0;
		test = 1;
		alst = NULL;
		strcpy(ft_name, "t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))");
		printf("## Fonction %d : %s\n", fonction, ft_name);
		while (content[i])
		{
			tmp = strdup(content[i]);
			new = ft_lstnew(tmp);
			ft_lstadd_back(&alst, new);
			i++;
		}
		i = 0;
		nlst = ft_lstmap(alst, ft_fstar, ft_del); // a modifier
		while (nlst->next != NULL)
		{
			if (strcmp(returns[i], (char *)nlst->content) == 0 && strcmp(content[i], (char *)alst->content) == 0)
			{
				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
				if (details_mode == 1)
				{
					printf("	\e[1;32mSuccess details :\e[0m\n");
					printf("	content :%s#\n", content[i]);
					printf("	Good lst->content :%s#\n", returns[i]);
					printf("	old lst->content  :%s#\n", (char *)alst->content);
					printf("	Your lst->content :%s#\n", (char *)nlst->content);
				}
			}
			else
			{
				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
				printf("	\e[1;31mFail details :\e[0m\n");
				printf("	content :%s#\n", content[i]);
				printf("	Good lst->content :%s#\n", returns[i]);
				printf("	old lst->content  :%s#\n", (char *)alst->content);
				printf("	Your lst->content :%s#\n", (char *)nlst->content);
			}
			nlst = nlst->next;
			alst = alst->next;
			i++;
			test++;
		}
		delay3(0.33);
	}


//	/*
//	 ** Fonction 2 : ft_lstdelone
//	 */
//	fonction++;
//	if (ft_start <= fonction && fonction <= ft_end)
//	{
//		char		lst1_content[] = "test";
//		char		lst2_content[] = "Ceci est un test";
//		char		lst3_content[] = "";
//		t_list		*lst1;
//		t_list		*lst2;
//		t_list		*lst3;
//		lst1 = ft_lstnew((void *)lst1_content);
//		lst2 = ft_lstnew((void *)lst2_content);
//		lst3 = ft_lstnew((void *)lst3_content);
//		lst1->next = lst2;
//		lst2->next = lst3;
//		lst3->next = NULL;
//		t_list	*lst[] = {lst1, lst2, lst3, NULL};
//		t_list		*tmp_next_before;
//		char		*tmp_content_before;
//		t_list		*tmp_next_after;
//		char		*tmp_content_after;
//
//		test = 1;
//		i = 0;
//		strcpy(ft_name, "void ft_lstdelone(t_list *lst, void (*del)(void*))");
//		printf("## Fonction %d : %s\n", fonction, ft_name);
//		while (lst[i] != NULL)
//		{	
//			tmp_content_before = (char *)(lst[i])->content;
//			tmp_next_before = (lst[i])->next;
//			ft_lstdelone(lst[i], ft_del);
//			tmp_content_after = (char *)(lst[i])->content;
//			tmp_next_after = (lst[i])->next;
//			if (lst[i]->content == NULL)
//			{
//				printf("   Test %d ---> \e[1;32m[OK]\e[0m\n", test);
//				if (details_mode == 1)
//				{
//					printf("	\e[1;32mSuccess details :\e[0m\n");
//					printf("	content      :%s#\n", tmp_content_before);
//					printf("	next :%p#\n", tmp_next_before);
//					printf("	Your lst->content :%s#\n", tmp_content_after);
//					printf("	Your lst->next ptr :%p#\n", tmp_next_after);
//				}
//			}
//			else
//			{
//				printf("   Test %d ---> \e[1;31m[KO]\e[0m\n", test);
//				printf("	\e[1;31mFail details :\e[0m\n");
//				printf("	content      :%s#\n", tmp_content_before);
//				printf("	next :%p#\n", tmp_next_before);
//				printf("	Your lst->content :%s#\n", tmp_content_after);
//				printf("	Your lst->next ptr :%p#\n", tmp_next_after);
//			}
//			test++;
//			i++;
//		}
//		delay3(0.33);
//	}
	printf("\n");
}
