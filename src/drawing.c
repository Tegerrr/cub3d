/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:39:38 by mac               #+#    #+#             */
/*   Updated: 2024/03/10 23:18:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_put(t_data *data)
{
	int color = 0;
	
	if (data->map->map[data->map_x][data->map_y] == 1)
		color = 0x00FF3333;
	else if (data->map->map[data->map_x][data->map_y] == 2)
		color = 0x00FF99FF;
	else if (data->map->map[data->map_x][data->map_y] == 3)
		color = 0x009966FF;
	else if (data->map->map[data->map_x][data->map_y] == 4)
		color = 0x009933CC;
	printf("f\n");
	mlx_pixel_put(data->mlx->mlx, data->mlx->win, data->draw_start, data->draw_end, color);
}
