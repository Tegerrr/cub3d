/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:56:12 by mac               #+#    #+#             */
/*   Updated: 2024/04/22 17:49:14 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	define_press(int keycode, t_data *data)
{
	if (keycode == 13)
		data->w = 1;
	if (keycode == 1)
		data->s = 1;
	if (keycode == 0)
		data->a = 1;
	if (keycode == 2)
		data->d = 1;
	if (keycode == 123)
		data->left = 1;
	if (keycode == 124)
		data->right = 1;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		close_game();
	}
	return (0);
}

int	define_release(int keycode, t_data *data)
{
	if (keycode == 13)
		data->w = 0;
	if (keycode == 1)
		data->s = 0;
	if (keycode == 0)
		data->a = 0;
	if (keycode == 2)
		data->d = 0;
	if (keycode == 123)
		data->left = 0;
	if (keycode == 124)
		data->right = 0;
	return (0);
}

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
