/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:13:50 by valentin          #+#    #+#             */
/*   Updated: 2021/01/08 16:45:57 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_pwd(t_shell *shell)
{
	ft_printf("%s\n", get_envval("PWD", shell->env));
}

void	builtin_cd(t_cmd *cmd, t_shell *shell)
{
	chdir((cmd->args)[1]);
	update_pwd(shell);
	// TODO : error management
}
