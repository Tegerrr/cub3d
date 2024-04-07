/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:56:12 by mac               #+#    #+#             */
/*   Updated: 2024/03/08 14:56:13 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void    print_double_char_arr(char **map)
{
	int i;

	i = -1;
	if (!map)
		message_error_exit("empty array!");
	while (map[++i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putstr_fd("\n", 1);
	}
}

int has_only_white_space(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != ' '
			&& !(str[i] >= 9 && str[i] <= 13))
			return (0);
	}
	return (1);
}


int	no_double_new_line(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = ft_strtrim(str, "\n");
	while (tmp && tmp[i] && tmp[i + 1])
	{
		if (tmp[i] == '\n' && tmp[i + 1] == '\n')
		{
			free(tmp);
			message_error_exit("empty new line the middle of map OR non-new line chars between 6 elems and map\n");
		}
		i++;
	}
	free(tmp);
	return (0);
}

int	check_if_empty(char *big_str)
{
	int	i;

	i = 0;
	if (!*big_str)
		message_error_exit("map is empty!\n");
	while (big_str[i])
	{
		if (big_str[i] != '\n')
			return (0);
		i++;
	}
	message_error_exit("map is empty except for new lines!\n");
	return (1);
}

int	free_double_char_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (1);
	while (arr && arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
	return (0);
}

int trim_double_char_arr(char ***ptr_to_double_ch_arr, char *set)
{
	int	i;
	char *tmp;

	i = -1;
	tmp = NULL;
	if (!ptr_to_double_ch_arr)
		return (1);
	while ((*ptr_to_double_ch_arr)[++i])
	{
		tmp = ft_strtrim((*ptr_to_double_ch_arr)[i], set);
		if (!tmp)
			message_error_exit("malloc failed in ft_strtrim\n");
		free((*ptr_to_double_ch_arr)[i]);
		(*ptr_to_double_ch_arr)[i] = tmp;
	}
	return (0);
}
void	print_texture_color_data(t_data *data)
{
	printf(".......\n");
	printf("NO: %s\n", data->texture->no);
	printf("SO: %s\n", data->texture->so);
	printf("EA: %s\n", data->texture->ea);
	printf("WE: %s\n", data->texture->we);
	printf("F: %i, %i, %i\n", data->map->floor->r, data->map->floor->g, data->map->floor->b);
	printf("C: %i, %i, %i\n", data->map->ceiling->r, data->map->ceiling->g, data->map->ceiling->b);
	printf(".......\n");
}