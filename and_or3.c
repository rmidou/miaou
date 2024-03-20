/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmidou <rmidou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:13:06 by rmidou            #+#    #+#             */
/*   Updated: 2024/03/20 14:24:42 by rmidou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*parse_command(char *str, int *i)
{
	char	*cmd;
	int		quotes;

	cmd = NULL;
	quotes = 0;
	while (str[*i + 1])
	{
		if (quotes != 1 && ((str[*i] == '&' && str[*i + 1] == '&')
				|| (str[*i] == '|' && str[*i + 1] == '|')))
			break ;
		if (str[*i] == '"' && quotes == 0)
			quotes = 1;
		else if (str[*i] == '"' && quotes == 1)
			quotes = 0;
		if (cmd != NULL || !ft_isspace(str[*i]))
			cmd = str_addc(cmd, str[*i]);
		(*i)++;
	}
	if ((str[*i] != '|' && str[*i] != '&') && !ft_isspace(str[*i]))
		cmd = str_addc(cmd, str[*i]);
	return (cmd);
}

t_node	*manage_parent(char	*cmd1, t_node *root, char *str, int *i)
{
	if (root->type == TYPE_OPP_B && !(root->prio) && (str[*i] == '&'
			&& str[*i + 1] == '&'))
		or(cmd1, root, str, i);
	else
	{
		root = create_parent(root, cmd1);
		(*i) += 2;
	}
	return (root);
}
