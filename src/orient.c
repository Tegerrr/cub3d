/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orient.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:47:49 by sbalasho          #+#    #+#             */
/*   Updated: 2024/04/16 17:48:34 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	orient_w(t_data *data)
{
	if (data->player->orientation == 'W')
	{
		data->dir_x = -1.0000000000001;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = -0.66;
	}
}

void	orient(t_data *data)
{
	if (data->player->orientation == 'N')
	{
		data->dir_x = 0;
		data->dir_y = -1.0000000000001;
		data->plane_x = 0.66;
		data->plane_y = 0;
	}
	if (data->player->orientation == 'S')
	{
		data->dir_x = 0;
		data->dir_y = 1.0000000000001;
		data->plane_x = -0.66;
		data->plane_y = 0;
	}
	if (data->player->orientation == 'E')
	{
		data->dir_x = 1.0000000000001;
		data->dir_y = 0;
		data->plane_x = 0;
		data->plane_y = 0.66;
	}
	orient_w(data);
}
