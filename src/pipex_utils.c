/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:49:59 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/10 15:45:47 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_put_exit(void)
{
	ft_printf("Error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	ft_pipex_redirect(int old_fd, int new_fd)
{
	if (old_fd != new_fd)
	{
		if (dup2(old_fd, new_fd) == -1)
			ft_error_put_exit();
		else
		{
			ft_printf("REDIRECT : %d being closed and redirected to %d.\n", old_fd, new_fd);
			close(old_fd);
		}
	}
}

char	**ft_split_path(char **envp)
{
	int		i;
	char	*path_trimmed;
	char	**path_splitted;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0 && envp[i] != NULL)
		i++;
	path_trimmed = ft_strtrim(envp[i], "PATH=");
	path_splitted = ft_split(path_trimmed, ':');
	free(path_trimmed);
	return (path_splitted);
}

char	*ft_exec_access(char *command, char **path)
{
	int		i;
	char	*path_join;

	if (!command)
		return (NULL);
	i = 0;
	while (path[i] != NULL)
	{
		ft_strlcat(path[i], "/", ft_strlen(path[i]) + 2);
		path_join = ft_strjoin(path[i], command);
		if (access(path_join, X_OK) == 0)
			return (path_join);
		free(path_join);
		i++;
	}
	return (NULL);
}

void	ft_pipex_infile_read(int *fd, int fd_infile)
{
	char	*out;

	out = ft_get_next_line(fd_infile);
	ft_printf("out : %s", out);
	if (out)
	{
		if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
			ft_error_put_exit();
		while (out)
		{
			out = ft_get_next_line(fd_infile);
			if (out)
			{
				ft_printf("out : %s", out);
				if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
					ft_error_put_exit();
			}
		}
		if (write(fd[WRITE_END], "\0", 1) == -1)
			ft_error_put_exit();
	}
}

void	ft_pipex_outfile_write(int *fd, int fd_outfile)
{
	int		i;
	char	*out;

	ft_printf("TOTO 2\n");
	i = 0;
	out = ft_get_next_line(fd[READ_END]);
	ft_printf("out : %s", out);
	if (out)
	{
		if (write(fd_outfile, out, ft_strlen(out)) == -1)
			ft_error_put_exit();
		while (out)
		{
			//ft_printf("i avant = %d\n", i);
			ft_printf("out : %s\n", out = ft_get_next_line(fd[READ_END]));
			if (out)
			{
				if (write(fd_outfile, out, ft_strlen(out)) == -1)
					ft_error_put_exit();
			}
			i++;
			//ft_printf("out : %s", out);
			//ft_printf("i apres = %d\n", i);
		}
		ft_printf("TEST OUT\n");
		exit(EXIT_SUCCESS);
	}
}
