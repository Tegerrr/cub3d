/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbalasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:27:24 by sbalasho          #+#    #+#             */
/*   Updated: 2023/01/17 17:38:32 by sbalasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalpha(int a)
{
	if ((a > 64 && a < 91) || (a > 96 && a < 123))
	{
		return (1);
	}
	return (0);
}