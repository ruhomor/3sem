# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/12/13 20:16:43 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = love

SRCS = 1.cpp \
	   3.cpp \
	   4.cpp

SRCBOX = 2.cpp

INC = ./

OUT = $(SRCS:%.cpp=%)

OUTBOX = $(SRCBOX:%.cpp=%)

CXXFLAGS = -std=c++17# -Werror -Wextra -Wall

all: $(OUT) $(OUTBOX)

$(OUTBOX): box.o

clean:
	@rm -f *.o

love:
	@echo "not war"

fclean: clean
	@rm -f $(OUT) $(OUTBOX)

re: fclean all

.PHONY: all clean fclean re
