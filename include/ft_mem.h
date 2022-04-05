/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:19:56 by aguiri            #+#    #+#             */
/*   Updated: 2022/02/09 15:22:17 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

// ****************************************************************************
// Functions - Memory manipulation

/**
 * \brief 		Locates the first occurrence of c (converted to an unsigned
 * 				char) in string s. 
 * 
 * \param s		String to search in. 
 * \param c		Charactered wanted. 
 * \param n		Number of iterations to be done. 
 * \return		Pointer to the byte located, or NULL if no such byte exists
 * 				within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * \brief		Compares byte string s1 against byte string s2. Both are
 * 				assumed to be n bytes long.
 *
 * \param s1	First string to be compared.
 * \param s2	Second string to be compared.
 * \param n     Length of both strings.
 *
 * \returns		0 if the two strings are identical, otherwise the difference
 * 				between the first two different bytes.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * \brief       Copies n bytes from memory area src to memory area dst.
 *              If dst and src overlap, behavior is undefined. 
 * 
 * \param dst   Destination string. 
 * \param src   Source string. 
 * \param n     Number of bytes. 
 * \return      Original value of dst. 
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * \brief		Copies len bytes from string src to string dst.  The two strings
 * 				may overlap; the copy is always done in a non-destructive
 * 				manner. 
 * 
 * \param dst 	Destination string.
 * \param src	Source string. 
 * \param len	Number of bytes to be copied. 
 * \return		Original value of dst. 
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * \brief       Writes len bytes of value c (converted to an unsigned char)
 *              to the string b.
 * 
 * \param b     Destination string. 
 * \param c     Value to be written. 
 * \param len   Length. 
 * \return      First argument, b. 
 */
void	*ft_memset(void *b, int c, size_t len);

#endif