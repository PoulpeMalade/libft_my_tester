/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cberganz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:28:15 by cberganz          #+#    #+#             */
/*   Updated: 2021/11/27 17:56:23 by cberganz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <bsd/string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

void	part1_tester(int details_mode, int ft_start, int ft_end);
void	part2_tester(int details_mode, int ft_start, int ft_end);
void	bonus_tester(int details_mode, int ft_start, int ft_end);

int	main(int argc, char *argv[])
{
	int	details_mode = 0;
	int	part = 0;
	int	ft_start = 1;
	int	ft_end = 50;

	if (argc > 5)
	{
		write(1, "Too much arguments !\n", 21);
		return (0);
	}
	if (argc == 1)
	{	
		part1_tester(details_mode, 1, 50);
		part2_tester(details_mode, 1, 50);
		bonus_tester(details_mode, 1, 50);
		return (0);
	}
	if (argc >= 2)
	{
		if (atoi(argv[1]) == 1)
			details_mode = 1;
		else if (atoi(argv[1]) == 0)
			details_mode = 0;
		else
		{
			write(1, "Your details mode is incorrect, please enter 0 or 1 !\n", 54);
			return (0);
		}
		if (argc == 2)
		{
			part1_tester(details_mode, 1, 50);
			part2_tester(details_mode, 1, 50);
			bonus_tester(details_mode, 1, 50);
		}
	}
	if (argc >= 3)
	{
		if (atoi(argv[2]) >= 1 && atoi(argv[2]) <= 3)
		{
			part = atoi(argv[2]);
			if (argc == 3)
			{
				if (atoi(argv[2]) == 1)
					part1_tester(details_mode, 1, 50);
				else if (atoi(argv[2]) == 2)
					part2_tester(details_mode, 1, 50);
				else if(atoi(argv[2]) == 3)
					bonus_tester(details_mode, 1, 50);
				else
				{
					write(1, "Your part number is incorrect, please enter a number between 1 and 3 !\n", 71);
					return (0);
				}
			}
		}
		else
		{
			write(1, "The part number is incorrect !\n", 31);
			return (0);
		}
	}
	if (argc >= 4)
	{
		ft_start = atoi(argv[3]);
		if (argc == 4)
		{
			if (atoi(argv[2]) == 1)
				part1_tester(details_mode, ft_start, 50);
			else if (atoi(argv[2]) == 2)
				part2_tester(details_mode, ft_start, 50);
			else if(atoi(argv[2]) == 3)
				bonus_tester(details_mode, ft_start, 50);
			else
			{
				write(1, "Your part number is incorrect, please enter a number between 1 and 3 !\n", 71);
				return (0);
			}
		}

	}
	if (argc == 5)
	{
		ft_end = atoi(argv[4]);
		if (argc == 5)
		{
			if (atoi(argv[2]) == 1)
				part1_tester(details_mode, ft_start, ft_end);
			else if (atoi(argv[2]) == 2)
				part2_tester(details_mode, ft_start, ft_end);
			else if(atoi(argv[2]) == 3)
				bonus_tester(details_mode, ft_start, ft_end);
			else
			{
				write(1, "Your part number is incorrect, please enter a number between 1 and 3 !\n", 71);
				return (0);
			}
		}
	}
	return (0);
}
