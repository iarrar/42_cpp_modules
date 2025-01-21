# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 13:49:18 by iarrar            #+#    #+#              #
#    Updated: 2024/05/07 16:17:11 by iarrar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = A.class.cpp B.class.cpp C.class.cpp Base.class.cpp main.cpp
CXX = c++
OBJ = $(SRC:.cpp=.o)
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Identify

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re