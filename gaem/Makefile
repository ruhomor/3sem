# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/03 14:53:22 by kachiote          #+#    #+#              #
#    Updated: 2020/11/04 15:48:09 by Ruslan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

ALGOFOLDER = algos

NAME = Application

SRCS = map

HEADERS = $(patsubst %, %.h, $(SRCS))

INC = gaem.h

OBJS = $(patsubst %, %.o, $(SRCS))

CXXFILES = $(patsubst %, %.cpp, $(SRCS))

CXXFLAGS = -std=c++17 -O3

FRAMEWORKS = -lglfw -lglew -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo

$(NAME): $(OBJS) $(NAME).o
	@make --ignore-errors -C $(ALGOFOLDER)
	$(CXX) $(CXXFLAGS) $(FRAMEWORKS) -o $(NAME) $(OBJS) $(NAME).o

$(NAME).o: $(INC)
	$(CXX) $(CXXFLAGS) $(NAME).cpp -c

$(OBJS): $(HEADERS)

$(NAME).cpp: $(INC)

all: $(NAME)

clean:
	@make --ignore-errors -C $(ALGOFOLDER) clean
	@rm -f $(OBJS) $(NAME).o

love:
	@echo "not war"

fclean: clean
	@make --ignore-errors -C $(ALGOFOLDER) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
