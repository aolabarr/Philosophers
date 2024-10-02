# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 14:37:22 by aolabarr          #+#    #+#              #
#    Updated: 2024/10/02 19:53:01 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror -g3
SFLAGS =  -fsanitize=thread

OBJ_DIR = ./obj
SRC_DIR = ./src

INC_DIR = .


SRC =	philo_main.c \
		philo_utils.c \
		philo_error.c \
		philo_init.c \
		philo_start.c \
		philo_monitor.c \
		philo_actions.c \

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

sanitizer: lib $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(SFLAGS) $(OBJS) -o $(NAME)

fclean: clean
	rm -f $(NAME) *.out
clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi

re: fclean all

.PHONY: all fclean clean re lib sanitizer bonus

#.SILENT:
