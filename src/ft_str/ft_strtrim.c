/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 11:22:59 by aguiri            #+#    #+#             */
/*   Updated: 2021/10/31 12:02:06 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \brief 		Determines if the character passed as a parameter is considered
 * 				a separator.
 * 
 * \param c 	Input parameter.
 * \param set	Character reference set. 
 * \return		1 if it is a separator, 0 otherwise. 
 */
static int	ft_char_is_sep(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * \brief 		Computes the length of a trimmed string. 
 * 
 * \param s		Input string. 
 * \param set	Character reference set to trimmed. 
 * \return		String length without the trimmer characters. 
 */
static int	ft_strlen_trim(const char *s, const char *set)
{
	int	i;
	int	len_trim;

	i = 0;
	len_trim = ft_strlen(s);
	while (ft_char_is_sep(s[i++], set) && len_trim)
		len_trim--;
	i = ft_strlen(s) - 1;
	while (ft_char_is_sep(s[i--], set) && len_trim)
		len_trim--;
	return (len_trim);
}

/**
 * \brief 		Allocate (with malloc()) and returns a copy of the string s1,
 * 				without the characters specified in specified in set at the
 * 				beginning and end of the string.
 * 
 * \param s1	String to be trimmed. 
 * \param set	Character reference set to be trimmed. 
 * \return		Trimmed string. NULL if the allocation fails. 
 */

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*out;
	int		i;
	int		j;
	int		len_trim;

	len_trim = ft_strlen_trim(s1, set);
	out = malloc(sizeof(char) * (len_trim + 1));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && ft_char_is_sep(s1[i], set))
		i++;
	while (j < len_trim)
		out[j++] = (char) s1[i++];
	out[j] = '\0';
	return (out);
}
