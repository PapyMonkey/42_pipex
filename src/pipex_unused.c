/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_unused.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 12:21:12 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/09 12:21:39 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_pip_infile(int i, char **argv)
{
	int	fd_infile;

	fd_infile = 0;
	if (access(argv[i], R_OK) == 0)
	{
		fd_infile = open(argv[i], O_RDONLY);
		if (fd_infile == -1)
		{
			ft_printf("Error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		// INSERT HERE PIPE AND READ STUFF
	}
	else
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_pip_do(int *i, char **argv, char **path)
{
	int	fd_infile;

	(void) path;
	fd_infile = 0;
	if (access(argv[*i], R_OK) == 0)
	{
		fd_infile = open(argv[*i], O_RDONLY);
		if (fd_infile == -1)
		{
			ft_printf("Error: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
		// INSERT HERE PIPE AND READ STUFF
	}
	else
	{
		ft_printf("Error: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}