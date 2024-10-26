/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:43:16 by lkoh              #+#    #+#             */
/*   Updated: 2024/10/23 20:17:14 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

typedef struct s_ppx
{
	char	**envp;
	char	**argv;
	int		argc;
	int		heredoc;
	int		fd_in;
	int		fd_out;
	int		cmd_no;
	int		oldpipe[2];
	int		newpipe[2];
	pid_t	pid;
	int		child;
	char	**cmdargs;
	char	**path;
	char	*cmdpath;
	int		stat;
	int		nullenvp;
}			t_ppx;

char		**ft_split(char const *s, char c);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
void		ft_putstr_fd(char *s, int fd);

char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		open_file(t_ppx *pipex);
void		make_heredoc(t_ppx *info);
char		*get_next_line(int fd);

// clean
void		cleanchild(t_ppx *pipex);
void		cleanparent(t_ppx *pipex);

// helper
void		make_heredoc(t_ppx *info);
void		open_file(t_ppx *pipex);
void		setpath(t_ppx *ppx);
void		redirect(int in, int out);

// initexit
void		init(t_ppx *pipex, int argc, char **argv, char **envp);
void		err_exit(int error_code);

#endif