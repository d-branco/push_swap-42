# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abessa-m <abessa-m@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 19:31:29 by abessa-m          #+#    #+#              #
#    Updated: 2025/02/02 21:23:58 by abessa-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################################################## Test  #
test: re
	@echo -n "$(YELLOW)" ; \
	norminette *.c | grep -v -E \
	"Comment is invalid in this scope" \
	| grep Error ; echo -n "$(COR)" ; \
	valgrind --quiet -s --leak-check=full \
	./push_swap 1 2 -3 -8 7 4 6 -7 -5 3 -4 -6 9 8 -2 5 -1 -9 0 ; \
	echo "$(GRAY)Return value: $$?$(COR)" ; \
	$(RM) *.o *.gch ; \
	make --no-print-directory -C libft/ clean 

#	valgrind --quiet -s --leak-check=full \
#	./push_swap "0 2 1" ; \
#	echo "$(GRAY)Return value: $$?$(COR)" ; \

NAME		:= push_swap
LIBFT		:= libft.a
#################################################################### Compiler  #
CC			:= cc
CFLAGS		:= -g  -Wall -Wextra 
#-Werror
########################################################## Intermidiate steps  #
RM			:= rm -f
AR			:= ar rcs
######################################################### Objects and Headers  #
HEADERS		= push_swap.h
SRCS		= \
	push_swap.c \
	ps-initialize.c \
	ps-utils-stack.c ps-utils-order.c ps-utils-median.c \
	ps-op.c ps-op-swap.c ps-op-push.c ps-op-rotate.c ps-op-reverse.c \
	ps-check.c \
	ps-algo-small.c \
	ps-algo-turk.c \
	ps-algo-buble.c \
	ps-algo-quick.c ps-algo-quick-eco.c ps-algo-quick-move.c 
	
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

