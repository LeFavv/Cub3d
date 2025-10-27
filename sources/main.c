/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:04:13 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 16:54:43 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_cub *cub;
    int i = 0;
    
    cub = malloc(sizeof(t_cub));
    if (!cub)
        return (printf("Error\nMalloc failed"), 1);
    if (!init_all(cub))
    {
        ft_free_all(cub);
        free(cub);
        return (1);
    }
    cub->file = load_file(argv[1], cub);
    cub->info_map = load_info(cub->file, cub);
    cub->map = load_map(cub->file, cub);
    while (cub->file[i])
    {
        printf("%s", cub->file[i]);
        i++;
    }
    printf("\n=============================\n");
    i = 0;
    while (cub->info_map[i])
    {
        printf("%s", cub->info_map[i]);
        i++;
    }
    printf("\n=============================\n");
    i = 0;
    while (cub->map[i])
    {
        printf("%s", cub->map[i]);
        i++;
    }
    if (!directions_texture(cub->info_map, cub))
    {
        ft_free_all(cub);
        exit (0);
    }
    printf("\n=============================\n");
    printf("NO = %s\n", cub->NO);
    printf("SO = %s\n", cub->SO);
    printf("WE = %s\n", cub->WE);
    printf("EA = %s\n", cub->EA);
    
    printf("\n=============================\n");
    printf("floor = %s\n", cub->floor);
    printf("celling = %s\n", cub->celling);
    // if (!check_rgb_str(cub) || !check_rgb_str_2(cub))
    // {
    //     printf("Error\nInvalid RGB values\n");
    //     return (ft_free_all(cub), free(cub), 1);
    // }
    ft_check_colours_1(cub);
    ft_check_colours_2(cub);
    printf("\n=============================\n");
    i = 0;
    while (i < 3)
    {
        printf("%d\n", cub->F[i]);
        i++;
    }
    i = 0;
    while (i < 3)
    {
        printf("%d\n", cub->C[i]);
        i++;
    }
    ft_free_all(cub);
    free(cub);
    return (0);
}