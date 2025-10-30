/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:13:30 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/30 15:41:53 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

bool	load_and_check(t_cub *cub); //parsing_map
bool	check_general(t_cub *cub); //parsing_map

bool	load_and_check(t_cub *cub)
{
	cub->info_map = load_info(cub->file, cub);
    if (!cub->info_map)
        return (false);
    cub->map = load_map(cub->file, cub);
	if (!cub->map)
    	return (false);
		
	if (!check_general(cub))
		return (false);
	return (true);
}

bool	check_general(t_cub *cub)
{
	if (!check_map(cub))
        return (printf("File .cub non correct1\n"), false);
	check_valid_space(&cub, 0);
	if (!check_map_spaces(cub) || !check_sides(cub) || !check_zero_leak(cub))
        return (printf("File .cub non correct3\n"), false);
	if (!check_map_char(cub))
        return (printf("Invalides char in map\n"), false);
	if (!directions_texture(cub->info_map, cub))
		return (printf("Texture directions invalid\n"), false);
	if (!check_rgb_str(cub))
		return (printf("Error\nInvalid RGB values\n"), false);
	ft_check_colours_1(cub);
    ft_check_colours_2(cub);
	if (!check_numbers(cub->F) || !check_numbers(cub->C))
		return (printf("Error\nInvalid RGB values\n"), false);
	return (true);
}