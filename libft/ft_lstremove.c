/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 02:36:09 by ariahi            #+#    #+#             */
/*   Updated: 2023/01/02 10:37:08 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **lst, t_list *to_rm)
{
	t_list	*pre;
	t_list	*cur;

	pre = NULL;
	cur = *lst;
	while (cur)
	{
		if (cur == to_rm)
		{
			if (pre)
				pre->next = cur->next;
			else
				*lst = cur->next;
			return ;
		}
		pre = cur;
		cur = cur->next;
	}
}
