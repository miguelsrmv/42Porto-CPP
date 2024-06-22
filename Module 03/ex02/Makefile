# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miguel <miguel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 21:06:16 by mde-sa--          #+#    #+#              #
#    Updated: 2024/06/22 16:40:07 by miguel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   RepetitiveWork
CXX			=   c++
CXXFLAGS	=   -Wall -Wextra -Werror -pedantic -std=c++98
SRC			=   main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
INC			=	/
OBJS		=   $(SRC:.cpp=.o)
RM			=   rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re