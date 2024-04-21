/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_color_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:42:34 by sbalasho          #+#    #+#             */
/*   Updated: 2024/03/26 18:42:37 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	check_if_elem_is_doubled(int texture_counter, int found_code)
{
	int	power_of_two;
	int	mask;

	power_of_two = 0;
	while (found_code > 1)
	{
		found_code >>= 1;
		power_of_two++;
	}
	mask = 1 << power_of_two;
	if ((texture_counter & mask) != 0)
	{
		message_error_exit("Same texture or color specified more than once\n");
		return (1);
	}
	else
		return (0);
}

char	*check_t_path(char *line, int *texture_counter, int found_code)
{
	int	fd;

	check_if_elem_is_doubled(*texture_counter, found_code);
	*texture_counter += found_code;
	line += 2;
	while (line && ft_strchr(WHITE_CHARS, line[0]))
		line++;
	fd = open(line, O_RDONLY);
	if (fd < 0)
		message_error_exit("wrong texture path!\n");
	if (close(fd) < 0)
		message_error_exit("close function failed!\n");
	is_file_extension_right(line, ".xpm");
	return (line);
}

int	find_a_texture(char *line, t_data *data, int *t_counter)
{
	if (!ft_strncmp(line, "NO", 2))
		data->texture->no = ft_strdup(check_t_path(line, t_counter, FOUND_NO));
	else if (!ft_strncmp(line, "SO", 2))
		data->texture->so = ft_strdup(check_t_path(line, t_counter, FOUND_SO));
	else if (!ft_strncmp(line, "WE", 2))
		data->texture->we = ft_strdup(check_t_path(line, t_counter, FOUND_WE));
	else if (!ft_strncmp(line, "EA", 2))
		data->texture->ea = ft_strdup(check_t_path(line, t_counter, FOUND_EA));
	else if (!ft_strncmp(line, "F", 1))
		check_color(line, t_counter, FOUND_F, data);
	else if (!ft_strncmp(line, "C", 1))
		check_color(line, t_counter, FOUND_C, data);
	else
		return (1);
	return (0);
}

void	parse_textures_and_colors(int map_fd, t_data *data)
{
	int		texture_counter;
	char	*tmp;
	char	*tmp2;

	texture_counter = 0;
	while (1)
	{
		if (texture_counter == HAS_ALL_COLORS_AND_TEXTURES)
			break ;
		tmp = get_next_line(map_fd);
		if (!tmp)
			break ;
		if (has_only_white_space(tmp))
			free(tmp);
		else
		{
			tmp2 = ft_strtrim(tmp, WHITE_CHARS);
			if (find_a_texture(tmp2, data, &texture_counter) == 1)
				message_error_exit("A line has wrong specifier\n");
			free(tmp);
			free(tmp2);
		}
	}
	if (texture_counter != HAS_ALL_COLORS_AND_TEXTURES)
		message_error_exit("Not all textures and colors are present\n");
}
