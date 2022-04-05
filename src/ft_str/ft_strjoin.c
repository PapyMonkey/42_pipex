/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 23:57:32 by aguiri            #+#    #+#             */
/*   Updated: 2021/10/31 00:23:40 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*out;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	out = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		out[i] = (char) s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		out[i + len_s1] = (char) s2[i];
		i++;
	}
	out[len_s1 + len_s2] = '\0';
	return (out);
}
