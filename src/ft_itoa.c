/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 01:56:53 by papy              #+#    #+#             */
/*   Updated: 2021/10/31 11:10:33 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \brief		Return the length of a given integer. 
 *
 * \param n		Integer to be counted.
 * \return		Length of the integer. +1 if the number appends to be negative.
 */
static int	ft_intlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n > 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

/**
 * \brief		Write an int number in a dedicated string. Recursive function.
 * 
 * \param i		Current position in the string.
 * \param str	String to write into. 
 * \param n		Number to be written. 
 */
static void	ft_write_numb(int *i, char *str, long n)
{
	if (n >= 10)
	{
		ft_write_numb(i, str, n / 10);
		ft_write_numb(i, str, n % 10);
	}
	else
		str[(*i)++] = n + '0';
}

/**
 * \brief		Allocate (with malloc()) and returns a string of characters
 * 				representing the integer received as argument.
 * 				Negative numbers must be handled.
 *
 * \param n		Integer to be converted.
 * \return		String that represent the integer, NULL if the allocation fails.
 */

char	*ft_itoa(int n)
{
	int		i;
	long	n_long;
	char	*out;

	n_long = n;
	out = malloc(sizeof(char) * (ft_intlen(n_long) + 1));
	if (!out)
		return (NULL);
	i = 0;
	if (n_long < 0)
	{
		out[i++] = '-';
		n_long *= -1;
	}
	ft_write_numb(&i, out, n_long);
	out[i] = '\0';
	return (out);
}
