/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:20:18 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/30 15:21:39 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	check_numbers(int *tab); //parsing_colours
bool	check_rgb_str(t_cub *cub); //parsing_colours
int		check_rgb_str_2(t_cub *cub); //parsing_colours
void	ft_check_colours_1(t_cub *cub); //parsing_colours
void	ft_check_colours_2(t_cub *cub); //parsing_colours

bool	check_numbers(int *tab)
{
	int i;

	i = 0;
	while (i < 3)
	{
		// printf("valeur de tab[i] = %d\n", tab[i]);
		if (tab[i] < 0 || tab[i] > 255)
			return (false);
		i++;
	}
	return (true);
}

bool		check_rgb_str(t_cub *cub) //possible de faire un truc universel en prenant en parametre une string et pas cub
{
	int i = 0;
	int count = 0;
	// printf("|%s|\n", cub->floor);
	if (!cub->floor || !cub->celling)
		return (false);
	while (i < (int)ft_strlen(cub->floor) - 1)
	{
		if (!(cub->floor[i] >= '0' && cub->floor[i] <= '9'))
		{
			if (cub->floor[i] == ',')
				count++;
			else if (!((cub->floor[i] >= 9 && cub->floor[i] <= 13) || cub->floor[i] == 32))
				return (printf("1\n"), false);
		}
		i++;
	}
	if (count != 2)
		return (false);
	count = 0;
	i = 0;
	while (i < (int)ft_strlen(cub->celling) - 1)
	{
		if (!(cub->celling[i] >= '0' && cub->celling[i] <= '9'))
		{
			if (cub->celling[i] == ',')
				count++;
			else if (!((cub->celling[i] >= 9 && cub->celling[i] <= 13) || cub->celling[i] == 32))
				return (printf("1\n"), false);
		}
		i++;
	}
	if (count != 2)
		return (false);
	return (true);
}

int	check_rgb_str_2(t_cub *cub)
{
	// printf("je rentre la\n");
	if (ft_strlen(cub->celling) < 5 || ft_strlen(cub->celling) > 11)
		return (0);
	if (ft_strlen(cub->floor) < 5 || ft_strlen(cub->floor) > 11)
		return (0);
	return (1);
}

void	ft_check_colours_1(t_cub *cub)
{
    char **values;
    int i = 0;
    
    values = ft_split(cub->floor, ',');
    
    while (values[i] && i < 3)
    {
        cub->F[i] = ft_atoi(values[i]);
        i++;
    }
    
    ft_free_tab(values);
}

void	ft_check_colours_2(t_cub *cub)
{
    char **values;
    int i = 0;
    
    values = ft_split(cub->celling, ',');
    
    while (values[i] && i < 3)
    {
        cub->C[i] = ft_atoi(values[i]);
        i++;
    }
    
    ft_free_tab(values);
}