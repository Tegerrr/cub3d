/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:01:41 by timelkon          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst1, const void *src1, size_t len)

{
	char	*dst;
	char	*src;
	size_t	i;

	i = 0;
	dst = (char *) dst1;
	src = (char *) src1;
	if (dst < src)
	{
		while (i < len)
		{
		dst[i] = src[i];
		i++;
		}
	}
	else if (dst > src)
	{
		i = len - 1;
		while (i < len)
		{
			dst[i] = src[i];
			i--;
		}
	}
	return (dst);
}
