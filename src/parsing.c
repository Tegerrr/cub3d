/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:30 by mac               #+#    #+#             */
/*   Updated: 2024/03/08 14:58:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	is_map_a_cub_file(char *map_path)
{
	if (ft_strncmp(map_path + (ft_strlen(map_path) - 4), ".cub", 4))
		message_error_exit("Error: map is not .cub!\n");
	return (0);
}

int	check_if_empty(char *big_str)
{
	int	i;

	i = 0;
	if (!*big_str)
		message_error_exit("map is empty!\n");
	while (big_str[i])
	{
		if (big_str[i] != '\n')
			return (0);
		i++;
	}
	message_error_exit("map is empty except for new lines!\n");
	return (1);
}

void open_map_file(char *map_path, int *fd)
{
	*fd = open(map_path, O_RDONLY);
	if ((*fd) < 0)
		message_error_exit("Error: couldn't open map!\n");
}

void	parse_textures_and_colors(int map_fd, t_data *data)
{
	//use get_next_line unil all 6 keys for texture and color are found
	//if map's 0s and 1s start before all 6 keys are found, call message_error
	//stop immediately after all 6 keys are found
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
	data->map->map = ft_split(big_str, '\n');
	free(big_str);
}


int	parsing(char *map_path, t_data *data)
{
	int fd;
	is_map_a_cub_file(map_path);
	open_map_file(map_path, &fd);
	parse_textures_and_colors(fd, data);
	put_2d_map_into_double_arr(fd, data);
	validate_2d_map(data->map->map);
	//does_map_have_all_textures(argv[1]);
	return 0;
}
