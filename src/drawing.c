/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 19:39:38 by mac               #+#    #+#             */
/*   Updated: 2024/04/18 00:49:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_texture(t_data *data)
{
	if (data->side && data->radir_y_y > 0)
		return (0);
	else if (data->side && data->radir_y_y < 0)
		return (1);
	else if (!data->side && data->radir_y_x > 0)
		return (2);
	else if (!data->side && data->radir_y_x < 0)
		return (3);
	return (-1);
}

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->image->img_addr + (y * data->image->line_length + \
			x * (data->image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	texture_put(t_data *data, int x)
{
	char	*dst;
	int		y;
	int		texture;

	y = data->draw_start;
	texture = set_texture(data);
	while (y < data->draw_end)
	{
		data->tex_y = (int)data->tepos_x & (64 - 1);
		data->tepos_x += data->step;
		dst = data->walls_textures[texture]->img_addr + (data->tex_y * \
			data->walls_textures[texture]->line_length + \
			data->texx * (data->walls_textures[texture]->bits_per_pixel / 8));
		my_pixel_put(data, x, y++, *(unsigned int *)dst);
	}
}
