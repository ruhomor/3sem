# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 01:41:39 by Ruslan            #+#    #+#              #
#    Updated: 2020/09/23 01:41:43 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = love

LIB = ./libvec

LDFLAGS = -L$(LIB) -lvec

SRCS = $(wildcard *.cpp)

INC = ./

OUT = $(SRCS:%.cpp=%)

CXXFLAGS = -std=c++14# -Werror -Wextra -Wall

all: $(NAME) $(OUT)

$(NAME):
	@make -C $(LIB)

clean:
	@rm -f *.o
	@make -C $(LIB) clean

fclean: clean
	@rm -f $(OUT)
	@make -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re
