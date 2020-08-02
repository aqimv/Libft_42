# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skennith <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 18:19:22 by skennith          #+#    #+#              #
#    Updated: 2020/01/21 17:33:07 by skennith         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = ./srcs/
SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strcat.c  ft_strchr.c \
		ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlcat.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c ft_strclr.c ft_striter.c \
		ft_striteri.c ft_strequ.c ft_strnequ.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strmap.c ft_strmapi.c ft_strjoin.c \
		ft_strtrim.c ft_strsub.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_sqrt.c ft_range.c ft_uppercase.c ft_lowercase.c ft_wordcounter.c get_next_line.c

SRC_PF_DIR = ./srcs/ft_printf/
SRC_PF = char.c float2.c ft_printf.c init.c octal.c setters.c unsignedint.c utils2.c float.c \
		float3.c hex.c int.c pointer.c string.c utils.c utils3.c
# SRCS_PF = $(addprefix $(SRC_PF_DIR), $(SRC_PF))

OBJ = $(SRC:.c=.o)
OBJ_DIR = ./obj/
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

PF_OBJ = $(SRC_PF:.c=.o)
PF_OBJ_DIR = ./obj/ft_printf/
PF_OBJS = $(addprefix $(PF_OBJ_DIR), $(PF_OBJ))

INC = libft.h get_next_line.h ft_printf.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

FLAGS = -g -Wall -Werror -Wextra -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(PF_OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJ_DIR): 
		@mkdir -p $@
		mkdir -p $(PF_OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		gcc $(FLAGS) -o $@ -c $<

$(PF_OBJ_DIR)%.o: $(SRC_PF_DIR)%.c $(INCS)
		gcc $(FLAGS) -o $@ -c $<

clean:
		@rm -f $(PF_OBJS)
		@rm -rf $(PF_OBJ_DIR)
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
