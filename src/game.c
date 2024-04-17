/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:06:12 by mac               #+#    #+#             */
/*   Updated: 2024/04/18 00:22:08 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	define_press(int keycode, t_data *data)
{
	if (keycode == 13)
		data->w = 1;
	if (keycode == 1)
		data->s = 1;
	if (keycode == 0)
		data->a = 1;
	if (keycode == 2)
		data->d = 1;
	if (keycode == 123)
		data->left = 1;
	if (keycode == 124)
		data->right = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit(0);
	}
	return 0;
}

int	define_release(int keycode, t_data *data)
{
	if (keycode == 13)
		data->w = 0;
	if (keycode == 1)
		data->s = 0;
	if (keycode == 0)
		data->a = 0;
	if (keycode == 2)
		data->d = 0;
	if (keycode == 123)
		data->left = 0;
	if (keycode == 124)
		data->right = 0;
	return 0;
}

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
	else if (data->s == 1)
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
		if (data->map->map[(int)(data->pos_y - data->plane_y * data->move_speed)]
		[(int)(data->pos_x)] != '1')
			data->pos_y -= data->plane_y * data->move_speed;
	}
	else if (data->d == 1)
	{
		if (data->map->map[(int)(data->pos_y)]
		[(int)(data->pos_x + data->plane_x * data->move_speed)] != '1')
			data->pos_x += data->plane_x * data->move_speed;
		if (data->map->map[(int)(data->pos_y + data->plane_y * data->move_speed)]
		[(int)(data->pos_x)] != '1')
			data->pos_y += data->plane_y * data->move_speed;
	}
}

void	rotate_left_right(t_data *data)
{
	if (data->left == 1)
	{
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rot_speed) - data->dir_y * sin(-data->rot_speed);
		data->dir_y = data->old_dir_x * sin(-data->rot_speed) + data->dir_y * cos(-data->rot_speed);
		data->old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(-data->rot_speed) - data->plane_y * sin(-data->rot_speed);
		data->plane_y = data->old_plane_x * sin(-data->rot_speed) + data->plane_y * cos(-data->rot_speed);
	}
	if (data->right == 1)
	{
		data->old_dir_x = data->dir_x;
		data->dir_x = data->dir_x * cos(data->rot_speed) - data->dir_y * sin(data->rot_speed);
		data->dir_y = data->old_dir_x * sin(data->rot_speed) + data->dir_y * cos(data->rot_speed);
		data->old_plane_x = data->plane_x;
		data->plane_x = data->plane_x * cos(data->rot_speed) - data->plane_y * sin(data->rot_speed);
		data->plane_y = data->old_plane_x * sin(data->rot_speed) + data->plane_y * cos(data->rot_speed);
	}
}

int	move(t_data *data)
{
		move_forward_back(data);
		move_left_right(data);
		rotate_left_right(data);
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
	mlx_hook(data->mlx->win, 2, 1L << 2, define_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 3, define_release, data);
	move(data);
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
