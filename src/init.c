/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:33 by mac               #+#    #+#             */
/*   Updated: 2024/04/18 00:56:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_file_to_img(t_data *data)
{
	int	i;
	int	size;

	size = 64;
	i = 0;
	data->walls_textures[2]->img = mlx_xpm_file_to_image
		(data->mlx->mlx, data->texture->ea, &size, &size);
	data->walls_textures[1]->img = mlx_xpm_file_to_image
		(data->mlx->mlx, data->texture->no, &size, &size);
	data->walls_textures[0]->img = mlx_xpm_file_to_image
		(data->mlx->mlx, data->texture->so, &size, &size);
	data->walls_textures[3]->img = mlx_xpm_file_to_image
		(data->mlx->mlx, data->texture->we, &size, &size);
	while (i < 4)
	{
		data->walls_textures[i]->img_addr
			= mlx_get_data_addr(data->walls_textures[i]->img,
				&data->walls_textures[i]->bits_per_pixel,
				&data->walls_textures[i]->line_length,
				&data->walls_textures[i]->endian);
		i++;
	}
}

void	inits(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->walls_textures[i] = malloc(sizeof(t_img));
		i++;
	}
	data->move_speed = 0.03;
	data->old_dir_x = 0;
	data->rot_speed = 0.03;
	data->w = 0;
	data->s = 0;
	data->a = 0;
	data->d = 0;
	texture_file_to_img(data);
}
