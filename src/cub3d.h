/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:12:16 by mac               #+#    #+#             */
/*   Updated: 2024/04/22 17:40:43 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WIDTH 1080
# define HEIGHT 720
# define HAS_ALL_COLORS_AND_TEXTURES 63
# define FOUND_NO 32
# define FOUND_SO 16
# define FOUND_WE 8
# define FOUND_EA 4
# define FOUND_C 2
# define FOUND_F 1
# define WHITE_CHARS "\t\n\x0b\x0c\r "
# define ORIENTATION_CHARS "NSEW"
# define VALID_MAP_CHARS " 10NSEW"
# define NLERR "nl the middle of map OR non-nl chars bwn 6 elems and map\n"
# define MAX_MAP_WIDTH 200
# define MAX_MAP_HEIGHT 100

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

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
	t_color	*floor;
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
	int		found_flag;
	char	orientation;
}	t_player;

typedef struct s_data
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*player;
	t_texture	*texture;
	t_img		*image;
	t_img		*walls_textures[4];
	int			tex_num;
	double		wallx;
	int			texx;
	int			tex_width;
	int			tex_height;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		radir_y_x;
	double		radir_y_y;
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
	double		step;
	double		perp_wall_dist;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		tepos_x;
	int			tex_y;
	double		time;
	double		old_time;
	double		move_speed;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}	t_data;

void			ft_mlx_init(t_data *data);
void			inits(t_data *data);
void			raycasting(t_data *data);
int				parsing(char *map_path, t_data *data);
void			orient(t_data *data);
void			orient_w(t_data *data);
void			message_error_exit(char *message);
int				is_file_extension_right(char *map_path, char *extension);
void			open_map_file(char *map_path, int *fd);
void			parse_textures_and_colors(int map_fd, t_data *data);
void			put_2d_map_into_double_arr(int map_fd, t_data *data);
void			print_double_char_arr(char **map);
int				no_double_new_line(char *str);
int				check_if_empty(char *big_str);
void			check_if_map_too_big(char **map);
int				has_not_only_white_space(char *str);
char			*check_t_path(char *line, int *texture_counter, int found_code);
int				find_a_texture(char *line, t_data *data, int *texture_counter);
void			parse_textures_and_colors(int map_fd, t_data *data);
int				has_only_white_space(char *str);
int				check_if_elem_is_doubled(int texture_counter, int found_code);
int				trim_double_char_arr(char ***ptr_to_double_ch_arr, char *set);
int				check_color(char *line, int *t_counter,
					int found_code, t_data *data);
void			record_color(t_data *data, t_color *color, int found_code);
int				is_color_valid(t_color c);
void			has_two_commas(char *line);
int				check_color_lines(char **color_lines);
void			check_if_map_has_right_chars(char **map, t_data *data);
void			record_player_position(t_data *data, int i, int j, char **map);
void			check_map_walls(char **map);
void			check_if_enclosed_by_walls(int x, int y, char **map);
int				is_enclosed_north(int x, int y, char **map);
int				is_enclosed_south(int x, int y, char **map);
int				is_enclosed_east(int x, int y, char **map);
int				is_enclosed_west(int x, int y, char **map);
void			game(t_data *data);
void			texture_put(t_data *data, int x);
void			draw_floor_ceiling(t_data *data);
unsigned long	set_up_color(int r, int g, int b);
int				close_game(void);
int				define_press(int keycode, t_data *data);
int				define_release(int keycode, t_data *data);
void			move_forward_back(t_data *data);
void			move_left_right(t_data *data);
void			rotate_left(t_data *data);
void			rotate_right(t_data *data);
void			detect_hit(t_data *data);
void			calculate_wall_height(t_data *data);
void			hit_a_wall(t_data *data);
void			step_and_side_dist(t_data *data);
void			position_and_direction(t_data *data, int x);
int				free_double_char_arr(char **arr);
void			free_all_data(t_data *data);
void			free_walls_textures(t_data *data);

#endif