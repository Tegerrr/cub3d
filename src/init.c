/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:33 by mac               #+#    #+#             */
/*   Updated: 2024/03/10 19:57:32 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_mlx_init(t_data *data)
{
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx_loop(data->mlx->mlx);
}

void	no_parser_inits(t_data *data)
{
	int i = 0;
	while (data->map->map[i])
	{
		data->map->map[i] = malloc(sizeof(char) * 6);
		i++;
	}
	data->map->map[0] = "111111";
	data->map->map[1] = "400002";
	data->map->map[2] = "400002";
	data->map->map[3] = "400002";
	data->map->map[4] = "433332";
	data->pos_x = 2;
	data->pos_y = 2;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
	data->hit = 0;
}
