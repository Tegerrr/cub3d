/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:30 by mac               #+#    #+#             */
/*   Updated: 2024/04/15 17:54:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_file_extension_right(char *map_path , char *extension)
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
/*
int	check_if_empty(char **map)
{
	int	i;

	i = -1;
	if (!map)
		message_error_exit("map is empty!\n");
	while (map[++i])
		if (!has_not_only_white_space(map[i]))
			return (0);
	message_error_exit("map is empty!\n");
	return (1);
}
*/

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
	// for(int i = 0; data->map->map[i]; i++)
	// {
	// 	printf("%s\n", data->map->map[i]);
	// }
	free(big_str);
}

void	orient_W(t_data *data)
{
	if (data->player->orientation == 'W')
	{
		data->dir_x = -1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}

void	orient(t_data *data)
{
	if (data->player->orientation == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	if (data->player->orientation == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1;
		
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	if (data->player->orientation == 'E')
	{
		data->dir_x = 1;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	orient_W(data);
}

int	parsing(char *map_path, t_data *data)
{
	int	fd;

	is_file_extension_right(map_path, ".cub");
	open_map_file(map_path, &fd);
	parse_textures_and_colors(fd, data);
	print_texture_color_data(data);
	put_2d_map_into_double_arr(fd, data);
	check_if_map_has_right_chars(data->map->map, data);
	check_map_walls(data->map->map);
	print_double_char_arr(data->map->map);
	orient(data);
	printf("player info: x: %i, y: %i, orientation: %c\n", data->player->x, data->player->y, data->player->orientation);
	printf("No gaps, BITCH!\n");
	//print_double_char_arr(data->map->map);
	//validate_2d_map(data->map->map);
	return 0;
}
