/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/10 17:38:01 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_pipex_infile(size_t i, int *fd, t_cmds cmds)
{
	int	fd_infile;

	fd_infile = 0;
	if (access(cmds.args[i], R_OK) == 0)
	{
		fd_infile = open(cmds.args[i], O_RDONLY);
		if (fd_infile == -1)
			ft_error_put_exit();
		close(fd[READ_END]);
		ft_pipex_infile_read(fd, fd_infile);
		close(fd[WRITE_END]);
		close(fd_infile);
		//ft_printf("CC c'est passeeeeee\n");
		exit(EXIT_SUCCESS);
	}
	else
		ft_error_put_exit();
}

static void	ft_pipex_outfile(size_t i, int *fd, t_cmds cmds)
{
	int	fd_outfile;

	fd_outfile = 0;
	if (access(cmds.args[i], W_OK) == 0)
	{
		fd_outfile = open(cmds.args[i], O_WRONLY);
		if (fd_outfile == -1)
			ft_error_put_exit();
		//ft_printf("TOTO 1\n");
		//ft_printf("read : %d\n", read(fd[READ_END], NULL, 1));
		//ft_pipex_redirect(fd[READ_END], fd_outfile);
		close(fd[WRITE_END]);
		ft_pipex_outfile_write(fd, fd_outfile);
		close(fd[READ_END]);
		close(fd_outfile);
		//ft_printf("TOTO 3\n");
		exit(EXIT_SUCCESS);
	}
	else
		ft_error_put_exit();
}

// Access and execute commands
static void	ft_pipex_exec(size_t i, int *fd, t_cmds cmds)
{
	char	**cmd_splitted;
	char	*try_access;

	ft_pipex_redirect(fd[READ_END], STDIN_FILENO);
	ft_pipex_redirect(fd[WRITE_END], STDOUT_FILENO);
	cmd_splitted = ft_split(cmds.args[i], ' ');
	try_access = ft_exec_access(cmd_splitted[0], cmds.path);		// Try if file is executable
	if (!try_access)
		ft_error_put_exit();
	if (try_access)
	{
		//ft_printf("Exec core\n"); // TEST 
		execve(try_access, cmd_splitted, cmds.envp);
		free(try_access);
		exit(EXIT_SUCCESS);
	}
}

static void	ft_pipex_core(size_t i, int fd_old, t_cmds cmds)
{
	pid_t	pid;
	int		fd[2];
	int		fd_child[2];
	//int		*fd;

	//fd = malloc(sizeof(int) * 2 + 1);
	//fd[2] = '\0';
	if (i < cmds.args_nb)
	{
		if (pipe(fd) == -1)
			ft_error_put_exit();
		//ft_printf("fd[READ_END] = %d\tfd[WRITE_END] = %d\n", fd[READ_END], fd[WRITE_END]);
		//ft_printf("\n\ni : %d\n", i);
		pid = fork();
		/*
		ft_printf("TEST AVANT TOUT\n");
		ft_printf("fd[READ_END] = %d\n", fd[READ_END]);
		ft_printf("fd[WRITE_END] = %d\n", fd[WRITE_END]);
		ft_printf("fd_new[READ_END] = %d\n", fd_new[READ_END]);
		ft_printf("fd_new[WRITE_END] = %d\n", fd_new[WRITE_END]);
		ft_printf("TEST APRES TOUT\n");
		ft_printf("PID : %d\n", (int) pid);
		*/
		if (pid < 0) 									// ERROR
			ft_error_put_exit();
		else if (pid == 0)
		{
			if (pipe(fd_child) == -1)
				ft_error_put_exit();
			close(fd[READ_END]);
			ft_pipex_redirect(fd_old, fd_child[READ_END]);
			ft_pipex_redirect(fd[WRITE_END], fd_child[WRITE_END]);
			if (i == 1)									// "Input/infile" case
				ft_pipex_infile(i, fd_child, cmds);
			else if (i == cmds.args_nb - 1)				// "Output/outfile" case
				ft_pipex_outfile(i, fd_child, cmds);	
			else if (i != 1 && i != cmds.args_nb - 1)	// "Exec commands" case
				ft_pipex_exec(i, fd_child, cmds);
		}
		else
		{
			close(fd_old);
			close(fd[WRITE_END]);
			waitpid(pid, NULL, 0);
			ft_pipex_core(++i, fd[READ_END], cmds);			// Recall recursive function
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	size_t	i;
	int		fd[2];
	t_cmds	cmds;

	if (argc <= 4)
	{
		ft_printf("Error: Invalid arguments\n");
		return (EXIT_FAILURE);
	}
	i = 1;
	if (pipe(fd) == -1)
		ft_error_put_exit();
	cmds.args_nb = argc;
	cmds.args = argv;
	cmds.envp = envp;
	cmds.path = ft_split_path(cmds.envp);
	close(fd[WRITE_END]);
	ft_pipex_core(i, fd[READ_END], cmds);
	close(fd[READ_END]);
	//ft_printf("\nYOUPI c'est la fin\n");
	return (EXIT_SUCCESS);
}
