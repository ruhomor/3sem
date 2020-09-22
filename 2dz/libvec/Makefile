# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 21:02:57 by kachiote          #+#    #+#              #
#    Updated: 2019/09/24 16:43:58 by kachiote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = g++

NAME = libvec.a

FUNCS = vec_input \
		vec_isin \
		vec_display

SRCS = $(patsubst %, %.c, $(FUNCS))

OUT = $(patsubst %, %.o, $(FUNCS))

INCL = ./

CXXFLAGS = -std=c++14 -Werror -Wextra -Wall

all: $(NAME)

%.o:%.cpp -I$(INCL)
	@$(CXX) $(FLAGS) $(INCL) $< -o $@

$(NAME): $(OUT)
	@ar rc $(NAME) $(OUT)
	@ranlib $(NAME)

clean:
	@rm -f $(OUT)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
