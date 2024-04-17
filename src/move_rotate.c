/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 01:26:52 by mac               #+#    #+#             */
/*   Updated: 2024/04/18 01:26:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_back(t_data *data)
{
	if (data->w == 1)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->dir_x * data->move_speed)] != '1')
			data->pos_x += data->dir_x * data->move_speed;
		if (data->map->map[(int)(data->pos_y + data->dir_y * data->move_speed)]
			[(int)(data->pos_x)] != '1')
			data->pos_y += data->dir_y * data->move_speed;
	}
	if (data->s == 1)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x - data->dir_x * data->move_speed)] != '1')
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->map->map[(int)(data->pos_y - data->dir_y * data->move_speed)]
		[(int)(data->pos_x)] != '1')
			data->pos_y -= data->dir_y * data->move_speed;
	}
}

void	move_left_right(t_data *data)
{
	if (data->a == 1)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x - data->plane_x * data->move_speed)] != '1')
			data->pos_x -= data->plane_x * data->move_speed;
		if (data->map->map
			[(int)(data->pos_y - data->plane_y * data->move_speed)]
				[(int)(data->pos_x)] != '1')
			data->pos_y -= data->plane_y * data->move_speed;
	}
	if (data->d == 1)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->plane_x * data->move_speed)] != '1')
			data->pos_x += data->plane_x * data->move_speed;
		if (data->map->map
			[(int)(data->pos_y + data->plane_y * data->move_speed)]
				[(int)(data->pos_x)] != '1')
			data->pos_y += data->plane_y * data->move_speed;
	}
}

void	rotate_right(t_data *data)
{
	if (data->right == 1)
	{
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x
			* cos(data->rot_speed) - data->dir_y * sin(data->rot_speed);
		data->dir_y = data->old_dir_x
			* sin(data->rot_speed) + data->dir_y * cos(data->rot_speed);
		data->old_plane_x = data->plane_x;
		data->plane_x = data->plane_x
			* cos(data->rot_speed) - data->plane_y * sin(data->rot_speed);
		data->plane_y = data->old_plane_x
			* sin(data->rot_speed) + data->plane_y * cos(data->rot_speed);
	}
}

void	rotate_left(t_data *data)
{
	if (data->left == 1)
	{
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x
			* cos(-data->rot_speed) - data->dir_y * sin(-data->rot_speed);
		data->dir_y = data->old_dir_x
			* sin(-data->rot_speed) + data->dir_y * cos(-data->rot_speed);
		data->old_plane_x = data->plane_x;
		data->plane_x = data->plane_x
			* cos(-data->rot_speed) - data->plane_y * sin(-data->rot_speed);
		data->plane_y = data->old_plane_x
			* sin(-data->rot_speed) + data->plane_y * cos(-data->rot_speed);
	}
}
