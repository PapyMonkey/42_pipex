/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/05 13:06:35 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

char	*ft_exec_access(char *command, char **path)
{
	int		i;
	char	*path_join;

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

char	**ft_split_path(char *path)
{
	char	*path_trimmed;
	char	**path_splitted;

	path_trimmed = ft_strtrim(path, "PATH=");
	path_splitted = ft_split(path_trimmed, ':');
	free(path_trimmed);
	return (path_splitted);
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	char	*tmp_access;
	int		i;
	char	*tmp_args[] = {argv[0], NULL};

	(void) argc;
	(void) **argv;
	i = 1;
	path = ft_split_path(envp[4]);
	while (i != argc)
	{
		tmp_access = ft_exec_access(argv[i], path);
		ft_printf("%s\n", tmp_access);
		i++;
	}
	if (tmp_access)
	{
		if (fork() == 0)
			execve(tmp_access, tmp_args, envp);
	}
	return (0);
}
