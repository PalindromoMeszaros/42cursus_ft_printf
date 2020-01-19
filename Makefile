# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pablomar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/13 16:55:19 by pablomar          #+#    #+#              #
#    Updated: 2020/01/19 15:05:33 by pablomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
LIB = ar rcs
RM = rm -f
CC = gcc
CCFLAGS = -Wall -Werror -Wextra

SRC_PF =  ft_printf.c conversion_c.c conversion_s.c conversion_di.c conversion_u.c conversion_x.c conversion_p.c conversion_pct.c flags.c ft_itoa_special.c miscellaneous.c miscellaneous_02.c

SRC_LFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoa_base.c ft_lstadd_back_bonus.c \
		  ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c \
		  ft_lstsize_bonus.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		  ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		  ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 

OBJ_SRC = $(SRC_PF:.c=.o)
OBJ_LFT = $(SRC_LFT:.c=.o)

LIBFT_PATH = libft
SRC_PATH = src
INCLUDES_PATH = includes

LFT = $(addprefix $(LIBFT_PATH)/, $(OBJ_LFT))
SRC = $(addprefix $(SRC_PATH)/, $(OBJ_SRC))

INCLUDE_PF = ft_printf.h
INCLUDE_LFT = libft.h

PF_LIB = $(addprefix $(INCLUDES_PATH)/, $(INCLUDE_PF))
LFT_LIB = $(addprefix $(LIBFT_PATH)/, $(INCLUDE_LFT))

all: $(NAME)

$(NAME): $(SRC) $(LFT) $(PF_LIB) $(LFT_LIB)
	$(LIB) $(NAME) $(SRC) $(LFT)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(SRC) $(LFT)

fclean: clean
	$(RM) $(NAME)

re: fclean all
