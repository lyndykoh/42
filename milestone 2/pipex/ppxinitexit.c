/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppxinitexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:30:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/23 20:15:14 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_ppx *pipex, int argc, char **argv, char **envp)
{
	if (*envp == NULL)
		pipex->nullenvp = 1;
	else
		pipex->nullenvp = 0;
	pipex->envp = envp;
	pipex->argv = argv;
	pipex->argc = argc;
	pipex->heredoc = (!(ft_strncmp(pipex->argv[1], "here_doc", 8)));
	pipex->cmd_no = pipex->argc - 3 - pipex->heredoc;
	pipex->oldpipe[0] = -1;
	pipex->oldpipe[1] = -1;
	pipex->newpipe[0] = -1;
	pipex->newpipe[1] = -1;
	pipex->pid = 0;
	pipex->child = 0;
	pipex->cmdargs = NULL;
	pipex->path = NULL;
	pipex->cmdpath = NULL;
	pipex->stat = 1;
	open_file(pipex);
}

void	err_exit(int error_code)
{
	if (error_code == ENOENT || error_code == EBADF)
	{
		ft_putstr_fd("Command where\n", 2);
		exit(127);
	}
	else if (error_code == EACCES)
	{
		ft_putstr_fd("No permission brother\n", 2);
		exit(126);
	}
	else
	{
		ft_putstr_fd("NOPE\n", 2);
		exit(1);
	}
}
