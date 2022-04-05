/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 07:14:39 by aguiri            #+#    #+#             */
/*   Updated: 2021/10/30 14:42:15 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;

	s = (char *)dst;
	if (!dst && !src)
		return (dst);
	while (n)
	{
		*(char *)s = *(char *)src;
		s++;
		src++;
		n--;
	}
	return (dst);
}
