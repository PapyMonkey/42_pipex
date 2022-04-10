# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguiri <aguiri@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/30 14:23:25 by aguiri            #+#    #+#              #
#    Updated: 2022/04/10 12:38:54 by aguiri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				?=	pipex

CC					=	gcc
CFLAGS				?=	-Wall -Wextra -Werror
AR 					?=	ar
RM					?=	rm -f
MKDIR				?=	mkdir -p
ECHO				?=	echo

# ********************************* F O N T S *********************************

EOC					:=	"\033[0m"
LIGHT				:=	"\033[1m"
DARK				:=	"\033[2m"

ITALIC				:=	"\033[3m"
UNDERLINE			:=	"\033[4m"

BLACK				:=	"\033[30m"
RED					:=	"\033[31m"
GREEN				:=	"\033[32m"
BLUE				:=	"\033[34m"
PURPLE				:=	"\033[35m"
CYAN				:=	"\033[36m"
WHITE				:=	"\033[37m"

# ********************************* P A T H S *********************************

SRCS_PATH			:=	src
OBJS_PATH			:=	bin
HDRS_PATH			:=	include
LIBS_PATH			:=	libft

# ********************************* N A M E S *********************************

SRCS_NAME			:=	pipex_utils.c\
						pipex.c
SRCS				:=	$(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
OBJS 				:=	$(addprefix $(OBJS_PATH)/, $(SRCS_NAME:.c=.o))

# ********************************* H E A D S *********************************

HFLAGS				:=	-I $(HDRS_PATH)\
						-I $(LIBS_PATH)/$(HDRS_PATH)

# ********************************** L I B S **********************************

LFLAGS_NAME			:=	-lft
LFLAGS				:=	-L./$(LIBS_PATH) $(LFLAGS_NAME)

# ********************************* R U L E S *********************************

all:				$(NAME)
					
$(OBJS_PATH)/%.o: 	$(SRCS_PATH)/%.c $(HDRS_PATH)
					@$(MKDIR) $(dir $@)
					@$(ECHO)\
					$(BLACK)$(DARK)$(ITALIC)"Compiling $<"$(EOC)
					@$(CC) -g -o $@ -c $< $(HFLAGS) $(CFLAGS)


$(NAME):			$(OBJS)
					@$(CC) $^ -o $@ $(LFLAGS)
					@$(ECHO)\
					$(CYAN)$(UNDERLINE)"$@"$(EOC)": "$(GREEN)"complete"$(EOC)

clean:
					@$(ECHO)\
					$(RED)$(ITALIC)"Deleting binary files"$(EOC)
					@$(RM) $(OBJS)

fclean:				clean
					@$(ECHO)\
					$(RED)$(ITALIC)"Deleting executable file"$(EOC)
					@$(RM) -r $(OBJS_PATH)
					@$(RM) $(NAME)

re:					fclean all

libft:				
					@$(MAKE) -C ./$(LIBS_PATH)

libft_clean:
					@$(MAKE) -C ./$(LIBS_PATH) clean

libft_fclean:		
					@$(MAKE) -C ./$(LIBS_PATH) fclean

libft_re:		
					@$(MAKE) -C ./$(LIBS_PATH) re

.PHONY:				all clean fclean re libft libft_clean libft_fclean libft_re