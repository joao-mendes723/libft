/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:36:32 by jmendes           #+#    #+#             */
/*   Updated: 2021/10/31 15:30:52 by jmendes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		copy = ft_lstnew(f(lst->content));
		if (!copy)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, copy);
		lst = lst->next;
	}
	return (new);
}
