# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 21:06:16 by mde-sa--          #+#    #+#              #
#    Updated: 2024/06/18 15:30:00 by mde-sa--         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=   IdentifyRealType
CXX			=   c++
CXXFLAGS	=   -Wall -Wextra -Werror -Wshadow -pedantic -std=c++98
SRCDIR		=	src
INCDIR		=   includes
SRC			=   main.cpp
OBJS		=   $(addprefix $(SRCDIR)/, $(SRC:.cpp=.o))
RM			=   rm -rf


all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(SRCDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re