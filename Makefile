# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 19:31:29 by abessa-m          #+#    #+#              #
#    Updated: 2025/01/28 21:37:42 by abessa-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################## Test  #
test: re
	@echo -n "$(YELLOW)" ; \
	norminette *.c | grep -v -E \
	"Comment is invalid in this scope" \
	| grep Error ; echo -n "$(COR)\n" ; \
	valgrind --quiet -s --leak-check=full \
	./push_swap 0 -442 -2 225 2 42 ; \
	echo "\nReturn value: $$?" ; \
	$(RM) *.o *.gch ; \
	make --no-print-directory -C libft/ clean 

NAME		:= push_swap
LIBFT		:= libft.a
#################################################################### Compiler  #
CC			:= cc
CFLAGS		:= -g  -Wall -Wextra #-Werror
########################################################## Intermidiate steps  #
RM			:= rm -f
AR			:= ar rcs
######################################################### Objects and Headers  #
HEADERS		= push_swap.h
SRCS		= \
	push_swap.c \
	ps-initialize.c \
	ps-utils.c \
	ps-operations.c
OBJS		= $(SRCS:.c=.o)
##################################################################### Targets  #
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME) \
	&& echo "$(GRAY)Compiled:$(COR) $(SRCS)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ \

$(LIBFT):
	@make --no-print-directory -C ./libft/ 

bonus: $(LIBFT)

clean:
	@$(RM) *.o *.gch ; \
	make --no-print-directory -C libft/ clean 

fclean: clean
	@@make --no-print-directory -C libft/ fclean \
	&& $(RM) $(NAME) 

re: fclean all	
	@echo "$(GRAY)redone$(COR)"
####################################################################### Colors #
COR = \033[0m# COlor Remove
PURPLE = \033[1;35m# purple
GRAY = \033[1;90m# gray
YELLOW = \033[1;93m# yellow

