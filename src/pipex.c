/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/09 12:42:05 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_exec(int i, int *fd, t_cmds cmds)
{
	char	**cmd_splitted;
	char	*try_access;

	(void) fd;
	cmd_splitted = ft_split(cmds.args[i], ' ');
	try_access = ft_exec_access(cmd_splitted[0], cmds.path);
	// ft_printf("%s\n", try_access);
	if (!try_access)
		ft_error_put_exit();
	if (try_access)
	{
		execve(try_access, cmd_splitted, cmds.envp);
		free(try_access);
	}
}

void	ft_pipex_core(int i, int *fd, t_cmds cmds)
{
	pid_t	pid;
	int		status;

	(void) fd;
	pid = fork();
	if (pid < 0)
		ft_error_put_exit();
	if (pid == 0)
	{
		ft_pipex_exec(i, fd, cmds);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		ft_pipex_core(++i, fd, cmds);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		*fd;
	int		i;
	t_cmds	cmds;

	if (argc <= 4)
	{
		ft_printf("Error: Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	i = 1;
	fd = malloc(sizeof(int) * 2 + 1);
	fd[2] = '\0';
	pipe(fd);
	(void) fd;
	cmds.args_nb = argc;
	cmds.args = argv;
	cmds.envp = envp;
	cmds.path = ft_split_path(cmds.envp);
	ft_pipex_core(i, fd, cmds);
	return (EXIT_SUCCESS);
}
