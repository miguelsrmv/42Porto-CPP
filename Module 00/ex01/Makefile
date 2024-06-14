# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 21:06:16 by mde-sa--          #+#    #+#              #
#    Updated: 2024/06/14 10:48:31 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   MyAwesomePhonebook
CXX			=   c++
CXXFLAGS	=  -Wall -Wextra -Werror -std=c++98
SRC			=   MyAwesomePhonebook.cpp PhoneBook.cpp Contact.cpp
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