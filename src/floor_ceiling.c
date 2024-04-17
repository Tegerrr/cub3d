/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceiling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:43:40 by sbalasho          #+#    #+#             */
/*   Updated: 2024/04/09 14:12:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	set_up_color(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

void	draw_floor_ceiling(t_data *data)
{
	unsigned int		*dest;
	unsigned int		i;
	unsigned long		ceiling_rgb;
	unsigned long		floor_rgb;

	dest = (unsigned int *)data->image->img_addr;
	ceiling_rgb = set_up_color(data->map->ceiling->r,
			data->map->ceiling->g, data->map->ceiling->b);
	floor_rgb = set_up_color(data->map->floor->r,
			data->map->floor->g, data->map->floor->b);
	i = WIDTH * HEIGHT / 2 + 1;
	while (i-- > 0)
		*dest++ = ceiling_rgb;
	i = WIDTH * HEIGHT / 2 + 1;
	while (i-- > 0)
		*dest++ = floor_rgb;
}
