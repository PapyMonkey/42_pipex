/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 22:48:51 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/10 22:49:34 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


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

char	*ft_get_pwd(char **envp)
{
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PWD", 3) != 0 && envp[i] != NULL)
		i++;
	return (ft_strtrim(envp[i], "PWD="));
}

char	*ft_join_pwd_path(size_t i, t_cmds cmds)
{
	char	*tmp;
	char	*out;

	tmp = ft_strjoin(cmds.pwd, "/");
	out = ft_strjoin(tmp, cmds.args[i]);
	free(tmp);
	return (out);
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