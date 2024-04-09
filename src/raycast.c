/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:36 by mac               #+#    #+#             */
/*   Updated: 2024/04/06 21:43:33 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int x;
	
	x = -1;
	while (++x < WIDTH)
	{
		data->hit = 0;
		// calculate ray position and direction
		data->camera_x = 2 * x / (double)WIDTH - 1; // x-coordinate in camera space
		// printf("camera_x == %f\n", data->camera_x);
		data->ray_dir_x = data->dir_x + data->plane_x * data->camera_x; // direction of ray
		data->ray_dir_y = data->dir_y + data->plane_y * data->camera_x; // direction of ray
		data->delta_dist_x = sqrt(1 + (data->ray_dir_y * data->ray_dir_y) / (data->ray_dir_x * data->ray_dir_x)); // length of ray from one x or y-side to next x or y-side
		data->delta_dist_y = sqrt(1 + (data->ray_dir_x * data->ray_dir_x) / (data->ray_dir_y * data->ray_dir_y)); // length of ray from one x or y-side to next x or y-side
		
		// which box of the map we're in
		data->map_x = (int)data->pos_x;
		data->map_y = (int)data->pos_y;
		// printf("map_x == %d\n map_y == %d\n", data->map_x, data->map_y);
		//length of ray from one x or y-side to next x or y-side
		if (data->ray_dir_x == 0)
			data->delta_dist_x = 1e30;
		else
			data->delta_dist_x = fabs(1 / data->ray_dir_x);
		if (data->ray_dir_y == 0)
			data->delta_dist_y = 1e30;
		else
			data->delta_dist_y = fabs(1 / data->ray_dir_y);

		// calculate step and initial sideDist
		if(data->ray_dir_x < 0)
		{
			data->step_x = -1;
			data->side_dist_x = (data->pos_x - data->map_x) * data->delta_dist_x;
		}
		else
		{
			data->step_x = 1;
			data->side_dist_x = (data->map_x + 1.0 - data->pos_x) * data->delta_dist_x;
		}
		if (data->ray_dir_y < 0)
		{
			data->step_y = -1;
			data->side_dist_y = (data->pos_y - data->map_y) * data->delta_dist_y;
		}
		else
		{
			data->step_y = 1;
			data->side_dist_y = (data->map_y + 1.0 - data->pos_y) * data->delta_dist_y;
		}
		while (data->hit == 0)
		{
			// jump to next map square, OR in x-direction, OR in y-direction
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
			// Check if ray has hit a wall
			if (data->map->map[data->map_x][data->map_y] == '1')
			{
				printf("it hit a wall\n");
				data->hit = 1;
			}
		}
		
		// Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
		if (data->side == 0)
			data->perp_wall_dist = (data->side_dist_x - data->delta_dist_x);
		else
			data->perp_wall_dist = (data->side_dist_y - data->delta_dist_y);

		//Calculate height of line to draw on screen
		data->line_height = (int)(HEIGHT / data->perp_wall_dist);
		// printf("line_height == %d\n", data->line_height);
		//calculate lowest and highest pixel to fill in current stripe
		data->draw_start = -data->line_height / 2 + HEIGHT / 2;
		// printf("draw_start == %d\n", data->draw_start);
		if (data->draw_start < 0)
			data->draw_start = 0;
		data->draw_end = data->line_height / 2 + HEIGHT / 2;
		if (data->draw_end >= HEIGHT)
			data->draw_end = HEIGHT;
		texture_put(data, x);
	}
}
