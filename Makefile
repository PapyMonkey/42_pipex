# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 14:23:25 by aguiri            #+#    #+#              #
#    Updated: 2022/04/08 12:59:23 by aguiri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				?= pipex

CC					= gcc
CFLAGS				?= -Wall -Wextra -Werror
AR 					?= ar
RM					?= rm -f
MKDIR				?= mkdir -p

# ********************************* P A T H S *********************************

SRCS_PATH			:= src
OBJS_PATH			:= bin
HDRS_PATH			:= include
LIBS_PATH			:= libft

# ********************************* N A M E S *********************************

SRCS_NAME			:= 	pipex.c
SRCS				:= 	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
OBJS 				:= 	$(addprefix $(OBJS_PATH)/, $(SRCS_NAME:.c=.o))

# ********************************** L I B S **********************************

LFLAGS_NAME			:= -lft
LFLAGS				:= -L./$(LIBS_PATH) $(LFLAGS_NAME)

# ********************************* R U L E S *********************************

all:				$(NAME)
					
$(OBJS_PATH)/%.o: 	$(SRCS_PATH)/%.c $(HDRS_PATH)
					@$(MKDIR) $(dir $@)
					@$(CC) -o $@ -c $< -I $(HDRS_PATH) $(CFLAGS)


$(NAME):			$(OBJS) 
					@$(CC) $< -o $@ $(LFLAGS)
					@echo "$@: complete."

clean:		
					@$(RM) $(OBJS)

fclean:				clean 
					@$(RM) -r $(OBJS_PATH)
					@$(RM) $(NAME)

re:					fclean libft_re all

libft:				
					@$(MAKE) -C ./$(LIBS_PATH)

libft_clean:
					@$(MAKE) -C ./$(LIBS_PATH) clean

libft_fclean:		
					@$(MAKE) -C ./$(LIBS_PATH) fclean

libft_re:		
					@$(MAKE) -C ./$(LIBS_PATH) re

.PHONY:				all clean fclean re libft libft_clean libft_fclean libft_re