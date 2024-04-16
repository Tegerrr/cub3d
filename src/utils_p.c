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

void	print_double_char_arr(char **map)
{
	int	i;

	i = -1;
	if (!map)
		message_error_exit("empty array!");
	while (map[++i])
	{
		ft_putstr_fd(map[i], 1);
		ft_putstr_fd("\n", 1);
	}
}

int	has_only_white_space(char *str)
{
	int	i;

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
			message_error_exit(NLERR);
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
