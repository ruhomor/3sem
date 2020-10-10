# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/10/10 00:21:31 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = love

SRCS = $(wildcard *.cpp)

INC = ./

OUT = $(SRCS:%.cpp=%)

CXXFLAGS = -std=c++17# -Werror -Wextra -Wall

all: $(OUT)

clean:
	@rm -f *.o

love:
	@echo "not war"

fclean: clean
	@rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re
