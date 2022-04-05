/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 01:56:53 by papy              #+#    #+#             */
/*   Updated: 2022/04/05 10:41:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_putnbr_fd(int n, int fd)
{
	int	i;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	i = 0;
	if (n < 0)
	{
		i += ft_printf_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
		i += ft_printf_putnbr_fd(n / 10, fd);
	i += ft_printf_putchar_fd(n % 10 + '0', fd);
	return (i);
}
