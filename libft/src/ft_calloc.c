/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:32:22 by timelkon          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	size_t	prd;
	void	*spc;

	prd = count * size;
	if (count && size)
	{
		if (prd < size || prd < count)
			return (NULL);
	}
	spc = malloc(prd);
	if (!spc)
		return (NULL);
	ft_bzero(spc, prd);
	return (spc);
}
