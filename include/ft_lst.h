/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:25:13 by aguiri            #+#    #+#             */
/*   Updated: 2021/11/02 20:27:13 by aguiri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LST_H
# define FT_LST_H

// ****************************************************************************
// Structures

/**
 * \brief		Contains the links of the list.
 */
typedef struct s_list {
	void			*content;
	struct s_list	*next;
}					t_list;

// ****************************************************************************
// Functions - Lists

/**
 * \brief		Add the 'new' element at the end of the list.
 * 
 * \param alst	The address of the pointer to the first element of the list.
 * \param new	The address of the pointer to the element to add to the list.
 */
void	ft_lstadd_back(t_list **alst, t_list *new);

/**
 * \brief		Add the 'new' element at the beginning of the list.
 * 
 * \param alst	The address of the pointer to the first element of the list.
 * \param new	The address of the pointer to the element to add to the list.
 */
void	ft_lstadd_front(t_list **alst, t_list *new);

/**
 * \brief		Deletes and frees the memory of the element passed in parameter,
 * 				and of all the elements that follow, using del and free().
 * 				Finally, the initial pointer must be set to NULL.
 * 
 * \param lst	The address of the pointer to an element of the list.
 * \param del	Function's address used to delete the element's content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * \brief		Free the memory of the element passed as argument using the del
 * 				function and then with free(). The memory of next will not be
 * 				freed.
 * 
 * \param lst	Element to be freed.
 * \param del	Function's address used to delete the element's content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * \brief		Iterates over the list lst and applies the function f to the
 * 				content of each element.
 * 
 * \param lst	Address of the pointer to an element of the list.
 * \param f		Adresss of the function to be applied.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * \brief		Grab the list's last element. 
 * 
 * \param lst	First element of the list. 
 * \return		Last element of the list. 
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * \brief		Iterates over the list lst and applies the function f to the
 * 				content of each element. Create a new list resulting from the
 * 				successive applications of f. The function del is there to
 * 				destroy the content of an element element if necessary.
 * 
 * \param lst	First element of the list. 
 * \param f		Adresss of the function to be applied.
 * \param del	Function's address used to delete the element's content.
 * \return		New created list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * \brief		Allocate (with malloc()) and returns a new element. The
 * 				variable content is initialized with the value of the content
 * 				parameter. The variable next is initialized to NULL.
 * 
 * \param content	Content of the new element.
 * \return			Pointer to the new element. 
 */
t_list	*ft_lstnew(void *content);

/**
 * \brief		Count the number of elemets of the list.
 * 
 * \param lst	First element of the list.
 */
int		ft_lstsize(t_list *lst);

#endif
