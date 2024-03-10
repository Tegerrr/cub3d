/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:12:16 by mac               #+#    #+#             */
/*   Updated: 2024/03/10 23:55:05 by mac              ###   ########.fr       */
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

# define WIDTH 1080
# define HEIGHT 720
# define NO "textures/Asset-7.xpm"
# define SO "textures/Asset-9.xpm"
# define WE "textures/Asset-11.xpm"
# define EA "textures/Asset-15.xpm"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct texture
{
	char *no;
	char *so;
	char *we;
	char *ea;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map
{
	char	*map[5];
	t_color	*ceiling;
	t_color *floor;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*img_addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_player
{
	int		x;
	int		y;
	char	orientation;
}	t_player;

typedef struct s_data
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	t_texture	*texture;
	t_img		*image;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		camera_x;
	double		camera_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			hit;
	int			side;
	int			step_x;
	int			step_y;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		time;		// time of current frame
	double		old_time;	// time of previous frame
}	t_data;

// init
void ft_mlx_init(t_data *data);
void	no_parser_inits(t_data *data);

// raycast
void	raycasting(t_data *data);

// parsing
int	parsing(char **argv, t_data *data);

// game
void	game(t_data *data);

// drawing
void	texture_put(t_data *data);

#endif