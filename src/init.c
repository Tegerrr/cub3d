/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:33 by mac               #+#    #+#             */
/*   Updated: 2024/04/09 14:14:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_mlx_init(t_data *data)
{
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx, WIDTH, HEIGHT, "cub3d");
	mlx_loop(data->mlx->mlx);
}
void	texture_file_to_img(t_data *data)
{
	int i;
	int size;

	size = 64;
	i = 0;
		data->walls_textures[0]->img = mlx_xpm_file_to_image(data->mlx->mlx, data->texture->ea, &size, &size);
		data->walls_textures[1]->img = mlx_xpm_file_to_image(data->mlx->mlx, data->texture->no, &size, &size);
		data->walls_textures[2]->img = mlx_xpm_file_to_image(data->mlx->mlx, data->texture->so, &size, &size);
		data->walls_textures[3]->img = mlx_xpm_file_to_image(data->mlx->mlx, data->texture->we, &size, &size);
	while (i < 4)
	{
		data->walls_textures[i]->img_addr = mlx_get_data_addr(data->walls_textures[i]->img, \
			&data->walls_textures[i]->bits_per_pixel, &data->walls_textures[i]->line_length, \
				&data->walls_textures[i]->endian);
		i++;
	}
}

void	no_parser_inits(t_data *data)
{
	int i = 0;
	// while (data->map->map[i])
	// {
	// 	data->map->map[i] = malloc(sizeof(char) * 6);
	// 	i++;
	// }
	// i = 0;
	// data->map->map[0] = "111111";
	// data->map->map[1] = "100001";
	// data->map->map[2] = "100001";
	// data->map->map[3] = "100001";
	// data->map->map[4] = "111111";
	// data->pos_x = 2;
	// data->pos_y = 3;
	// data->dir_x = 0;
	// data->dir_y = 1;
	// data->plane_x = 0.66;
	// data->plane_y = 0;
	// data->texture->no = "textures/bluestone.xpm";
	// data->texture->so = "textures/eagle.xpm";
	// data->texture->we = "textures/greystone.xpm";
	// data->texture->ea = "textures/redbrick.xpm";
	while (i < 4)
	{
		data->walls_textures[i] = malloc(sizeof(t_img));
		i++;
	}
	texture_file_to_img(data);
}
