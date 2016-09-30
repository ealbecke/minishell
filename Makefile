# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/26 11:30:59 by ealbecke          #+#    #+#              #
#    Updated: 2016/05/26 11:31:38 by ealbecke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= clang
WFLAGS	= -Wall -Wextra -Werror -g
OPTI	= -I

LS		= ls -1
GREP	= grep
MKDIR	= mkdir -p
RM		= rm -rf

DSRC	= src
DLIB	= libft
DINC	= inc
DINCLIB	= inc \
		  $(DLIB)/inc
DOBJ	= obj

FSRC	:= $(shell $(LS) $(DSRC) | $(GREP) \.c$)
FOBJ	:= $(FSRC:.c=.o)
LIBFT	:= libft.a

FSRC	:= $(addprefix $(DSRC)/, $(FSRC))
FOBJ	:= $(addprefix $(DOBJ)/, $(FOBJ))
FINCLIB	:= $(addprefix $(OPTI) , $(DINCLIB))
LIBFT	:= $(addprefix $(DLIB)/, $(LIBFT))

all: libft $(FOBJ) $(NAME)

$(NAME): $(LIBFT) $(FOBJ)
	$(CC) $(WFLAGS) $(FOBJ) $(LIBFT) -o $@

$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)
	@$(MKDIR) $(DOBJ)
	$(CC) $(WFLAGS) -c $< $(FINCLIB) -o $@

libft:
	make -C $(DLIB)

clean:
	make -C $(DLIB) clean
	$(RM) $(DOBJ)

fclean: clean
	make -C $(DLIB) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
