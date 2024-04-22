/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:06:12 by mac               #+#    #+#             */
/*   Updated: 2024/04/22 17:40:53 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting(t_data *data)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		position_and_direction(data, x);
		step_and_side_dist(data);
		hit_a_wall(data);
		calculate_wall_height(data);
		texture_put(data, x);
		detect_hit(data);
	}
}

int	move(t_data *data)
{
	move_forward_back(data);
	move_left_right(data);
	rotate_left(data);
	rotate_right(data);
	return (0);
}

int	updating_img(t_data *data)
{
	t_img	local_img;

	data->image = &local_img;
	data->image->img = mlx_new_image(data->mlx->mlx, WIDTH, HEIGHT);
	data->image->img_addr = mlx_get_data_addr(data->image->img,
			&data->image->bits_per_pixel,
			&data->image->line_length, &data->image->endian);
	if (data->image->img == NULL)
		message_error_exit("mlx_new_image failed\n");
	if (data->image->img_addr == NULL)
		message_error_exit("mlx_get_data_addr failed\n");
	draw_floor_ceiling(data);
	raycasting(data);
	mlx_hook(data->mlx->win, 2, 1L << 2, define_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 3, define_release, data);
	move(data);
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->win, data->image->img, 0, 0);
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
