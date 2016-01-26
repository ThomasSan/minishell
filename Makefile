# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/01 18:33:59 by mdebelle          #+#    #+#              #
#    Updated: 2016/01/26 18:43:08 by tsanzey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC = main.c get_next_line.c built_in.c envp.c ft_misc.c lst_manip.c \
other_built.c usage.c

OBJ = $(SRC:%.c=obj/%.o)

CXX = gcc
CXXFLAGS = -Wall -Werror -Wextra

INC = -I includes
LIB = libft/

all: $(NAME)

$(NAME): obj $(OBJ)
	@make -s -C $(LIB)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(INC) -L$(LIB) -lft -g
	@echo "\033[0;32m  (\_/)"
	@echo "\033[0;32m =(^.^)="
	@echo "\033[0;32m ( )_( )"
	@echo "\033[1;33m Rabbit\033[0m : $(NAME) is\033[0;32m ready\033[0m"

obj/%.o: %.c
	$(CXX) $(CXXFLAGS) $(INC) -o $@ -c $< -I$(LIB)

obj:
	mkdir -p obj/

clean:
	@rm -rf obj

fclean: clean
	@echo "\033[0;31m ___( o)>"
	@echo "\033[0;31m \ <_. )"
	@echo "\033[0;31m   --- "
	@echo "\033[1;33m Duck\033[0m : $(NAME) is\033[0;31m deleted\033[0m"
	@rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean re
