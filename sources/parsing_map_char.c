/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:27 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/30 15:16:19 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	floor_celling(char c); //parsing_map_char
bool	player_char(char c); //parsing_map_char
bool	check_map_char(t_cub *cub); //parsing_map_char
bool	valid_char(char c); //parsing_map_char

bool	floor_celling(char c)
{
	if (c == '1' || c == '0')
		return (true);
	else if ((c >= 9 && c <= 23) || c == 32)
		return (true);
	else
		return (printf("\n%c\n", c), false);
}

bool	player_char(char c)
{
	// printf("je rentre la\n");
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (true);
	return (printf("\n2\n"), false);
}

bool	check_map_char(t_cub *cub)
{
	int i;
	int j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (!floor_celling(cub->map[i][j]))
			{
				if (player_char(cub->map[i][j]))
				{
					count_player++;
				}
				else
					return (false);
			}
			j++;
		}
		i++;
	}
	if (count_player != 1)
				return (false);
	return (true);
}

bool	valid_char(char c)
{
	if (c == '0')
		return (true);
	return (false);
}