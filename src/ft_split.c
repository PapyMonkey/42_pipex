/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 13:54:37 by aguiri            #+#    #+#             */
/*   Updated: 2021/11/02 12:30:08 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * \brief		Check if the given character is a separator or not.
 * 
 * \param c		Character to be tested.
 * \param sep	Separator.
 * \return		1 if it is, 0 otherwise.
 */
static int	ft_char_is_sep(char c, char sep)
{
	return (c == sep || c == '\0');
}

/**
 * \brief		Count the numbers of words in the string based on the
 * 				given separators.
 *
 * \param str	String containing the words.
 * \param c		Delimiting character.
 *
 * \return  	Number of words counted. 
 */
static int	ft_count_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_sep(str[i + 1], c) && !ft_char_is_sep(str[i], c))
			words++;
		i++;
	}
	return (words);
}

/**
 * \brief		Write a word in a destination string.
 *
 * \param dest	Destination string.
 * \param src	String containing the words.
 * \param c		Delimiting character.
 */
static void	ft_write_words(char *dest, const char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * \brief		Write the different words in a destination 2D array.
 *
 * \param str_split	Destination 2D array.
 * \param str		String containing the words.
 * \param c			Delimiting character.
 */
static void	ft_write_tab(char **str_split, const char *str, char c)
{
	int	i;
	int	j;
	int	n_word;

	i = 0;
	n_word = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_sep(str[i], c))
			i++;
		else
		{
			j = 0;
			while (!ft_char_is_sep(str[i + j], c))
				j++;
			str_split[n_word] = malloc(sizeof(char) * (j + 1));
			ft_write_words(str_split[n_word], str + i, j);
			i += j;
			n_word++;
		}
	}
}

/**
 * \brief		Allocate (with malloc()) and returns an array of strings
 * 				obtained by separating s with the character c, used as
 * 				delimiter. The array must be terminated by NULL.
 *
 * \param s		Input string to be splitted.
 * \param c		Delimiting character.
 *
 * \return		2D string containing the splitted string. 
 */

char	**ft_split(char const *s, char c)
{
	char	**str_splitted;
	int		n_words;

	if (s == NULL)
		return (NULL);
	n_words = ft_count_words((char *) s, c);
	str_splitted = malloc(sizeof(char *) * (n_words + 1));
	if (!str_splitted)
		return (NULL);
	str_splitted[n_words] = 0;
	ft_write_tab(str_splitted, s, c);
	return (str_splitted);
}
/*
int	main(void)
{
  char **tab = ft_split("chinimala", ' ');
  return 0;
}
*/