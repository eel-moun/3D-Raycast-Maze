/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:02:23 by ariahi            #+#    #+#             */
/*   Updated: 2022/08/07 19:33:31 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnlen(const char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!str[i])
			return (i);
		i++;
	}
	return (i);
}