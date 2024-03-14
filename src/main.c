/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:23 by mac               #+#    #+#             */
/*   Updated: 2024/03/10 17:08:09 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	
	if (argc != 2)
		message_error_exit("Error: wrong number of arguments!\n");
	argv = NULL;
	data = malloc(sizeof(t_data));
	data->mlx = malloc(sizeof(t_mlx));
	data->map = malloc(sizeof(t_map));
	data->player = malloc(sizeof(t_player));
	data->texture = malloc(sizeof(t_texture));
	parsing(argv[1], data);
	// ft_mlx_init(data);
	// printf("hello\n");
	game(data);
	return 0;
}
