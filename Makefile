# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 22:25:32 by tshimoda          #+#    #+#              #
#    Updated: 2022/01/13 13:43:55 by tshimoda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

AR= ar rc
RM= rm -rf

CC= gcc
CFLAGS= -Wall -Werror -Wextra -c -g

SDIR= sources
ODIR= objects

SRCS= main.c \
		misc.c \
		parse.c \
		print.c \
		push.c \
		reverse.c \
		rotate.c \
		sort.c \
		sortbig.c \
		sortcomplex.c \
		stack.c \
		swap.c \
		tools.c \
		utils.c \

OBJS= $(SRCS:.c=.o)

SFIX= $(addprefix $(SDIR)/, $(SRCS))
OFIX= $(addprefix $(ODIR)/, $(OBJS))

VPATH= $(SDIR)

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(ODIR) $(OFIX)
	$(MAKE) -C ./libft
	$(CC) $(OFIX) -lft -L./libft -o $(NAME)
	@echo "\033[1;32m 下田、徳太郎のPUSH_SWAP\033[0;39m"

all:    $(NAME)

$(ODIR):
		mkdir -p $(ODIR)


clean:
	$(MAKE) clean -C ./libft
	$(RM) $(ODIR)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	@echo "\033[1;34m make fclean done!\033[0;39m"

re:     clean all

.PHONY: all clean flcean re