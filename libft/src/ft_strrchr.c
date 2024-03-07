/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:55:54 by timelkon          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)

{
	char	*cop;
	int		num;

	cop = (char *)s;
	num = ft_strlen(cop);
	while (*cop != '\0')
		cop++;
	while (num >= 0)
	{
		if (*cop == (char)c)
			return (cop);
		cop--;
		num--;
	}
	return (0);
}
