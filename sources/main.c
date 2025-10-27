/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:04:13 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 11:08:58 by vafavard         ###   ########.fr       */
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
    cub->file = load_map(argv[1]);
    while (cub->file[i])
    {
        printf("%s", cub->file[i]);
        i++;
    }
    return (0);
}