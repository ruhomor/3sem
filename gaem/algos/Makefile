# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/11/04 15:41:28 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = game

INC = game.h

SRCS = $(filter-out game.cpp, $(wildcard *.cpp))

OUT = $(SRCS:%.cpp=%)

PLAYERS = $(SRCS:%.cpp=%.player)

CXXFLAGS = -std=c++17# -Werror -Wextra -Wall

all: $(PLAYERS)

$(PLAYERS): $(OUT)
	mv $(@:%.player=%) $@

$(NAME).o: $(INC)

$(OUT): $(NAME).o

clean:
	@rm -f $(NAME).o

love:
	@echo "not war"

fclean: clean
	$(PLAYERS)

re: fclean all

.PHONY: all clean fclean re
