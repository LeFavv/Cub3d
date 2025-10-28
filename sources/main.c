/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:04:13 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/28 12:39:45 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
    t_cub *cub;
    int i = 0;
    if (argc != 2)
        return (1);
    if (!check_name(argv[1]))
        return (printf("Error\nBad File name\n"), 1);
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
    if (!cub->file)
        return (ft_free_all(cub), free(cub), 1);
    cub->info_map = load_info(cub->file, cub);
    if (!cub->info_map)
        return (ft_free_all(cub), free(cub), 1);
    cub->map = load_map(cub->file, cub);
    if (!cub->map)
        return (ft_free_all(cub), free(cub), 1);
    if (!check_map(cub))
        return (printf("File .cub non correct\n"), ft_free_all(cub), free(cub), 1);
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
    if (!check_rgb_str(cub) || !check_rgb_str_2(cub))
    {
        printf("Error\nInvalid RGB values\n");
        return (ft_free_all(cub), free(cub), 1);
    }
    ft_check_colours_1(cub);
    ft_check_colours_2(cub);
    if (!check_numbers(cub->F) || !check_numbers(cub->C))
    {
        printf("Error\nInvalid RGB values\n");
        return (ft_free_all(cub), free(cub), 1);
    }
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