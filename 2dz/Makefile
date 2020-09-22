# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/09/16 13:12:11 by sslift           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = love

CFILES = 1

SRCS = $(wildcard *.cpp)

INCL = ./

OUT = $(SRCS:%.cpp=%)

CXXFLAGS = -std=c++14# -Werror -Wextra -Wall

all: $(OUT)

$(NAME):
	@echo "not war"

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re
