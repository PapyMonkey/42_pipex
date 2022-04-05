/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 05:02:45 by aguiri            #+#    #+#             */
/*   Updated: 2022/04/05 10:37:34 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// ****************************************************************************
// Includes

# include <stdlib.h>
# include <unistd.h>

# include "ft_lst.h"
# include "ft_mem.h"
# include "ft_printf.h"
# include "ft_put.h"
# include "ft_str.h"

// ****************************************************************************
// Misc. functions

/**
 * \brief 		Converts the initial portion of the string pointed to by str to an 
 * 				int representation.
 * 
 * \param str 	String to be converted.
 * \return		Int representation of the initial portion of the string. 
 */
int		ft_atoi(const char *str);

/**
 * \brief   	Writes n zeroed bytes to the string s.
 *          	If n is zero, does nothing. 
 * 
 * \param s 	String to write on. 
 * \param n 	Number of zero to write.
 */
void	ft_bzero(void *s, size_t n);

/**
 * \brief 		Contiguously allocates enough space for count objects that are size
 * 				bytes of memory each and returns a pointer to the allocated memory.
 * 				The allocated memory is filled with bytes of value zero.
 * 
 * \param count	Number of elements.
 * \param size 	Size of the elements.
 * \return 		If successful, return a pointer to the allocated memory.
 * 				Otherwise, return NULL. 
 */
void	*ft_calloc(size_t count, size_t size);

/**
 * \brief 		Write a function that returns a line read from a file
 				descriptor.
 * 
 * \param fd	File descriptor to read on.
 * \return 		Read line:  correct behavior.
 * 				NULL: there is nothing else to read, or an error occurred.
 */
char	*ft_get_next_line(int fd);

/**
 * \brief   	Tests for any character for which isalpha() or isdigit() is true.
 * 
 * \param c 	Character to be tested. 
 * \return  	1 if True, 0 if False.
 */
int		ft_isalnum(int c);

/**
 * \brief 		Tests for any character for which isupper() or islower() is true.
 * 
 * \param c 	Character to be tested. 
 * \return  	1 if True, 0 if False.
 */
int		ft_isalpha(int c);

/**
 * \brief   	Tests for an ASCII character, which is any character between 0 and
 *          	127 inclusive.
 * 
 * \param c 	Character to be tested. 
 * \return  	1 if True, 0 if False.
 */
int		ft_isascii(int c);

/**
 * \brief   	Tests for a decimal digit character.
 * 
 * \param c 	Character to be tested. 
 * \return  	1 if True, 0 if False.
 */
int		ft_isdigit(int c);

/**
 * \brief   	Tests for any printing character, including space (‘ ’).
 * 
 * \param c 	Character to be tested. 
 * \return  	1 if True, 0 if False.
 */
int		ft_isprint(int c);

/**
 * \brief		Allocate (with malloc()) and returns a string of characters
 * 				representing the integer received as argument.
 * 				Negative numbers must be handled.
 *
 * \param n		Integer to be converted.
 * \return		String that represent the integer, NULL if the allocation fails.
 */
char	*ft_itoa(int n);

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
char	**ft_split(char const *s, char c);

/**
 * \brief	    Converts an upper-case letter to the corresponding lower-case
 * 			    letter.
 *
 * \param c     Decimal Ascii value of the letter to be converted.
 * \returns		If the argument is an upper-case letter, returns the
 * 				corresponding lower-case. Otherwise, the argument is returned
 * 				unchanged.
 */
int		ft_tolower(int c);

/**
 * \brief	    Converts a lower case letter to the corresponding upper-case
 * 			    letter.
 *
 * \param c     Decimal Ascii value of the letter to be converted.
 * \returns		If the argument is a lower-case letter, returns the
 * 				corresponding upper-case. Otherwise, the argument is returned
 * 				unchanged.
 */
int		ft_toupper(int c);

#endif