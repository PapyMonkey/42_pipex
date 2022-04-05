/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:08:05 by aguiri            #+#    #+#             */
/*   Updated: 2022/02/09 15:17:47 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

// ****************************************************************************
// Functions - Strings

/**
 * \brief		Locates the first occurrence of c (converted to a char) in the
 * 				string pointed to by s.  The terminating null character is
 * 				considered to be part of the string; therefore if c is ‘\0’,
 * 				the functions locate the terminating ‘\0’.
 * 
 * \param s 	String to search in.
 * \param c		Character to be found. 
 * \return		Pointer to the located character, or NULL if the character
 * 				does not appear in the string.
 */
char	*ft_strchr(const char *s, int c);

/**
 * \brief	    Allocate (with malloc()) sufficient memory for a copy of the
 * 				string, does the copy, and returns a pointer to it.
 *
 * \param src	Source string to be copied.
 *
 * \returns	    Returns a pointer to the copied string.	
 * 			    If insufficient memory is available, NULL is returned.
 */
char	*ft_strdup(char *src);

/**
 * \brief		Apply the f function to each character of the string passed as
 * 				an argument and passing its index as first argument.
 * 				Each character is passed by address to f to be modified if 
 * 				necessary.
 *
 * \param s		String to iterate on. 
 * \param f		Function to apply on each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * \brief		Allocate (with malloc()) and return a new string who
 * 				concatenate s1 and s2. 
 * 
 * \param s1	Prefix string. 
 * \param s2	Suffix string. 
 * \return		New string, NULL if the allocation fails. 
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * \brief		Appends string src to the end of dst. It will append at most
 * 				dstsize - strlen(dst) - 1 characters. It will then
 * 				NUL-terminate the string, unless dstsize is 0 or the original
 * 				dst string was longer than dstsize (in practice this should not
 * 				happen as it means that either dstsize is incorrect or that dst
 * 				is not a proper string). 
 * 
 * \param dst		Destination string.
 * \param src		Source string, to be appened at the end of dst.
 * \param dstsize	Size of the destination buffer.
 * \return		Total length of the string the function tried to create. 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * \brief		Copies up to dstsize - 1 characters from the string src to dst,
 * 				NUL-terminating the result if dstsize is not 0.
 * 
 * \param dst		Destination string.
 * \param src		Source string, to be appened at the end of dst.
 * \param dstsize	Size of the destination buffer.
 * \return		Total length of the string the function tried to create. 
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * \brief       Computes the length of the string. 
 * 
 * \param str   Input string. 
 * \return      Length of str. 
 */
int		ft_strlen(const char *str);

/**
 * \brief		Apply the 'f' function to each character of the string passed in
 * 				argument to create a new string a new string (with malloc())
 * 				resulting from the successive applications of 'f'.
 *
 * \param s		String to iterate on. 
 * \param f		Function to apply on each character.
 * \return		The character string resulting from the successive applications
 * 				of f. Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * \brief       Compares not more than n characters. 
 * 
 * \param s1    First string to be compared. 
 * \param s2    Second string to be compared. 
 * \param n     Number of character to compare. 
 * \return      Integer greater than, equal to, or less than 0, according as the
 *              string s1 is greater than, equal to, or less than the string s2.
 *              The comparison is done using unsigned characters, so that ‘\200’
 *              is greater than ‘\0’. 
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * \brief		Locates the first occurrence of the null-terminated string
 * 				needle in the string haystack, where not more than len
 * 				characters are searched. 
 * 
 * \param haystack	String to search in.
 * \param needle	String to be found. 
 * \param len		Number of bytes to be scanned in haystack. 
 * \return			If needle is an empty string, haystack is returned; if
 * 					needle occurs nowhere in haystack, NULL is returned;
 * 					otherwise a pointer to the first character of the first
 * 					occurrence of needle is returned. 
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * \brief		Locates the last occurrence of c (converted to a char) in the
 * 				string pointed to by s.  The terminating null character is
 * 				considered to be part of the string; therefore if c is ‘\0’,
 * 				the functions locate the terminating ‘\0’.
 * 
 * \param s 	String to search in.
 * \param c		Character to be found. 
 * \return		Pointer to the located character, or NULL if the character
 * 				does not appear in the string.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * \brief 		Allocate (with malloc()) and returns a copy of the string s1,
 * 				without the characters specified in specified in set at the
 * 				beginning and end of the string.
 * 
 * \param s1	String to be trimmed. 
 * \param set	Character reference set to be trimmed. 
 * \return		Trimmed string. NULL if the allocation fails. 
 */
char	*ft_strtrim(const char *s1, const char *set);

/**
 * \brief 		Allocate (with malloc()) and returns a string of string from
 * 				the string s. This new string starts at index start and
 * 				has the maximum size len.
 * 
 * \param s		String to be copied. 
 * \param start	Index of the new string in s. 
 * \param len	Maximum length of the new string. 
 * \return		New allocated string. Returns NULL if allocation fails. 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif