/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:04:13 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 12:08:04 by vafavard         ###   ########.fr       */
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
    init_all(cub);
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
    ft_free_all(cub);
    free(cub);
    return (0);
}