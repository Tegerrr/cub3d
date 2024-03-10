/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:23 by mac               #+#    #+#             */
/*   Updated: 2024/03/09 13:51:28 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	
	if (argc)
	{}
	argv = NULL;
	data = malloc(sizeof(t_data));
	data->mlx = malloc(sizeof(t_mlx));
	data->map = malloc(sizeof(t_map));
	data->player = malloc(sizeof(t_player));
	data->texture = malloc(sizeof(t_texture));
	parsing(argv, data);
	// ft_mlx_init(data);
	printf("hello\n");
	raycast(data);
	mlx_loop(data->mlx->mlx);
	return 0;
}
