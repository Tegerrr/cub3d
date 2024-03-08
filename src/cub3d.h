/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:12:16 by mac               #+#    #+#             */
/*   Updated: 2024/03/08 14:06:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../mlx/mlx.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	**map;
	t_color	*ceiling;
	t_color *floor;
}	t_map;

typedef struct s_data
{
	t_mlx	*mlx;
	t_map	*map;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_data;

// init
void ft_mlx_init(t_data *data);

// raycast
void	raycast(t_data *data)

#endif