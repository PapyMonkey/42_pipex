/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/11 12:36:23 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pipex_in_out_file(size_t i, int *fd, t_cmds cmds, int OPEN_MODE)
{
	char	*path;
	int		fd_file;

	path = ft_join_pwd_path(i, cmds);
	fd_file = open(path, OPEN_MODE | O_CREAT | O_TRUNC, 0777);
	free(path);
	if (fd_file == -1)
		ft_error_put_exit();
	if (OPEN_MODE == O_RDONLY)
	{
		close(fd[READ_END]);
		ft_pipex_infile_read(fd, fd_file);
		close(fd[WRITE_END]);
	}
	else if (OPEN_MODE == O_WRONLY)
	{
		close(fd[WRITE_END]);
		ft_pipex_outfile_write(fd, fd_file);
		close(fd[READ_END]);
	}
	else
		exit(EXIT_FAILURE);
	close(fd_file);
	exit(EXIT_SUCCESS);
}

// Access and execute commands
static void	ft_pipex_exec(const size_t i, int *fd, const t_cmds cmds)
{
	char	**cmd_splitted;
	char	*try_access;

	ft_pipex_redirect(fd[READ_END], STDIN_FILENO);
	ft_pipex_redirect(fd[WRITE_END], STDOUT_FILENO);
	cmd_splitted = ft_split(cmds.args[i], ' ');
	try_access = ft_exec_access(cmd_splitted[0], cmds.path);
	if (!try_access)
		ft_error_put_exit();
	if (try_access)
	{
		execve(try_access, cmd_splitted, cmds.envp);
		free(try_access);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_pipex_routine(size_t i, int fd_old, int *fd, t_cmds cmds)
{
	int		fd_child[2];

	if (pipe(fd_child) == -1)
		ft_error_put_exit();
	close(fd[READ_END]);
	ft_pipex_redirect(fd_old, fd_child[READ_END]);
	ft_pipex_redirect(fd[WRITE_END], fd_child[WRITE_END]);
	if (i == 1)
		ft_pipex_in_out_file(i, fd_child, cmds, O_RDONLY);
	else if (i == cmds.args_nb - 1)
		ft_pipex_in_out_file(i, fd_child, cmds, O_WRONLY);
	else if (i != 1 && i != cmds.args_nb - 1)
		ft_pipex_exec(i, fd_child, cmds);
}

static void	ft_pipex_core(size_t i, int fd_old, t_cmds cmds)
{
	pid_t	pid;
	int		fd[2];

	if (i < cmds.args_nb)
	{
		if (pipe(fd) == -1)
			ft_error_put_exit();
		pid = fork();
		if (pid < 0)
			ft_error_put_exit();
		else if (pid == 0)
			ft_pipex_routine(i, fd_old, fd, cmds);
		else
		{
			close(fd_old);
			close(fd[WRITE_END]);
			if (waitpid(pid, NULL, 0) == -1)
				exit(EXIT_FAILURE);
			ft_pipex_core(++i, fd[READ_END], cmds);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	t_cmds	cmds;

	if (argc <= 4)
	{
		ft_printf("Error: Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		ft_error_put_exit();
	cmds = ft_pipex_construct(argc, argv, envp);
	close(fd[WRITE_END]);
	ft_pipex_core(1, fd[READ_END], cmds);
	close(fd[READ_END]);
	ft_pipex_deconstruct(cmds);
	return (EXIT_SUCCESS);
}
