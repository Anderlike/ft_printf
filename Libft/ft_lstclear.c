/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:08:15 by aaleixo-          #+#    #+#             */
/*   Updated: 2024/04/29 17:22:40 by aaleixo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current)
	{
		del(current->content);
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}
/*
#include <stdio.h>

void	free_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *head = (t_list *)malloc(sizeof(t_list));
	head->content = malloc(sizeof(int));
	*(int *)head->content = 1;
	head->next = NULL;

	t_list *second_node = (t_list *)malloc(sizeof(t_list));
	second_node->content = malloc(sizeof(int));
	*(int *)second_node->content = 2;
	second_node->next = NULL;
	ft_lstadd_back(&head, second_node);

	printf("Lista sem ser apagada:\n");
	t_list *current = head;
	while (current)
	{
		printf("%d ", *(int *)(current->content));
		current = current->next;
	}
	ft_lstclear(&head, &free_content);

	printf("\nLista depois de ser apagada:\n");
	current = head;
	while (current)
	{
		printf("%d \n", *(int *)(current->content));
		current = current->next;
	}
	return (0);
}*/