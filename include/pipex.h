/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:53:00 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/09 17:54:18 by aguiri           ###   ########.fr       */
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
}			t_cmds;

// ****************************************************************************
// Functions - pipex_utils.c

void	ft_error_put_exit(void);

void	ft_pipex_redirect(int old_fd, int new_fd);

char	**ft_split_path(char **envp);

char	*ft_exec_access(char *command, char **path);

void	ft_pipex_infile_read(int *fd, int fd_infile);

void	ft_pipex_outfile_write(int *fd, int fd_outfile);

#endif