# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/11/03 12:17:17 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = love

SRCS = $(wildcard *.cpp)

INC = ./

OUT = $(SRCS:%.cpp=%)

CXXFLAGS = -std=c++14 -lglfw -lglew -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo# -Werror -Wextra -Wall

all: $(OUT)

clean:
	@rm -f *.o

love:
	@echo "not war"

fclean: clean
	@rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re
