/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valentin <valentin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:00:28 by valentin          #+#    #+#             */
/*   Updated: 2021/02/09 20:36:05 by valentin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_shell(u_char status, t_shell *shell)
{
	free_read_state(&(shell->read_state));
	free_cltoks(&(shell->cltoks));
	free_cmdg(shell->cmdg);
	shell->cmdg = NULL;
	free_lpids(shell->lpids);
	free_env(shell->env);
	free(shell);
	exit(status);
}

void	pcustom_error(char *str_error)
{
	ft_putstr_fd(str_error, 2);
}

void	perrno(void)
{
	ft_putstr_fd(strerror(errno), 2);
}

void	pcustom_error_exit(char *str_error, t_shell *shell)
{
	pcustom_error(str_error);
	exit_shell(EXIT_FAILURE, shell);
}

void	perrno_exit(t_shell *shell)
{
	perrno();
	exit_shell(EXIT_FAILURE, shell);
}
