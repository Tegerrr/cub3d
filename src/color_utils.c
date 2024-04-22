/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:46:46 by sbalasho          #+#    #+#             */
/*   Updated: 2024/03/29 13:46:49 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

int	check_color_lines(char **color_lines)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (color_lines && color_lines[++i])
	{
		if (i > 2)
		{
			message_error_exit("color is misconfigured: more than 3 numbers\n");
			break ;
		}
		j = 0;
		while (color_lines[i][j] && ft_strchr(WHITE_CHARS, color_lines[i][j]))
			j++;
		while (color_lines[i][j])
		{
			if (!ft_isdigit(color_lines[i][j]))
				message_error_exit("color has a non-digit char\n");
			j++;
		}
	}
	if (i <= 2)
		message_error_exit("color is misconfigured: less than 3 numbers\n");
	return (0);
}

int	is_color_valid(t_color c)
{
	if (c.r < 0 || c.r > 255 || c.g < 0 || c.g > 255 || c.b < 0 || c.b > 255)
	{
		message_error_exit("color components must be in range 0 - 255\n");
		return (0);
	}
	return (1);
}

void	has_two_commas(char *line)
{
	int	i;
	int	commas;

	i = -1;
	commas = 0;
	while (line && line[++i])
	{
		if (line[i] == ',')
			commas++;
	}
	if (commas != 2)
		message_error_exit("color is misconfigured: must have two commas\n");
}

int	check_color(char *line, int *t_counter, int found_code, t_data *data)
{
	t_color	color;
	char	**color_lines;

	check_if_elem_is_doubled(*t_counter, found_code);
	*t_counter += found_code;
	line++;
	while (line && line[0] && ft_strchr(WHITE_CHARS, line[0]))
		line++;
	has_two_commas(line);
	color_lines = ft_split(line, ',');
	if (!color_lines)
		message_error_exit("split failed!");
	trim_double_char_arr(&color_lines, WHITE_CHARS);
	check_color_lines(color_lines);
	color.r = ft_atoi(color_lines[0]);
	color.g = ft_atoi(color_lines[1]);
	color.b = ft_atoi(color_lines[2]);
	is_color_valid(color);
	record_color(data, &color, found_code);
	free_double_char_arr(color_lines);
	return (0);
}

void	record_color(t_data *data, t_color *color, int found_code)
{
	if (found_code == FOUND_F)
	{
		data->map->floor->r = color->r;
		data->map->floor->g = color->g;
		data->map->floor->b = color->b;
	}
	else if (found_code == FOUND_C)
	{
		data->map->ceiling->r = color->r;
		data->map->ceiling->g = color->g;
		data->map->ceiling->b = color->b;
	}
	else
		message_error_exit("wrong code for color (never happens)\n");
}
