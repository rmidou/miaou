/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:08:17 by rmidou            #+#    #+#             */
/*   Updated: 2024/03/20 14:22:25 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_node	*createnode(void)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (newnode == NULL)
	{
		ft_printf("Erreur d'allocation de mémoire\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(newnode, sizeof(t_node));
	return (newnode);
}

void	freetree(t_node *root)
{
	if (root == NULL)
		return ();
	freetree(root->child_1);
	freetree(root->child_2);
	free(root);
}

t_node	*create_parent(t_node *child, char *line)
{
	child->parent = createnode();
	if (line[0] == '&')
		child->parent->type = TYPE_OPP_A;
	else
		child->parent->type = TYPE_OPP_B;
	child->parent->line = line;
	child->parent->child_1 = child;
	return (child->parent);
}

void	or(char *cmd2, t_node *root, char *str, int *i)
{
	t_node	*temp;

	temp = root->child_2;
	root->child_2 = create_parent(temp, cmd2);
	root->child_2->parent = root;
	(*i) += 2;
	add_child(root->child_2, read_node(str, i));
	ft_printf("c2 c2 : %s\n", root->child_2->child_2->line);
}

t_node	*create_node(char *cmd)
{
	t_node	*node;

	node = createnode();
	node->type = TYPE_CMD;
	node->line = cmd;
	return (node);
}
