/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putendl_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 02:01:54 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/05 10:41:44 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (*s)
	{
		i += ft_printf_putchar_fd(*s, fd);
		s++;
	}
	write(fd, "\n", 1);
	return (i);
}
