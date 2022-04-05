/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:06:53 by aguiri            #+#    #+#             */
/*   Updated: 2021/11/04 00:26:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_uns_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_uns_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
