/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppxhelper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:30:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/23 20:18:03 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_heredoc(t_ppx *info)
{
	int		tmp_fd;
	int		cont;
	char	*line;

	tmp_fd = open("heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp_fd == -1)
		perror("heredoc.tmp creation error");
	cont = 1;
	line = NULL;
	while (cont == 1)
	{
		ft_putstr_fd("pipex heredoc > ", 1);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if ((!ft_strncmp(line, info->argv[2], ft_strlen(info->argv[2])))
			&& (ft_strlen(info->argv[2]) + 1 == ft_strlen(line)))
			cont = 0;
		else
			ft_putstr_fd(line, tmp_fd);
		free(line);
	}
	close(tmp_fd);
}

void	open_file(t_ppx *pipex)
{
	if (pipex->heredoc)
	{
		make_heredoc(pipex);
		pipex->fd_in = open("heredoc", O_RDONLY);
		pipex->fd_out = open(pipex->argv[pipex->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		pipex->fd_in = open(pipex->argv[1], O_RDONLY);
		pipex->fd_out = open(pipex->argv[pipex->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (pipex->fd_in == -1)
	{
		ft_printf("Error opening input file\n");
		pipex->fd_in = open("/dev/null", O_RDONLY);
	}
}

void	setpath(t_ppx *ppx)
{
	char	*temp;
	int		i;

	i = -1;
	while (ppx->envp[++i])
	{
		if (ft_strncmp("PATH=", ppx->envp[i], 5) == 0)
			ppx->path = ft_split(ppx->envp[i] + 5, ':');
	}
	ppx->cmdargs = ft_split(ppx->argv[ppx->heredoc + 2 + ppx->child], ' ');
	i = 0;
	while ((ppx->path) && ppx->path[i])
	{
		if ((ppx->cmdargs[0][0] == '.') && (ppx->cmdargs[0][1] == '/'))
			break ;
		temp = ft_strjoin(ppx->path[i], "/");
		if (temp == NULL)
			return (ft_printf("path error\n"), (void)0);
		(free(ppx->path[i]), ppx->path[i] = ft_strjoin(temp, ppx->cmdargs[0]));
		free(temp);
		if (access(ppx->path[i], F_OK | X_OK) == 0)
			return (ppx->cmdpath = ft_strdup(ppx->path[i]), (void)0);
		i++;
	}
	ppx->cmdpath = ft_strdup(ppx->cmdargs[0]);
}

void	redirect(int in, int out)
{
	if (dup2(in, STDIN_FILENO) == -1)
	{
		perror("smth wrong with dup2 in lah\n");
		exit(1);
	}
	if (dup2(out, STDOUT_FILENO) == -1)
	{
		perror("smth wrong with dup2 out\n");
		exit(1);
	}
}
