/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:55:02 by lkoh              #+#    #+#             */
/*   Updated: 2024/06/05 14:53:30 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}
// #include <stdio.h>
// #include <stdlib.h>
// void print_list(t_list *lst) {
//     while (lst != NULL) {
//         printf("%d -> ", *(int *)lst->content);
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }

// int main() {
//     // Create content for the nodes
//     int values[] = {10, 20, 30, 40, 50};
//     t_list *head = NULL;  // Start with an empty list

//     // Create multiple nodes and link them together
//     for (int i = 0; i < 5; i++) {
//         t_list *new_node = ft_lstnew(&values[i]); 
//	 //Create a new node with content from values
//         if (new_node == NULL) {
//             perror("Failed to allocate memory for new node");
//             exit(EXIT_FAILURE);
//         }
//         ft_lstadd_front(&head, new_node); 
//	 //Add the new node to the front of the list
//     }

//     // Output the contents of the list
//     printf("The linked list contains:\n");
//     print_list(head);

//     // Free all nodes (not shown, assuming proper free function exists)
//     // Remember to free each node's dynamically allocated memory if necessary

//     return (0);
// }