/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafavard <vafavard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:39:31 by vafavard          #+#    #+#             */
/*   Updated: 2025/10/29 15:15:26 by vafavard         ###   ########.fr       */
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
bool	check_rgb_str(t_cub *cub);
int		check_rgb_str_2(t_cub *cub);
int		ft_atoi(char *str);
void	ft_check_colours_1(t_cub *cub);
bool	check_numbers(int *tab);
bool	check_map(t_cub *cub);
bool	check_map_spaces(t_cub *cub);
bool	check_sides(t_cub *cub);
bool	check_zero_leak(t_cub *cub);
void	check_valid_space(t_cub **cub, int f);
bool	valid_char(char c);
bool	check_map_char(t_cub *cub);
bool	floor_celling(char c);
bool	player_char(char c);

bool	floor_celling(char c)
{
	if (c == '1' || c == '0')
		return (true);
	else if ((c >= 9 && c <= 23) || c == 32)
		return (true);
	return (printf("\n%c\n", c), false);
}

bool	player_char(char c)
{
	if (c == 'E' || c == 'W' || c == 'S' || c == 'N')
		return (true);
	return (printf("\n2\n"), false);
}


bool	check_map_char(t_cub *cub)
{
	int i;
	int j;
	int	count_player;

	i = 0;
	count_player = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (floor_celling(cub->map[i][j]))
				j++;
			else if (player_char(cub->map[i][j]))
			{
				count_player++;
				j++;
			}
			else
				return (false);
			if (count_player > 1)
				return (false);
		}
		i++;
	}
	return (true);
}

bool	valid_char(char c)
{
	if (c == '0')
		return (true);
	return (false);
}

int	double_tab_lenght(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

// void	check_valid_space(t_cub *cub)
// {
// 	int i;
// 	int j;
	
// 	i = 1;
// 	while (/*cub->map[i]*/i < (double_tab_lenght(cub->map) - 1))
// 	{
// 		j = 1;
// 		while (/*cub->map[i][j]*/j < ((int)ft_strlen(cub->map[i]) - 1))
// 		{
// 			if (cub->map[i][j] == ' ')
// 			{
// 				if (valid_char(cub->map[i][j + 1]) || valid_char(cub->map[i][j - 1])
// 					 || valid_char(cub->map[i + 1][j]) || valid_char(cub->map[i - 1][j]))
// 					cub->map[i][j] = '0';
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }
void	check_valid_space(t_cub **cub, int f)
{
	int i;
	int j;
	int k;
	// int	l;
	
	i = 1;
	while (/*cub->map[i]*/i < (double_tab_lenght((*cub)->map) - 1))
	{
		j = 1;
		while (/*cub->map[i][j]*/j < ((int)ft_strlen((*cub)->map[i]) - 1))
		{
			k = 0;
			if ((*cub)->map[i][j] == ' ')
			{
				if ((*cub)->map[i][j] == ' ')
				{
				    int valid = 0;
				    if (j + 1 < (int)ft_strlen((*cub)->map[i]) && valid_char((*cub)->map[i][j + 1]))
				        valid = 1;
				    if (valid_char((*cub)->map[i][j - 1]))
				        valid = 1;
				    if (j < (int)ft_strlen((*cub)->map[i + 1]) && valid_char((*cub)->map[i + 1][j]))
				        valid = 1;
				    if (j < (int)ft_strlen((*cub)->map[i - 1]) && valid_char((*cub)->map[i - 1][j]))
				        valid = 1;
				    if (valid)
				        (*cub)->map[i][j] = '0';
					else if ((*cub)->map[i][j - 1] == '1')
					{
						while ((*cub)->map[i][j + k] && (*cub)->map[i][j + k] != '1')
						{
							if ((*cub)->map[i][j + k] == '0')
							{
								while (j < k)
								{
									if ((*cub)->map[i][j] != '1')
										(*cub)->map[i][j] = '0';
									j++;
								}
							}
							k++;
						}
						
					}
				}
			}
			j++;
		}
		i++;
	}
	if (f == 1)
		return;
	check_valid_space(cub, 1);
}

// void	check_valid_space(t_cub **cub)
// {
// 	int i;
// 	int j;
// 	int k;
	
// 	i = 1;
// 	while (/*cub->map[i]*/i < (double_tab_lenght((*cub)->map) - 1))
// 	{
// 		j = 1;
// 		while (/*cub->map[i][j]*/j < ((int)ft_strlen((*cub)->map[i]) - 1))
// 		{
// 			if ((*cub)->map[i][j] == ' ')
// 			{
// 				// if (valid_char((*cub)->map[i][j + 1]) || valid_char((*cub)->map[i][j - 1])
// 				// 	 || valid_char((*cub)->map[i + 1][j]) || valid_char((*cub)->map[i - 1][j]))
// 				// {
// 				// 	(*cub)->map[i][j] = '0';
// 				// 	// printf("suis je la\n");
// 				// }
// 				if ((*cub)->map[i][j] == ' ')
// 				{
// 				    int valid = 0;
// 					k = 0;
// 				    if (j + 1 < (int)ft_strlen((*cub)->map[i]) && valid_char((*cub)->map[i][j + 1]))
// 					{
// 						if (((*cub)->map[i][j - 1] && valid_char((*cub)->map[i][j - 1])))
// 						{
// 							while ((*cub)->map[i][j + k])
// 							{
// 								if ((*cub)->map[i][j + k] == '0')
// 									valid = 1;
// 								k++;
// 							}
// 						}
// 						k = 0;
// 					}
// 				    if (valid_char((*cub)->map[i][j - 1]))
// 					{
// 						if (((*cub)->map[i][j - 1] && valid_char((*cub)->map[i][j - 1])))
// 						{
// 							while ((*cub)->map[i][j + k])
// 							{
// 								if ((*cub)->map[i][j + k] == '0')
// 									valid = 1;
// 								k--;
// 							}
// 						}
// 						k = 0;
// 					}
// 				        valid = 1;
// 				    if (j < (int)ft_strlen((*cub)->map[i + 1]) && valid_char((*cub)->map[i + 1][j]))
// 				        valid = 1;
// 				    if (j < (int)ft_strlen((*cub)->map[i - 1]) && valid_char((*cub)->map[i - 1][j]))
// 				        valid = 1;
// 				    if (valid)
// 				        (*cub)->map[i][j] = '0';
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

