/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:56:12 by mac               #+#    #+#             */
/*   Updated: 2024/04/06 22:01:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_game(void)
{
	exit(0);
	return (0);
}

int	trim_double_char_arr(char ***ptr_to_double_ch_arr, char *set)
{
	int		i;
	char	*tmp;

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
	printf("F: %i, %i, %i\n", data->map->floor->r,
		data->map->floor->g, data->map->floor->b);
	printf("C: %i, %i, %i\n", data->map->ceiling->r,
		data->map->ceiling->g, data->map->ceiling->b);
	printf(".......\n");
}
