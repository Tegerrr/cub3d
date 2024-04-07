/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enclosed_nswe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:41:36 by sbalasho          #+#    #+#             */
/*   Updated: 2024/04/01 17:41:39 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"


int	is_enclosed_north(int x, int y, char **map)
{
	int	i;
	int	enslosed_no;

	i = y;
	enslosed_no = 0;
	while (--i >= 0)
	{
		if (map[i] && (ft_strlen(map[i]) >= (unsigned long)x) && map[i][x])
		{
			if (map[i][x] == ' ')
				break ;
			if (map[i][x] == '1')
			{
				enslosed_no = 1;
				break ;
			}
		}
		else
			break ;
	}
	return (enslosed_no);
}

int	is_enclosed_south(int x, int y, char **map)
{
	int	i;
	int	enslosed_so;

	i = y;
	enslosed_so = 0;
	while (map[++i])
	{
		if (map[i] && ft_strlen(map[i]) >= (unsigned long)x && map[i][x])
		{
			if (map[i][x] == ' ')
				break ;
			if (map[i][x] == '1')
			{
				enslosed_so = 1;
				break ;
			}
		}
		else
			break ;
	}
	return (enslosed_so);
}

int	is_enclosed_east(int x, int y, char **map)
{
	int	j;
	int	enslosed_ea;

	j = x;
	enslosed_ea = 0;
	while (map[y][++j])
	{
		if (map[y][j] == ' ')
			break ;
		if (map[y][j] == '1')
		{
			enslosed_ea = 1;
			break ;
		}
	}
	return (enslosed_ea);
}

int	is_enclosed_west(int x, int y, char **map)
{
	int	j;
	int	enslosed_we;

	j = x;
	enslosed_we = 0;
	while (--j >= 0)
	{
		if (map[y][j] == ' ')
			break ;
		if (map[y][j] == '1')
		{
			enslosed_we = 1;
			break ;
		}
	}
	return (enslosed_we);
}
/*
void	check_if_enclosed_by_walls(int x, int y, char **map)
{
	if (check_if_enclosed_vertical(x, y, map) != 2)
		message_error_exit("nothern or southern wall has a gap\n");
	if (check_if_enclosed_horisontal(x, y, map) != 2)
		message_error_exit("eastern or western wall has a gap\n");
}


int	check_if_enclosed_vertical(int x, int y, char **map)
{
	int	i;
	int	enslosed_no;
	int	enslosed_so;

	i = y;
	enslosed_no = 0;
	enslosed_so = 0;
	while (map[--i])
	{
		if (map[i] && ft_strlen(map[i]) >= (unsigned long)x && map[i][x])
		{
			if (map[i][x] == ' ')
				break ;
			if (map[i][x] == '1')
			{
				enslosed_no = 1;
				break ;
			}
		}
	}
	i = y;
	while (map[++i])
	{
		if (map[i] && ft_strlen(map[i]) >= (unsigned long)x && map[i][x])
		{
			if (map[i][x] == ' ')
				break ;
			if (map[i][x] == '1')
			{
				enslosed_so = 1;
				break ;
			}
		}
	}
	return (enslosed_no + enslosed_so);
}

int	check_if_enclosed_horisontal(int x, int y, char **map)
{
	int	j;
	int	enslosed_we;
	int	enslosed_ea;

	j = x;
	enslosed_we = 0;
	enslosed_ea = 0;
	while (map[y][++j])
	{
		if (map[y][j] == ' ')
			break ;
		if (map[y][j] == '1')
		{
			enslosed_ea = 1;
			break ;
		}
	}
	j = x;
	while (--j >= 0)
	{
		if (map[y][j] == ' ')
			break ;
		if (map[y][j] == '1')
		{
			enslosed_we = 1;
			break ;
		}
	}
	return (enslosed_ea + enslosed_we);
}
*/