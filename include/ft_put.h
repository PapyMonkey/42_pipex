/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 00:29:29 by aguiri            #+#    #+#             */
/*   Updated: 2022/02/09 15:24:16 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUT_H
# define FT_PUT_H

// ****************************************************************************
// Functions - Put/print functions

/**
 * \brief		Write a pointer address in hexadecimal on a choosen file
 * 				descriptor.
 * 
 * \param ptr	Pointer.
 * \param fd	File descriptor on which you want your output.
 */
void	ft_putaddress_fd(void *ptr, int fd);

/**
 * \brief	    Write a given character on a choosen file descriptor. 
 *
 * \param c		Character to be written. 
 * \param fd	File descriptor on which you want your output.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * \brief       Write a given string on a choosen file descriptor followed
 * 			    by a line break.
 *
 * \param s     String to be written. 
 * \param fd	File descriptor on which you want your output.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * \brief   	Write a given number in a given base on a choosen file
 * 				descriptor. 
 *
 * \param n		Number to be written.
 * \param base	Base in which the number is expressed.
 * \param fd	File descriptor on which you want your output.
 */
void	ft_putnbr_base_fd(int nbr, char *base, int fd);

/**
 * \brief   	Write a given number on a choosen file descriptor. 
 *
 * \param	n	Unsigned integer to be written.
 * \param	fd	File descriptor on which you want your output.
 */
void	ft_putnbr_uns_fd(unsigned int n, int fd);

/**
 * \brief   	Write a given number on a choosen file descriptor. 
 *
 * \param	n	Integer to be written.
 * \param	fd	File descriptor on which you want your output.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * \brief       Write a given string on a choosen file descriptor. 
 *
 * \param s     String to be written. 
 * \param fd    File descriptor on which you want your output.
 */
void	ft_putstr_fd(char *s, int fd);

#endif