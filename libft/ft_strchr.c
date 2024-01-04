/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mofaisal <mofaisal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:58:48 by mofaisal          #+#    #+#             */
/*   Updated: 2023/04/17 17:44:24 by mofaisal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			return (0);
	}
	return (1);
}

int	ft_wallcheck(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && !(str[i] >= 50 && str[i] <= 126))
			i++;
		if (str[i] == (str[i] >= 50 && str[i] <= 126))
			return (0);
	}
	return (1);
}
