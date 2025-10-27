/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:41:17 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 12:09:49 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_cub
{
    char    **file; //idee de tout recup de base puis de separer entre le double tab map et info_map pour les gerer separement
    char    **map;
    char    **info_map;
    int     line_info;
    int     line_total;
}t_cub;

int		nb_line(char *file, t_cub *cub);
bool	check_name(char *file);
char	**load_info(char **file, t_cub *cub);
int		nb_line_info(char **file, t_cub *cub);
char	**load_file(char *file, t_cub *cub);
char	**load_map(char **file, t_cub *cub);
void    ft_free_all(t_cub *cub);
void    ft_free_tab(char **tab);
void    ft_free(char **file);
void    init_all(t_cub *cub);

#endif