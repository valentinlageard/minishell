/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:20:19 by valentin          #+#    #+#             */
/*   Updated: 2020/12/01 16:35:38 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*new_cmd(void)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd *)malloc(sizeof(t_cmd))))
		return (NULL);
	cmd->cmd = NULL;
	cmd->args = NULL;
	cmd->is_valid = 1;
	cmd->is_builtin = 0;
	return (cmd);
}

void	free_cmd(t_cmd *cmd)
{
	free(cmd->cmd);
	ft_free_words(cmd->args);
	free(cmd);
}

void	print_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	ft_printf("\tCMD : %s\n", cmd->cmd);
	ft_printf("\tARGS :\n");
	while ((cmd->args)[i])
	{
		ft_printf("\t- args[%d] : %s\n", i, (cmd->args)[i]);
		i++;
	}
	ft_printf("\tIS_VALID : %d\n", cmd->is_valid);
	ft_printf("\tIS_BUILTIN : %d\n", cmd->is_builtin);
}

void	print_cmds(t_cmd **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
	{
		ft_printf("-> cmds[%d] :\n", i);
		print_cmd(cmds[i]);
		i++;
	}
}