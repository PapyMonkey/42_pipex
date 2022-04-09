/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/09 21:46:40 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex_infile(size_t i, int *fd, t_cmds cmds)
{
	int		fd_infile;

	fd_infile = 0;
	if (access(cmds.args[i], R_OK) == 0)
	{
		fd_infile = open(cmds.args[i], O_RDONLY);
		if (fd_infile == -1)
			ft_error_put_exit();
		ft_pipex_infile_read(fd, fd_infile);
		close(fd_infile);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		exit(EXIT_SUCCESS);
	}
	else
		ft_error_put_exit();
}

void	ft_pipex_outfile(size_t i, int *fd, t_cmds cmds)
{
	int		fd_outfile;

	fd_outfile = 0;
	if (access(cmds.args[i], W_OK) == 0)
	{
		fd_outfile = open(cmds.args[i], O_WRONLY);
		if (fd_outfile == -1)
			ft_error_put_exit();
		ft_printf("TOTO\n");
		
		//ft_pipex_outfile_write(fd, fd_outfile);
		close(fd_outfile);
		close(fd[READ_END]);
		close(fd[WRITE_END]);
		exit(EXIT_SUCCESS);
	}
	else
		ft_error_put_exit();
}

// Access and execute commands
void	ft_pipex_exec(size_t i, int *fd, int input_fd, t_cmds cmds)
{
	char	**cmd_splitted;
	char	*try_access;

	ft_pipex_redirect(input_fd, STDIN_FILENO);
	ft_pipex_redirect(fd[WRITE_END], STDOUT_FILENO);
	cmd_splitted = ft_split(cmds.args[i], ' ');
	try_access = ft_exec_access(cmd_splitted[0], cmds.path);		// Try if file is executable
	if (!try_access)
		ft_error_put_exit();
	if (try_access)
	{
		ft_printf("Exec core\n"); // TEST 
		execve(try_access, cmd_splitted, cmds.envp);
		free(try_access);
		exit(EXIT_SUCCESS);
	}
}

void	ft_pipex_core(size_t i, t_cmds cmds)
{
	pid_t	pid;
	int		*fd;

	fd = malloc(sizeof(int) * 2 + 1);
	fd[2] = '\0';
	if (i < cmds.args_nb)
	{
		if (pipe(fd) == -1)
			ft_error_put_exit();
		ft_printf("i : %d\n", i);
		//ft_printf("fd[READ_END] = %d\tfd[WRITE_END] = %d\n", fd[READ_END], fd[WRITE_END]);
		pid = fork();
		if (pid < 0) 											// ERROR
			ft_error_put_exit();
		if (pid == 0 && i == 1)									// "Input/infile" case
			ft_pipex_infile(i, fd, cmds);
		else if (pid == 0 && i == cmds.args_nb - 1)				// "Output/outfile" case
			ft_pipex_outfile(i, fd, cmds);	
		else if (pid == 0 && i != 1 && i != cmds.args_nb - 1)	// "Exec commands" case
			ft_pipex_exec(i, fd, fd[READ_END], cmds);
		waitpid(pid, NULL, 0);
		//close(fd[READ_END]);
		//close(fd[WRITE_END]);
		ft_pipex_core(++i, cmds);								// Recall recursive function
	}
	close(fd[READ_END]);
	close(fd[WRITE_END]);
}

int	main(int argc, char **argv, char **envp)
{
	size_t	i;
	t_cmds	cmds;

/*
	if (argc <= 4)
	{
		ft_printf("Error: Invalid arguments\n");
		return (EXIT_FAILURE);
	}
*/
	i = 1;
	cmds.args_nb = argc;
	cmds.args = argv;
	cmds.envp = envp;
	cmds.path = ft_split_path(cmds.envp);
	ft_pipex_core(i, cmds);
	ft_printf("YOUPI c'est la fin\n");
	return (EXIT_SUCCESS);
}
