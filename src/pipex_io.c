/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 21:19:54 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/10 21:21:25 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_put_exit(void)
{
	ft_printf("Error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	ft_pipex_infile_read(int *fd, int fd_infile)
{
	char	*out;

	out = ft_get_next_line(fd_infile);
	//ft_printf("out : %s", out);
	if (out)
	{
		if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
			ft_error_put_exit();
		while (out)
		{
			out = ft_get_next_line(fd_infile);
			if (out)
			{
				//ft_printf("out : %s", out);
				if (write(fd[WRITE_END], out, ft_strlen(out)) == -1)
					ft_error_put_exit();
			}
		}
		if (write(fd[WRITE_END], "\0", 1) == -1)
			ft_error_put_exit();
	}
}

void	ft_pipex_outfile_write(int *fd, int fd_outfile)
{
	int		i;
	char	*out;

	//ft_printf("TOTO 2\n");
	i = 0;
	out = ft_get_next_line(fd[READ_END]);
	//ft_printf("out : %s", out);
	if (out)
	{
		if (write(fd_outfile, out, ft_strlen(out)) == -1)
			ft_error_put_exit();
		while (out)
		{
			//ft_printf("i avant = %d\n", i);
			out = ft_get_next_line(fd[READ_END]);
			if (out)
			{
				if (write(fd_outfile, out, ft_strlen(out)) == -1)
					ft_error_put_exit();
			}
			i++;
			//ft_printf("out : %s", out);
			//ft_printf("i apres = %d\n", i);
		}
		//ft_printf("TEST OUT\n");
		exit(EXIT_SUCCESS);
	}
}