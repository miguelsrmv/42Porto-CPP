# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 21:06:16 by mde-sa--          #+#    #+#              #
#    Updated: 2024/05/30 10:29:51 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   JobOfYourDreams
CC      =   c++
FLAGS   =  -Wall -Wextra -Werror -std=c++98
SRC     =   tests.cpp Account.cpp
INC		=	/
OBJS    =   $(SRC:.cpp=.o)
RM      =   rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -I $(INC) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

format:
	clang-format -style="{BasedOnStyle: GNU, UseTab: Always, IndentWidth: 4, TabWidth: 4}" -i Account.cpp

.PHONY: all clean fclean re format