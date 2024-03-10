/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:06:12 by mac               #+#    #+#             */
/*   Updated: 2024/03/10 23:14:44 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	updating_img(t_data *data)
{
	// data->image->img = mlx_new_image(data->mlx->mlx, WIDTH, HEIGHT);
	// data->image->img_addr = mlx_get_data_addr(data->image->img, \
	// 	&data->image->bits_per_pixel, &data->image->line_length, &data->image->endian);
	raycasting(data);
	return (0);
}

void	game(t_data *data)
{
	no_parser_inits(data);
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx_loop_hook(data->mlx->mlx, updating_img, data);
	mlx_loop(data->mlx->mlx);
}
