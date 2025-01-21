#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: home <home@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:49:18 by iarrar            #+#    #+#              #
#    Updated: 2024/03/28 12:26:30 by home             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = main.cpp 
CXX = c++
OBJ = $(SRC:.cpp=.o)
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = MutantStack

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
