/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:49:59 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/10 23:02:47 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_cmds	ft_pipex_construct(int argc, char **argv, char **envp)
{
	t_cmds	out;

	out.args_nb = argc;
	out.args = argv;
	out.envp = envp;
	out.path = ft_split_path(out.envp);
	out.pwd = ft_get_pwd(out.envp);
	return (out);
}

void	ft_pipex_deconstruct(t_cmds cmds)
{
	free(cmds.path);
	free(cmds.pwd);
}

void	ft_pipex_redirect(int old_fd, int new_fd)
{
	if (old_fd != new_fd)
	{
		if (dup2(old_fd, new_fd) == -1)
			ft_error_put_exit();
		else
			close(old_fd);
	}
}
