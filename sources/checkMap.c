/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:39:31 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/27 16:55:11 by vafavard         ###   ########.fr       */
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
int		fill_floor_celling(int index, char *file, t_cub *cub);
void	fill_floor_celling_2(t_cub *cub, int index, char *line);
int		check_rgb_str(t_cub *cub);
int		check_rgb_str_2(t_cub *cub);
int		ft_atoi(char *str);
void	ft_check_colours_1(t_cub *cub);

int		check_rgb_str(t_cub *cub)
{
	int i = 0;
	int count = 0;
	
	while (cub->floor[i])
	{
		if (!(cub->floor[i] >= '0' && cub->floor[i] <= '9') 
			|| cub->floor[i] != ',')
			return (0);
		else if (cub->floor[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	count = 0;
	while (cub->celling[i])
	{
		if (!(cub->celling[i] >= '0' && cub->celling[i] <= '9') 
			|| cub->celling[i] != ',')
			return (0);
		if (cub->celling[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int	check_rgb_str_2(t_cub *cub)
{
	if (ft_strlen(cub->celling) < 5 || ft_strlen(cub->celling) > 11)
		return (0);
	if (ft_strlen(cub->floor) < 5 || ft_strlen(cub->floor) > 11)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	int nb;
	int i;
	
	nb = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

// void	ft_check_colours(t_cub *cub)
// {
// 	int i = 0;
// 	int j = 0;
// 	while (cub->floor[i] && j < 3)
// 	{
// 		while (cub->floor[i] && cub->floor[i] != ',')
// 			i++;
// 		cub->F[j] = ft_atoi(&cub->floor[i]);
// 		i++;
// 		j++;
// 	}
// }

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

int	fill_floor_celling(int index, char *file, t_cub *cub)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (!(file[i] >= '0' && file[i] <= '9'))
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
	fill_floor_celling_2(cub, index, line);
	return (1);
}

void	fill_floor_celling_2(t_cub *cub, int index, char *line)
{
	if (index == 5)
		cub->floor = line;
	else if (index == 6)
		cub->celling = line;
}

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
	else if (ft_strncmp(file, "F", 1) == 0)
		return (5);
	else if (ft_strncmp(file, "C", 1) == 0)
		return (6);
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
}

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

int	directions_texture(char **file, t_cub *cub)
{
	int i;
	int index;

	i = 0;
	while (cub->info_map[i])
	{
		if (is_valid(cub->info_map[i]))
		{
			index = is_valid(cub->info_map[i]);
			if (index >= 5)
			{
				if (!fill_floor_celling(index, file[i], cub))
					return (ft_free_all(cub), 0);
			}
			else if (!fill_direction(index, file[i], cub))
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