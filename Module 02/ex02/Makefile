# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 21:06:16 by mde-sa--          #+#    #+#              #
#    Updated: 2024/06/10 22:29:03 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   NowWeAreTalking
CXX			=   c++
CXXFLAGS	=  -Wall -Wextra -Werror -std=c++98
SRC			=   main.cpp Fixed.cpp
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

format:
	clang-format -style="{BasedOnStyle: GNU, UseTab: Always, IndentWidth: 4, TabWidth: 4}" -i *.cpp *.hpp

.PHONY: all clean fclean re format