/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:36 by mac               #+#    #+#             */
/*   Updated: 2024/03/08 14:22:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	no_parser_inits(t_data *data)
{
	data->map->map[0] = "111111";
	data->map->map[1] = "100001";
	data->map->map[2] = "10N001";
	data->map->map[3] = "100001";
	data->map->map[4] = "111111";
	data->pos_x = 2;
	data->pos_y = 2;
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
}

void	raycast(t_data *data)
{
	no_parser_inits(data);
	
}
