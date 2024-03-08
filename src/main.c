/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 23:11:23 by mac               #+#    #+#             */
/*   Updated: 2024/03/08 13:58:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	
	argc = NULL;
	argv = NULL;
	data = malloc(sizeof(t_data));
	// parsing(argv, data);
	ft_mlx_init(data);
	raycast(data);
	printf("hello\n");
	return 0;
}
