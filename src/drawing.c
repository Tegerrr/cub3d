/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:39:38 by mac               #+#    #+#             */
/*   Updated: 2024/04/06 21:42:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_texture (t_data *data)
{
	if (data->side && data->ray_dir_y > 0)
		return (0);
	else if (data->side && data->ray_dir_y < 0)
		return (1);
	else if (!data->side && data->ray_dir_x > 0)
		return (2);
	else if (!data->side && data->ray_dir_x < 0)
		return (3);
	printf("side == %d\nray_dir_x == %f\nray_dir_y == %f\n", data->side, data->ray_dir_x, data->ray_dir_y);
	return (-1);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->img_addr + (y * data->image->line_length + \
			x * (data->image->bits_per_pixel / 8));
			// printf("img addr == %p\n", data->image->img_addr);
	// printf("bpp == %d\n", data->image->bits_per_pixel / 8);
	// printf("dst == %d\n", *(unsigned int *)dst);
	// printf("line_length == %d\n", data->image->line_length);
	*(unsigned int *)dst = color;
	// printf("color: %d\n is put at x: %d and y: %d\n", color, x, y);
	// printf("dst == %d\n", *(unsigned int *)dst);
	if (x || y || color || data)
		{}
}

void	texture_put(t_data *data, int x)
{
	char	*dst;
	int	y;
	int	texture;
	// uint32_t buffer[HEIGHT][WIDTH];
	
	// calculate value of wallx (where exactly the wall was hit)
	data->tex_num = data->map->map[data->map_x][data->map_y] - 1;
	if (data->side == 0)
		data->wallx = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		data->wallx = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	// printf("ray dir y == %f\nray dir x == %f\n", data->ray_dir_y, data->ray_dir_x);
	data->wallx -= floor(data->wallx);

	// x coordinate on the texture
	data->texx = (int)(data->wallx * (double)64);
	if (data->side == 0 && data->ray_dir_x > 0)
		data->texx = 64 - data->texx - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->texx = 64 - data->texx - 1;
	
	// how much to increase the texture coordinate per screen pixel
	data->step = 1.0 * 64 / data->line_height;
	// printf("line_height == %d\n", data->line_height);
	// starting texture coordinate
	data->tex_pos = (data->draw_start - HEIGHT / 2 + data->line_height / 2) * data->step;
	y = data->draw_start;
	// printf("draw_end == %d\n", y);
	texture = set_texture(data);
	// printf("texture == %d\n", texture);
	while (y < data->draw_end)
	{
		// printf("y is %d\n", y);
		// cast the texture coordinate to integer, and mask with (tex_height - 1) in case of overflow
		data->tex_y = (int)data->tex_pos & (64 - 1);
		// printf("tex_y == %d\n", data->tex_y);
		data->tex_pos += data->step;
		// printf("tex_pos == %f\n", data->tex_pos);
		// printf("walls_texture == %s\n", data->walls_textures[texture]);
		// printf("line_length == %d\n", data->walls_textures[texture]->line_length);
		dst = data->walls_textures[texture]->img_addr + (data->tex_y * \
			data->walls_textures[texture]->line_length + \
			data->texx * (data->walls_textures[texture]->bits_per_pixel / 8));
		// printf("x == %d\n", x);
		// printf("ll walls tex == %d\n", data->walls_textures[texture]->line_length);
		// printf("tex_x == %d\n", data->texx);
		my_pixel_put(data, x, y++, *(unsigned int *)dst);
	}
}
