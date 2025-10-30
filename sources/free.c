/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:03:49 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/30 15:46:08 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_free_tab(char **tab);

void    ft_free_all(t_cub *cub)
{
    if (cub->file)
    {
        ft_free_tab(cub->file);
        cub->file = NULL;   
    }
    if (cub->info_map)
    {
        ft_free_tab(cub->info_map);
        cub->info_map = NULL;
    }
    if (cub->map)
    {
        ft_free_tab(cub->map);
        cub->map = NULL;   
    }
    if (cub->EA)
    {
        free(cub->EA);
        cub->EA = NULL;
    }
    if (cub->NO)
    {
        free(cub->NO);
        cub->NO = NULL;
    }
    if (cub->SO)
    {
        free(cub->SO);
        cub->SO = NULL;   
    }
    if (cub->WE)
    {
        free(cub->WE);
        cub->WE = NULL;   
    }
    if (cub->floor)
    {
        free(cub->floor);
        cub->floor = NULL;   
    }
    if (cub->celling)
    {
        free(cub->celling);
        cub->celling = NULL;   
    }
    if (cub->C)
    {
        free(cub->C);
    }
    if (cub->F)
    {
        free(cub->F);
    }
}

// void    ft_free_int_tab(int *tab)
// {
//     free(tab);
// }

void    ft_free_tab(char **tab)
{
    int i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
}

// void    ft_free(char *file)
// {
//     free(file);
// }