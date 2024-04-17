/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:36 by mac               #+#    #+#             */
/*   Updated: 2024/04/18 01:28:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	position_and_direction(t_data *data, int x)
{
	data->hit = 0;
	data->camera_x = 2 * x / (double)WIDTH - 1;
	data->radir_y_x = data->dir_x + data->plane_x * data->camera_x;
	data->radir_y_y = data->dir_y + data->plane_y * data->camera_x;
	data->delta_dist_x = sqrt(1 + (data->radir_y_y * data->radir_y_y)
			/ (data->radir_y_x * data->radir_y_x));
	data->delta_dist_y = sqrt(1 + (data->radir_y_x * data->radir_y_x)
			/ (data->radir_y_y * data->radir_y_y));
	data->map_x = (int)data->pos_x;
	data->map_y = (int)data->pos_y;
	if (data->radir_y_x == 0)
		data->delta_dist_x = 1e30;
	else
		data->delta_dist_x = fabs(1 / data->radir_y_x);
	if (data->radir_y_y == 0)
		data->delta_dist_y = 1e30;
	else
		data->delta_dist_y = fabs(1 / data->radir_y_y);
}

void	step_and_side_dist(t_data *data)
{
	if (data->radir_y_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0 - data->pos_x)
			* data->delta_dist_x;
	}
	if (data->radir_y_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->pos_y - data->map_y)
			* data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0 - data->pos_y)
			* data->delta_dist_y;
	}
}

void	hit_a_wall(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map->map[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
}

void	calculate_wall_height(t_data *data)
{
	if (data->side == 0)
		data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
	else
		data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);
	data->line_height = (int)(HEIGHT / data->perp_wall_dist);
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	if (data->draw_start < 0)
		data->draw_start = 0;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	if (data->draw_end >= HEIGHT)
		data->draw_end = HEIGHT;
}

void	detect_hit(t_data *data)
{
	data->tex_num = data->map->map[data->map_y][data->map_x] - 1;
	if (data->side == 0)
		data->wallx = data->pos_y + data->perp_wall_dist * data->radir_y_y;
	else
		data->wallx = data->pos_x + data->perp_wall_dist * data->radir_y_x;
	data->wallx -= floor(data->wallx);
	data->texx = (int)(data->wallx * (double)64);
	if (data->side == 0 && data->radir_y_x > 0)
		data->texx = 64 - data->texx - 1;
	if (data->side == 1 && data->radir_y_y < 0)
		data->texx = 64 - data->texx - 1;
	data->step = 1.0 * 64 / data->line_height;
	data->tepos_x
		= (data->draw_start - HEIGHT / 2 + data->line_height / 2) * data->step;
}
