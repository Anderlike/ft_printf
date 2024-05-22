/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:46:32 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/04/29 17:22:44 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

void	free_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*current;

	node1 = (t_list *)malloc(sizeof(t_list));
	node1->content = ft_strdup("Node 1");
	node1->next = NULL;
	node2 = (t_list *)malloc(sizeof(t_list));
	node2->content = ft_strdup("Node 2");
	node2->next = NULL;
	node1->next = node2;
	printf("Lista sem ser apagada:\n");
	current = node1;
	while (current)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}
	ft_lstdelone(node1, &free_content);
	printf("Lista depois de ser apagada:\n");
	current = node2;
	while (current)
	{
		printf("%s\n", (char *)(current->content));
		current = current->next;
	}
	free(node2->content);
	free(node2);
	return (0);
}
*/