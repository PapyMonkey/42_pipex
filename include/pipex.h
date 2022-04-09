/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:53:00 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/09 12:19:24 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <fcntl.h> 
# include <errno.h> 

# include "libft.h"

// ****************************************************************************
// Structures

/**
 * \brief		Contains the commands and paths of pipex program.
 */
typedef struct s_cmds {
	int		args_nb;
	char	**args;
	char	**path;
	char	**envp;
}			t_cmds;

// ****************************************************************************
// Functions - pipex_utils.c

void	ft_error_put_exit(void);

char	**ft_split_path(char **envp);

char	*ft_exec_access(char *command, char **path);

#endif