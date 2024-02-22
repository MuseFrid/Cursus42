# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/26 20:38:39 by gduchesn          #+#    #+#              #
#    Updated: 2024/02/21 16:52:28 by gduchesn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Array
OBJS_DIR = object
FILES = main.cpp
SRCS = $(addprefix sources/, $(FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
CFLAGS = -Wall -Wextra -Werror -g
CPPFLAGS = -std=c++98 $(INCLUDES)
INCLUDES = -I includes/

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/sources

$(NAME): $(OBJS)
	c++ $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: %.cpp
	c++ $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
