/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:30 by mac               #+#    #+#             */
/*   Updated: 2024/04/18 01:32:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_file_extension_right(char *map_path, char *extension)
{
	int	extension_len;

	extension_len = ft_strlen(extension);
	if (ft_strncmp(map_path + (ft_strlen(map_path)
				- extension_len), extension, extension_len))
	{
		printf("%s should have extension %s\n", map_path, extension);
		message_error_exit("map or texture has wrong file extension!\n");
	}
	return (0);
}

void	check_if_map_too_big(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (!map)
		message_error_exit("map array ptr is null!\n");
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > MAX_MAP_WIDTH)
			message_error_exit("map is too big!\n");
		i++;
	}
	if (i > MAX_MAP_HEIGHT)
		message_error_exit("map is too big!\n");
}

void	open_map_file(char *map_path, int *fd)
{
	*fd = open(map_path, O_RDONLY);
	if ((*fd) < 0)
		message_error_exit("couldn't open map!\n");
}

void	put_2d_map_into_double_arr(int map_fd, t_data *data)
{
	char	*big_str;
	char	*tmp;
	char	*tmp2;

	big_str = ft_calloc(1, sizeof(char));
	if (!big_str)
		message_error_exit("malloc failed in ft_calloc!\n");
	while (1)
	{
		tmp = get_next_line(map_fd);
		if (!tmp)
			break ;
		tmp2 = ft_strdup(big_str);
		free(big_str);
		big_str = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
	}
	check_if_empty(big_str);
	no_double_new_line(big_str);
	data->map->map = ft_split(big_str, '\n');
	free(big_str);
}

int	parsing(char *map_path, t_data *data)
{
	int	fd;

	is_file_extension_right(map_path, ".cub");
	open_map_file(map_path, &fd);
	parse_textures_and_colors(fd, data);
	put_2d_map_into_double_arr(fd, data);
	check_if_map_too_big(data->map->map);
	check_if_map_has_right_chars(data->map->map, data);
	check_map_walls(data->map->map);
	orient(data);
	return (0);
}
