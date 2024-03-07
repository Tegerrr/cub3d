/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:33:15 by timelkon          #+#    #+#             */
/*   Updated: 2024/03/07 16:43:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)

{
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (0);
	if (!*s)
		return (ft_strdup(""));
	j = ft_strlen(s);
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	while (j > i && ft_strchr(set, s[j]))
		j--;
	return (ft_substr(s, i, (j - i + 1)));
}
