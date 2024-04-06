/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:23 by mac               #+#    #+#             */
/*   Updated: 2024/03/24 21:13:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int i = 0;
	
	if (argc)
	{}
	argv = NULL;
	data = malloc(sizeof(t_data));
	data->mlx = malloc(sizeof(t_mlx));
	data->map = malloc(sizeof(t_map));
	data->player = malloc(sizeof(t_player));
	data->texture = malloc(sizeof(t_texture));
	while (data->walls_textures[i])
	{
		data->walls_textures[i] = malloc(sizeof(t_img));
		i++;
	}
	parsing(argv, data);
	// ft_mlx_init(data);
	// printf("hello\n");
	game(data);
	return 0;
}
