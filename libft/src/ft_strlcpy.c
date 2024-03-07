/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:53:51 by timelkon          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count(char	*src)

{
	size_t	a;

	a = 0;
	while (src[a] != '\0')
	{
		a++;
	}
	return (a);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)

{
	size_t	num;
	size_t	a;

	a = 0;
	num = count(src);
	if (size == 0)
		return (num);
	if (size > 0)
	{
		while (a != size - 1 && src[a] != '\0')
		{
			dest[a] = src[a];
			a++;
		}
	}
	dest[a] = '\0';
	return (num);
}
