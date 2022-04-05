/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 17:25:15 by aguiri            #+#    #+#             */
/*   Updated: 2021/10/31 12:53:48 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	dst_tmp = (unsigned char *) dst;
	src_tmp = (unsigned char *) src;
	if (dst > src)
	{
		while (len > 0)
		{
			dst_tmp[len - 1] = src_tmp[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(dst_tmp, src_tmp, len);
	return (dst);
}
