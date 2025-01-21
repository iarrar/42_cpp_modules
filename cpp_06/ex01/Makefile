#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: home <home@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:49:18 by iarrar            #+#    #+#              #
#    Updated: 2024/03/19 11:03:06 by home             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC = Data.class.cpp Serialize.class.cpp main.cpp
CXX = c++
OBJ = $(SRC:.cpp=.o)
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Serialize

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re