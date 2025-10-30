/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:17 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/30 15:41:22 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	check_valid_space(t_cub **cub, int f); //check_valid_map
bool	check_zero_leak(t_cub *cub); //check_valid_map
bool	check_sides(t_cub *cub); //check_valid_map
bool	check_map_spaces(t_cub *cub); //check_valid_map
bool	check_map(t_cub *cub); //check_valid_map

void	check_valid_space(t_cub **cub, int f)
{
	int i;
	int j;
	int k;
	// int	l;
	
	i = 1;
	while (/*cub->map[i]*/i < (double_tab_lenght((*cub)->map) - 1))
	{
		j = 1;
		while (/*cub->map[i][j]*/j < ((int)ft_strlen((*cub)->map[i]) - 1))
		{
			k = 0;
			if ((*cub)->map[i][j] == ' ')
			{
				if ((*cub)->map[i][j] == ' ')
				{
				    int valid = 0;
				    if (j + 1 < (int)ft_strlen((*cub)->map[i]) && valid_char((*cub)->map[i][j + 1]))
				        valid = 1;
				    if (valid_char((*cub)->map[i][j - 1]))
				        valid = 1;
				    if (j < (int)ft_strlen((*cub)->map[i + 1]) && valid_char((*cub)->map[i + 1][j]))
				        valid = 1;
				    if (j < (int)ft_strlen((*cub)->map[i - 1]) && valid_char((*cub)->map[i - 1][j]))
				        valid = 1;
				    if (valid)
				        (*cub)->map[i][j] = '0';
					else if ((*cub)->map[i][j - 1] == '1')
					{
						while ((*cub)->map[i][j + k] && (*cub)->map[i][j + k] != '1')
						{
							if ((*cub)->map[i][j + k] == '0')
							{
								while (j < k)
								{
									if ((*cub)->map[i][j] != '1')
										(*cub)->map[i][j] = '0';
									j++;
								}
							}
							k++;
						}
						
					}
				}
			}
			j++;
		}
		i++;
	}
	if (f == 1)
		return;
	check_valid_space(cub, 1);
}

bool	check_zero_leak(t_cub *cub)
{
	int i;
	int	j;
	
	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
			{
				if (!cub->map[i + 1][j] || !cub->map[i - 1][j])
					return (printf("A\n"), false);
				else if (cub->map[i + 1][j] == ' ' || cub->map[i - 1][j] == ' ')
					return (printf("B %s [%d][%d]\n", cub->map[i],i, j), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_sides(t_cub *cub)
{
	int i;
	int j;
	
	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][0] != ' ')
			{
				if (cub->map[i][0] != '1')
					return (printf("1 %s\n", cub->map[i]), false);
			}
			if (cub->map[i][j + 1] == '\n')
			{
				if (cub->map[i][j] != '1' && cub->map[i][j] != ' ')
					return (printf("2\n"), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_spaces(t_cub *cub)
{
	int i;
	int j;
	int flag;
	
	i = 1;
	while (cub->map[i])
	{
		j = 1;
		while (cub->map[i][j])
		{
			flag = 0;
			if (cub->map[i][j] == ' ')
			{
				flag = 1;
				// if (cub->map[i][j - 1] && cub->map[i][j - 1] != '1')
				// 	return (printf("C\n"), false);
				while (cub->map[i][j] && cub->map[i][j] == ' ')
					j++;
			}
			if (flag == 1 && (cub->map[i][j] != '1' && cub->map[i][j + 1]))
				return (/*printf("D %s [%d]\n", cub->map[i], i), */false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map(t_cub *cub)
{
	int i;
	int	j;
	int	flag;
	
	i = 0;
	flag = 0;
	while (cub->map[i])
	{
		j = 0;
		flag = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != ' ' && cub->map[i][j] != '\n')
				flag = 1;
			j++;
		}
		if (!flag)
			return (printf("\nla\n"),false);
		i++;
	}
	i -= 1;
	j = 0;
	while (cub->map[i][j])
	{
		if (cub->map[i][j] != '1')
		{
			if (cub->map[i][j] != ' ')
				return (printf("2%s\n", cub->map[i]),false);
		}
		j++;
	}
	return (true);
}