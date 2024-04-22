/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:23 by mac               #+#    #+#             */
/*   Updated: 2024/04/15 18:53:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	if (argc != 2)
		message_error_exit("Error: wrong number of arguments!\n");
	data = malloc(sizeof(t_data));
	data->mlx = malloc(sizeof(t_mlx));
	data->map = malloc(sizeof(t_map));
	data->player = malloc(sizeof(t_player));
	data->texture = malloc(sizeof(t_texture));
	data->map->floor = malloc(sizeof(t_color));
	data->map->ceiling = malloc(sizeof(t_color));
	while (data->walls_textures[i])
	{
		data->walls_textures[i] = malloc(sizeof(t_img));
		i++;
	}
	parsing(argv[1], data);
	game(data);
	return (0);
}
