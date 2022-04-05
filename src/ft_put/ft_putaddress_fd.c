/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 01:49:28 by aguiri            #+#    #+#             */
/*   Updated: 2021/11/04 02:07:30 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_and_test_longlong(char *str)
{
	unsigned int	len;
	unsigned int	count;

	len = 0;
	count = 0;
	while (str[len] != '\0')
	{
		if (str[len] == '+' || str[len] == '-')
			return (0);
		while (count < len)
		{
			if (str[count] == str[len])
				return (0);
			count++;
		}
		len++;
	}
	return (len);
}

static void	ft_putlonglong_base_fd(unsigned long long nbr, char *base, int fd)
{
	unsigned int		len;
	unsigned long long	div;
	unsigned long long	mod;

	len = ft_strlen_and_test_longlong(base);
	if (len == 0 || len == 1)
		return ;
	if (nbr < 0)
	{
		div = nbr * -1;
		ft_putchar_fd('-', fd);
	}
	else
		div = nbr;
	mod = div % len;
	div = div / len;
	if (div != 0)
		ft_putlonglong_base_fd(div, base, fd);
	ft_putchar_fd(base[mod], fd);
}

void	ft_putaddress_fd(void *ptr, int fd)
{
	unsigned long long	address;

	address = (unsigned long long) ptr;
	ft_putstr_fd("0x", fd);
	ft_putlonglong_base_fd(address, "0123456789abcdef", fd);
}
