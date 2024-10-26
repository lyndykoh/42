/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppxclean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:30:36 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/25 13:10:20 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cleanchild(t_ppx *pipex)
{
	int	i;

	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->fd_out != -1)
		close(pipex->fd_out);
	if (pipex->heredoc == 1)
		unlink("heredoc");
	i = 0;
	while (pipex->cmdargs[i])
		free(pipex->cmdargs[i++]);
	free(pipex->cmdargs);
	i = 0;
	if (pipex->path)
	{
		while (pipex->path[i])
			free(pipex->path[i++]);
		free(pipex->path);
	}
	free(pipex->cmdpath);
}

void	cleanparent(t_ppx *pipex)
{
	int	i;

	if (pipex->fd_in != -1)
		close(pipex->fd_in);
	if (pipex->fd_out != -1)
		close(pipex->fd_out);
	if (pipex->heredoc == 1)
		unlink("heredoc");
	i = 0;
	free(pipex->cmdargs);
	free(pipex->path);
	free(pipex->cmdpath);
}
