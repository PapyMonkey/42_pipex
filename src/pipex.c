/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 12:54:24 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/07 22:42:03 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

// Parse through different PATH's paths, and check if a file is executable
// from his path. If it is, return his path. If it is not, return NULL.
char	*ft_exec_access(t_list *lst, char **path)
{
	int		i;
	char	*path_join;

	i = 0;
	while (path[i] != NULL)
	{
		ft_strlcat(path[i], "/", ft_strlen(path[i]) + 2);
		path_join = ft_strjoin(path[i], lst->content);
		if (access(path_join, X_OK) == 0)
			return (path_join);
		free(path_join);
		i++;
	}
	return (NULL);
}

// Get real path from PATH variable and return it.
char	**ft_split_path(char *path)
{
	char	*path_trimmed;
	char	**path_splitted;

	path_trimmed = ft_strtrim(path, "PATH=");
	path_splitted = ft_split(path_trimmed, ':');
	free(path_trimmed);
	return (path_splitted);
}

// Return a t_list of the main's argv.
t_list	*ft_lst_args(char **argv)
{
	int		count_argv;
	t_list	*lst_argv;

	count_argv = 1;
	if (argv[count_argv] == NULL)
		return (NULL);
	else
		lst_argv = ft_lstnew(argv[count_argv++]);
	ft_printf("Content : %s\t\tNext : %s\n", lst_argv->content, lst_argv->next);
	while (argv[count_argv] != NULL)
	{
		ft_lstadd_back(&lst_argv, ft_lstnew(argv[count_argv]));
		ft_printf("TEST ALLOC : %d\n", count_argv);
		count_argv++;
	}
	return (lst_argv);
}

void	ft_pip_command(t_list *lst, char **path)
{
	char	*tmp_access;

	tmp_access = ft_exec_access(lst, path);
	ft_printf("%s\n", tmp_access);
}

int	ft_pip_nb_args(t_list *lst)
{
	t_list	*lst_tmp;
	int		len;

	lst_tmp = lst;
	len = 0;
	ft_printf("TEST NB\n");
	while (lst_tmp != NULL
		|| ft_memcmp(lst_tmp->content, "|", 1) != 0
		|| ft_memcmp(lst_tmp->content, "<", 1) != 0
		|| ft_memcmp(lst_tmp->content, ">", 1) != 0)
	{
		ft_printf("TEST NB IN\n");
		ft_printf("Content : %s\t\tNext : %s\n", lst_tmp->content, lst_tmp->next);
		lst_tmp = lst_tmp->next;
		len++;
	}
	return (len);
}

// Custom delete function.
void	ft_lstdelcustom(void *s)
{
	ft_bzero(s, ft_strlen(s));
}

// Modified version of ft_delone function.
// Delete content of lst->content and reset lst to lst->next.
void	ft_lstdelandlink(t_list **lst, void (*del)(void*))
{
	t_list	*lst_tmp;

	lst_tmp = *lst;
	if (lst_tmp != NULL)
	{
		del(lst_tmp->content);
		*lst = lst_tmp->next;
		free(lst_tmp);
	}
}

char	**ft_pip_lst_args(t_list **lst, int len)
{
	int		i;
	t_list	*lst_tmp;
	char	**out;

	ft_printf("TEST 1\n");
	lst_tmp = *lst;
	if (len == 0)
		return (malloc(0));
	out = malloc(sizeof(char *) * len + 1);
	out[len] = NULL;
	i = 0;
	while (i < len)
	{
		out[i] = ft_strdup(lst_tmp->content);
		ft_lstdelandlink(lst, ft_lstdelcustom);
	}
	return (out);
}


/* VALIDATION TEST LST
void	ft_printcustom(void *s)
{
	ft_printf("%s\n", s);
}

void	test(t_list *lst)
{
	if (lst == NULL)
		ft_printf("NULL\n");
	ft_lstiter(lst, &ft_printcustom);
}
*/

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	char	**args;
	t_list	*lst_argv;
	//char	*tmp_args[] = {argv[0], NULL};

	(void) argc;
	path = ft_split_path(envp[4]);
	lst_argv = ft_lst_args(argv);
	ft_pip_command(lst_argv, path);
	args = ft_pip_lst_args(&lst_argv, ft_pip_nb_args(lst_argv));
	//test(ft_lst_args(argv));

	// ----------------------------

	/*          ACCESS EXECUTABLES

	if (tmp_access)
	{
		if (fork() == 0)
			execve(tmp_access, tmp_args, envp);
			printf("%s", strerror(errno));
			exit();
	}
	*/

	return (0);
}
