/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:03:49 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 13:58:27 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
        ft_free(cub->EA);
        cub->EA = NULL;
    }
    if (cub->NO)
    {
        ft_free(cub->NO);
        cub->NO = NULL;
    }
    if (cub->SO)
    {
        ft_free(cub->SO);
        cub->SO = NULL;   
    }
    if (cub->WE)
    {
        ft_free(cub->WE);
        cub->WE = NULL;   
    }
    // ft_free(cub->info_map);
    // ft_free(cub->map);
}

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

void    ft_free(char *file)
{
    free(file);
}