bool	check_zero_leak(t_cub *cub)
{
	int i;
	int	j;
	
	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] == '0')
			{
				if (!cub->map[i + 1][j] || !cub->map[i - 1][j])
					return (printf("A\n"), false);
				else if (cub->map[i + 1][j] == ' ' || cub->map[i - 1][j] == ' ')
					return (printf("B %s [%d][%d]\n", cub->map[i],i, j), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_sides(t_cub *cub)
{
	int i;
	int j;
	
	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][0] != ' ')
			{
				if (cub->map[i][0] != '1')
					return (printf("1 %s\n", cub->map[i]), false);
			}
			if (cub->map[i][j + 1] == '\n')
			{
				if (cub->map[i][j] != '1' && cub->map[i][j] != ' ')
					return (printf("2\n"), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map_spaces(t_cub *cub)
{
	int i;
	int j;
	int flag;
	
	i = 1;
	while (cub->map[i])
	{
		j = 1;
		while (cub->map[i][j])
		{
			flag = 0;
			if (cub->map[i][j] == ' ')
			{
				flag = 1;
				// if (cub->map[i][j - 1] && cub->map[i][j - 1] != '1')
				// 	return (printf("C\n"), false);
				while (cub->map[i][j] && cub->map[i][j] == ' ')
					j++;
			}
			if (flag == 1 && (cub->map[i][j] != '1' && cub->map[i][j + 1]))
				return (/*printf("D %s [%d]\n", cub->map[i], i), */false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	check_map(t_cub *cub)
{
	int i;
	int	j;
	int	flag;
	
	i = 0;
	flag = 0;
	while (cub->map[i])
	{
		j = 0;
		flag = 0;
		while (cub->map[i][j])
		{
			if (cub->map[i][j] != ' ' && cub->map[i][j] != '\n')
				flag = 1;
			j++;
		}
		if (!flag)
			return (printf("\nla\n"),false);
		i++;
	}
	i -= 1;
	j = 0;
	while (cub->map[i][j])
	{
		if (cub->map[i][j] != '1')
		{
			if (cub->map[i][j] != ' ')
				return (printf("2%s\n", cub->map[i]),false);
		}
		j++;
	}
	return (true);
}

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

int	ft_atoi(char *str)
{
	int nb;
	int i;
	
	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
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

char	*skip_space(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (&str[i]);
	}
	return (&str[i]);
}

// int		is_valid(char *file)
// {
// 	if (ft_strncmp(file, "NO", 2) == 0)
// 		return (1);
// 	else if (ft_strncmp(file, "SO", 2) == 0)
// 		return (2);
// 	else if (ft_strncmp(file, "WE", 2) == 0)
// 		return (3);
// 	else if (ft_strncmp(file, "EA", 2) == 0)
// 		return (4);
// 	else if (ft_strncmp(file, "F", 1) == 0)
// 		return (5);
// 	else if (ft_strncmp(file, "C", 1) == 0)
// 		return (6);
// 	return (0);
// }

int		is_valid(char *file)
{
	if (ft_strncmp(skip_space(file), "NO", 2) == 0)
		return (1);
	else if (ft_strncmp(skip_space(file), "SO", 2) == 0)
		return (2);
	else if (ft_strncmp(skip_space(file), "WE", 2) == 0)
		return (3);
	else if (ft_strncmp(skip_space(file), "EA", 2) == 0)
		return (4);
	else if (ft_strncmp(skip_space(file), "F", 1) == 0)
		return (5);
	else if (ft_strncmp(skip_space(file), "C", 1) == 0)
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
	int i ;
	int	j;

	i = 0;
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
	while (file[i] && file[i] != '.')
		i++;
	i++;
	if (file[i] == 'c')
		valide += 1;
	// else
	// 	printf("1 %c\n", file[i]);
	if (file[i + 1] == 'u')
		valide += 1;
	// else
	// 	printf("2 %c\n", file[i + 1]);
	if (file[i + 2] == 'b')
		valide += 1;
	if (file[i + 3] != '\0')
		return (false);
	// else
	// 	printf("3 %c\n", file[i + 2]);
	if (valide == 3)
		return (true);
	else
		return (/*printf("%d\n", valide), */false);
}