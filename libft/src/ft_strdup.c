/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:12:42 by timelkon          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)

{
	char	*spc;
	char	*str;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	str = (char *)s1;
	spc = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!spc)
		return (NULL);
	while (str[i] != '\0')
	{
		spc[i] = str[i];
		i++;
	}
	spc[i] = '\0';
	return (spc);
}
