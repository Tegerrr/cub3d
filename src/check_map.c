/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:42:20 by sbalasho          #+#    #+#             */
/*   Updated: 2024/04/07 16:30:28 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_if_map_has_right_chars(char **map, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	data->player->found_flag = 0;
	while (map && map[++i])
	{
		j = -1;
		while (map[i] && map[i][++j])
		{
			if (!ft_strchr(VALID_MAP_CHARS, map[i][j]))
				message_error_exit("map has an invalid char\n");
			if (ft_strchr(ORIENTATION_CHARS, map[i][j]))
			{
				if (data->player->found_flag == 1)
					message_error_exit("map has more than 1 player position\n");
				data->player->found_flag = 1;
				data->player->x = j;
				data->player->y = i;
				data->player->orientation = map[i][j];			
			}
		}
	}
	if (data->player->found_flag == 0)
		message_error_exit("map has no player\n");
}

void	check_map_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		j = 0;
		//print_double_char_arr(map);
		//printf("what the actuall fuck? map[i][j]: %i\n", map[i][j]);
		while (map[i][j])
		{
			// printf("check_map_walls! line: %i, char pos: %i, char: %c\n", i, j, map[i][j]);
			if (map[i][j] == '0' || ft_strchr(ORIENTATION_CHARS, map[i][j]))
				check_if_enclosed_by_walls(j, i, map);
			j++;
		}
		i++;
	}
}

void	check_if_enclosed_by_walls(int x, int y, char **map)
{
	if (!is_enclosed_north(x, y, map))
		message_error_exit("map has a gap (direction north)!\n");
	if (!is_enclosed_south(x, y, map))
		message_error_exit("map has a gap (direction south)!\n");
	if (!is_enclosed_east(x, y, map))
		message_error_exit("map has a gap (direction east)!\n");
	if (!is_enclosed_west(x, y, map))
		message_error_exit("map has a gap (direction west)\n");
}
