# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlima <jlima@student.42malaga.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/04 08:48:15 by jlima             #+#    #+#              #
#    Updated: 2022/07/11 13:04:59 by jlima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= pipex

BONUS		= checker

INCLUDES	= -I includes -I $(LIBFT_DIR)includes/

LIBFT_DIR	= libft/
LIBFT_OBJS	= $(LIBFT_DIR)objs/

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MAKE		= make

DIR_SRCS	= srcs/
DIR_OBJS	= objs/

DIR_BONUS	= bonus/
DIR_BO_OBJS	= bonus/objs/

SRCS_FILES	= main path utils

BONUS_FILES = 

OBJS		= $(addprefix $(DIR_OBJS), $(addsuffix .o, $(SRCS_FILES)))

BONUS_OBJS	= $(addprefix $(DIR_BONUS), $(addsuffix .o, $(BONUS_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_DIR)libft.a

$(DIR_OBJS)%.o :	$(DIR_SRCS)%.c
			@mkdir -p $(DIR_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus:		$(BONUS_OBJS)
			@$(MAKE) -C $(LIBFT_DIR)
			@$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJS) $(LIBFT_DIR)libft.a

$(DIR_BO_OBJS)%.o :	$(DIR_BONUS)%.c
			@mkdir -p $(DIR_BO_OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			rm -f $(BONUS_OBJS)
			rm -rf $(DIR_OBJS)
			rm -rf $(LIBFT_OBJS)
			rm -rf $(DIR_BO_OBJS)

fclean:		clean
			rm -f $(NAME)
			rm -f $(BONUS)
			rm -f $(LIBFT_DIR)libft.a

re:			fclean all

.PHONY: 	all clean fclean re bonus
