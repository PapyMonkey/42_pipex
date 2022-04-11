/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:53:00 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/11 07:14:12 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h> 
# include <errno.h> 

# include "libft.h"

# define WRITE_END 1
# define READ_END 0

// ****************************************************************************
// Structures

/**
 * \brief		Contains the commands and paths of pipex program.
 */
typedef struct s_cmds {
	size_t	args_nb;
	char	**args;
	char	**path;
	char	**envp;
	char	*pwd;
}			t_cmds;

// ****************************************************************************
// Functions - pipex_io.c

/**
 * \brief		Print on STDOUT the corresponding error message (errno) and
 * 				exit the current process with exit(1).
 */
void		ft_error_put_exit(void);

/**
 * \brief			Read the content of a file and write it into a pipe's
 * 					WRITE_END.
 * 
 * \param fd		Pipe's file descriptor.
 * \param fd_infile	File's file descriptor.
 */
void		ft_pipex_infile_read(int *fd, int fd_infile);

/**
 * \brief			Read the content of a pipe's READ_END and write it into
 * 					a file.
 * 
 * \param fd		Pipe's file descriptor.
 * \param fd_infile	File's file descriptor.
 */
void		ft_pipex_outfile_write(int *fd, int fd_outfile);

// ****************************************************************************
// Functions - pipex_path.c

/**
 * \brief			Get the PATH variable from the "envp" (environment
 * 					variable) main()'s third argument.
 * 
 * \param envp		2D array storing all the environment variables.
 * \return			2D array containing all paths from the PATH variable.
 */
char		**ft_split_path(char **envp);

/**
 * \brief			Get the PWD (current working directory) from the
 * 					"envp" (environment variable) main()'s third argument.
 * 
 * \param envp		2D array storing all the environment variables.
 * \return			String containing the absolute path to the working
 * 					directory.
 */
char		*ft_get_pwd(char **envp);

char		*ft_join_pwd_path(size_t i, t_cmds cmds);

char		*ft_exec_access(char *command, char **path);

// ****************************************************************************
// Functions - pipex_utils.c

t_cmds		ft_pipex_construct(int argc, char **argv, char **envp);

void		ft_pipex_deconstruct(t_cmds cmds);

void		ft_pipex_redirect(int old_fd, int new_fd);

#endif