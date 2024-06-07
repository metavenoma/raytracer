# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 09:47:09 by rverona-          #+#    #+#              #
#    Updated: 2024/04/30 09:47:10 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tests
OBJ_PATH = ../objects/
INC = -I ../includes

SRC = main.cpp ../sources/Color.cpp ../sources/Tuple.cpp 
SRC += ../sources/Utils.cpp ../sources/Canvas.cpp ../sources/Matrix.cpp

OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -g

$(OBJ_PATH)%.o: %.cpp 
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) $(INC) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ_PATH)
	@rm ../sources/*.o
fclean: clean
	@rm $(NAME)

re: fclean all
