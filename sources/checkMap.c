/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:39:31 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 14:20:28 by vafavard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

char	**load_file(char *file, t_cub *cub);
char	**load_map(char **file, t_cub *cub);
int		nb_line(char *file, t_cub *cub);
bool	check_name(char *file);
int		nb_line_info(char **file, t_cub *cub);
char	**load_info(char **file, t_cub *cub);
int		fill_direction(int index, char *file, t_cub *cub);
void	fill_direction_2(t_cub *cub, int index, char *line);
int		is_valid(char *file);
int		directions_texture(char **file, t_cub *cub);

int		is_valid(char *file)
{
	if (ft_strncmp(file, "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(file, "SO", 2) == 0)
		return (2);
	else if (ft_strncmp(file, "WE", 2) == 0)
		return (3);
	else if (ft_strncmp(file, "EA", 2) == 0)
		return (4);
	return (0);
}

void	fill_direction_2(t_cub *cub, int index, char *line)
{
	if (index == 1)
		cub->NO = line;
	else if (index  == 2)
		cub->SO = line;
	else if (index == 3)
		cub->WE = line;
	else if (index == 4)
		cub->EA = line;
		
	// printf("\nfunc NO = %s\n", cub->NO);
    // printf("func SO = %s\n", cub->SO);
    // printf("func WE = %s\n", cub->WE);
    // printf("func EA = %s\n", cub->EA);
}

// void	fill_direction_2(t_cub *cub, int index, char *line)
// {
// 	if (index == 1)
// 	{
// 		cub->NO = ft_strdup(line);
// 		free(line);	
// 	}
// 	else if (index  == 2)
// 	{
// 		cub->SO = ft_strdup(line);
// 		free(line);	
// 	}
// 	else if (index == 3)
// 	{
// 		cub->WE = ft_strdup(line);
// 		free(line);	
// 	}
// 	else if (index == 4)
// 	{
// 		cub->EA = ft_strdup(line);
// 		free(line);	
// 	}
// }

int	fill_direction(int index,char *file, t_cub *cub)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (file[i] != '.')
		i++;
	while (file[i + j])
		j++;
	line = malloc(sizeof(char) * (j + 1));
	if (!line)
		return (printf("Error\nMalloc failed\n"), 0);
	j = 0;
	while (file[i])
	{
		line[j] = file[i];
		i++;
		j++;
	}
	line[j] = '\0';
	fill_direction_2(cub, index, line);
	return (1);
}

int	directions_texture(char **file, t_cub *cub) //gerer en cas de return 0 pour stopper le programme
{
	int i;
	int	j;
	int	k;
	int index;

	j = 0;
	k = 0;
	i = 0;
	while (cub->info_map[i])
	{
		if (is_valid(cub->info_map[i]))
		{
			index = is_valid(cub->info_map[i]);
			// while (file[i][j] != '.')
			// 	j++;
			// while (file[i][j + k])
			// 	k++;
			if (!fill_direction(index, file[i], cub))
			{
				ft_free_all(cub);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

char	**load_file(char *file, t_cub *cub)
{
	int		fd;
	int		lines;
	int		i;
	char	**map;
	char	*line;

	i = 0;
	lines = nb_line(file, cub);
	if (lines <= 0)
		return (NULL);
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (close(fd), map);
}

char	**load_info(char **file, t_cub *cub)
{
	int 	lines;
	char	**info;
	int		i;

	i = 0;
	lines = nb_line_info(file, cub);
	info = malloc(sizeof(char *) * (lines + 1));
	if (!info)
		return (printf("Error\nMalloc failed\n"), NULL);
	while (i < lines)
	{
		info[i] = ft_strdup(file[i]);
		// info[i] = file[i];
		i++;
	}
	info[i] = NULL;
	return (info);
}

char	**load_map(char **file, t_cub *cub)
{
	char	**map;
	int		i;
	
	i = 0;
	map = malloc(sizeof(char *) * (cub->line_total - cub->line_info + 1));
	if (!map)
		return (printf("Error\nMalloc failed\n"), NULL);
	while (file[cub->line_info + i])
	{
		map[i] = ft_strdup(file[cub->line_info + i]);
		// map[i] = file[cub->line_info + i];
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	nb_line_info(char **file, t_cub *cub)
{
	int count;
	int i ;
	int	j;

	i = 0;
	count  = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == '\n' || file[i][j] == ' ')
			j++;
		if (file[i][j] == '1')
			return (cub->line_info = i, i);
		i += 1;
	}
	return (i);
}

int	nb_line(char *file, t_cub *cub)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	cub->line_total = count;
	return (count);
}

bool	check_name(char *file)
{
	int	i;
	int	valide;

	valide = 0;
	i = 0;
	while (file[i] != '.')
		i++;
	i++;
	if (file[i] == 'c')
		valide += 1;
	if (file[i + 1] == 'u')
		valide += 1;
	if (file[i + 2] == 'b')
		valide += 1;
	if (valide == 3)
		return (true);
	else
		return (false);
}