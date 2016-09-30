# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/27 17:28:44 by ealbecke          #+#    #+#              #
#    Updated: 2016/08/07 10:42:50 by ealbecke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main
NAME	=	 libft.a
AR		=	ar -rcs
CC		=	gcc

ifeq ($(DEBUG), yes)
FDEBUG	=	-g
endif

WFLAGS	=	-Wall -Wextra -Werror -g
OPTI	=	-I
LS		=	ls -1
GREP	=	grep
MKDIR	=	mkdir -p
RM		=	rm -rf

# Directory
DSRC	=	src
DOBJ	=	obj
DINC	=	inc

# File
FSRC	:=	$(shell $(LS) $(DSRC) | $(GREP) \.c$)
FOBJ	:=	$(FSRC:.c=.o)

# Transform
FSRC	:=	$(addprefix $(DSRC)/, $(FSRC))
FOBJ	:=	$(addprefix $(DOBJ)/, $(FOBJ))
FINC	:=	$(addprefix $(OPTI) , $(DINC))

all: $(FOBJ) $(NAME)

$(NAME): $(FOBJ)
	$(AR) $@ $(FOBJ)

$(DOBJ)/%.o: $(DSRC)/%.c $(DINC)
	@$(MKDIR) $(DOBJ)
	$(CC) $(FDEBUG) $(WFLAGS) -c $< $(FINC) -o $@

clean:
	$(RM) $(DOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all begin clean fclean re
