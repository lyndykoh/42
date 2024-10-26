/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:30:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/23 20:14:50 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parent(t_ppx *pipex)
{
	int	status;

	waitpid(pipex->pid, &status, 0);
	while (wait(NULL) > 0)
		;
	cleanparent(pipex);
	return (WEXITSTATUS(status));
}

void	child(t_ppx *pipex)
{
	int	result;

	setpath(pipex);
	if (pipex->child == 0)
		redirect(pipex->fd_in, pipex->newpipe[1]);
	else if (pipex->child == pipex->cmd_no - 1)
		redirect(pipex->oldpipe[0], pipex->fd_out);
	else
		redirect(pipex->oldpipe[0], pipex->newpipe[1]);
	close(pipex->fd_in);
	close(pipex->fd_out);
	close(pipex->newpipe[0]);
	if (pipex->child != 0)
		close(pipex->oldpipe[1]);
	if (pipex->nullenvp)
		result = execve(pipex->cmdpath, pipex->cmdargs, (char *[]){NULL});
	else
		result = execve(pipex->cmdpath, pipex->cmdargs, pipex->envp);
	if (result == -1)
	{
		cleanchild(pipex);
		err_exit(errno);
	}
	exit(2);
}

int	pipeit(t_ppx *pipex)
{
	int	status;

	while (pipex->child < pipex->cmd_no)
	{
		if (pipex->child < pipex->cmd_no - 1)
		{
			if (pipe(pipex->newpipe) == -1)
				perror("cannot pipe");
		}
		pipex->pid = fork();
		if (pipex->pid < 0)
			perror("fork fail");
		else if (pipex->pid == 0)
			child(pipex);
		if (pipex->child > 0)
			(close(pipex->oldpipe[0]), close(pipex->oldpipe[1]));
		if (pipex->child < pipex->cmd_no - 1)
		{
			pipex->oldpipe[0] = pipex->newpipe[0];
			pipex->oldpipe[1] = pipex->newpipe[1];
		}
		pipex->child++;
	}
	status = parent(pipex);
	return (status);
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	pipex;

	if (argc > 1 && (ft_strncmp(argv[1], "here_doc", 8)) == 0 && argc < 6)
		return (ft_printf("here_doc needs more than 6 leh\n"), 1);
	else if (argc < 5)
		return (ft_printf("BROTHER DO PROPERLY LAH\n"), 1);
	init(&pipex, argc, argv, envp);
	return (pipeit(&pipex));
}
