/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:06:12 by mac               #+#    #+#             */
/*   Updated: 2024/04/16 14:44:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward_back(t_data *data, int keycode)
{
	if (keycode == 13)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->dir_x * data->move_speed)] != '1')
			data->pos_x += data->dir_x * data->move_speed;
		if (data->map->map[(int)(data->pos_y + data->dir_y * data->move_speed)]
			[(int)(data->pos_x)] != '1')
			data->pos_y += data->dir_y * data->move_speed;
	}
	else if (keycode == 1)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x - data->dir_x * data->move_speed)] != '1')
			data->pos_x -= data->dir_x * data->move_speed;
		if (data->map->map[(int)(data->pos_y - data->dir_y * data->move_speed)]
		[(int)(data->pos_x)] != '1')
			data->pos_y -= data->dir_y * data->move_speed;
	}
}

void	move_left_right(t_data *data, int keycode)
{
	if (keycode == 0)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x - data->plane_x * data->move_speed)] != '1')
			data->pos_x -= data->plane_x * data->move_speed;
		if (data->map->map[(int)(data->pos_y - data->plane_y * data->move_speed)]
		[(int)(data->pos_x)] != '1')
			data->pos_y -= data->plane_y * data->move_speed;
	}
	else if (keycode == 2)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->plane_x * data->move_speed)] != '1')
			data->pos_x += data->plane_x * data->move_speed;
		if (data->map->map[(int)(data->pos_y + data->plane_y * data->move_speed)]
		[(int)(data->pos_x)] != '1')
			data->pos_y += data->plane_y * data->move_speed;
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit(0);
	}
	if (keycode == 13 || keycode == 1)
		move_forward_back(data, keycode);
	if (keycode == 0 || keycode == 2)
		move_left_right(data, keycode);
	return (0);
}

int	updating_img(t_data *data)
{
	data->image = malloc(sizeof(t_img));
	data->image->img = mlx_new_image(data->mlx->mlx, WIDTH, HEIGHT);
	data->image->img_addr = mlx_get_data_addr(data->image->img, \
		&data->image->bits_per_pixel, &data->image->line_length, &data->image->endian);
	if (data->image->img == NULL)
	{
		printf("Error img\n");
		exit(0);
	}
	if (data->image->img_addr == NULL)
	{
		printf("Error img_addr\n");
		exit(0);
	}
	draw_floor_ceiling(data);
	raycasting(data);
	mlx_hook(data->mlx->win, 2, 1L << 2, key_press, data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->image->img, 0, 0);
	mlx_destroy_image(data->mlx->mlx, data->image->img);
	return (0);
}

void	game(t_data *data)
{
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "cub3d");
	inits(data);
	mlx_loop_hook(data->mlx->mlx, &updating_img, data);
	mlx_hook(data->mlx->win, 17, 1L << 2, close_game, NULL);
	mlx_loop(data->mlx->mlx);
}
