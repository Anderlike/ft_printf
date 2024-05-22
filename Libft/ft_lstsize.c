/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:24:38 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/04/29 17:23:07 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list *node1 = (t_list *)malloc(sizeof(t_list));
	node1->next = NULL;
	t_list *node2 = (t_list *)malloc(sizeof(t_list));
	node2->next = NULL;
	t_list *node3 = (t_list *)malloc(sizeof(t_list));
	node2->next = NULL;

	node1->next = node2;
	node2->next = node3;

	printf("Tamanho da list: %d\n", ft_lstsize(node1));

	free(node1);
	free(node2);
	free(node3);

	return (0);
}*/