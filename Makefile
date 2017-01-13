# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 10:24:02 by sjang             #+#    #+#              #
#    Updated: 2016/11/05 10:24:03 by sjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET					=	libftprintf.a

OBJECTS					=	ft_dealflags.o ft_dealprecision.o ft_dealtypes.o\
							ft_dealtypes_part2.o ft_dealtypes_wd.o\
							ft_dealwidth.o ft_getspecifies.o\
							ft_getspecifies_sub.o\
							ft_getspecifies_sub2.o\
							ft_itoa_base_prtf.o ft_mknbr.o\
							ft_printf.o ft_libft_wd.o\
							ft_utfconvert.o\
							\
							ft_memset.o ft_memcpy.o ft_strcpy.o ft_strlen.o\
							ft_strdup.o ft_memmove.o ft_strcat.o ft_putchar.o\
							ft_putstr.o ft_isdigit.o

SRC						=	./src/
ICL						=	./include/

CC						=	gcc
CFLAG					=	-Werror -Wall -Wextra -c

AR						=	ar rc
RLIB					=	ranlib

rm						=	/bin/rm -f

.PHONY					:	clean fclean re

all						:	$(TARGET)

$(TARGET) 				:	$(OBJECTS)
							$(AR) $(TARGET) $(OBJECTS)
							$(RLIB) $(TARGET)

%.o						:	$(SRC)%.c
							$(CC) -c $(CFLAG) $< -I$(ICL)

ft_printf.o				:	$(SRC)ft_printf.c $(ICL)ft_printf.h
ft_dealflags.o			:	$(SRC)ft_dealflags.c $(ICL)ft_printf.h
ft_dealprecision.o		:	$(SRC)ft_dealprecision.c $(ICL)ft_printf.h
ft_dealtypes.o			:	$(SRC)ft_dealtypes.c $(ICL)ft_printf.h
ft_dealtypes_part2.o	:	$(SRC)ft_dealtypes_part2.c $(ICL)ft_printf.h
ft_dealwidth.o			:	$(SRC)ft_dealwidth.c $(ICL)ft_printf.h
ft_getspecifies.o		:	$(SRC)ft_getspecifies.c $(ICL)ft_printf.h
ft_getspecifies_sub.o	:	$(SRC)ft_getspecifies_sub.c $(ICL)ft_printf.h
ft_getspecifies_sub2.o	:	$(SRC)ft_getspecifies_sub2.c $(ICL)ft_printf.h
ft_itoa_base_prtf.o		:	$(SRC)ft_itoa_base_prtf.c $(ICL)ft_printf.h
ft_mknbr.o				:	$(SRC)ft_mknbr.c $(ICL)ft_printf.h
ft_libft_wd.o			:	$(SRC)ft_libft_wd.c $(ICL)ft_printf.h
ft_dealtypes_wd.o		:	$(SRC)ft_dealtypes_wd.c $(ICL)ft_printf.h
ft_utfconvert.o			:	$(SRC)ft_utfconvert.c $(ICL)ft_printf.h


ft_putchar.o			:	$(SRC)ft_putchar.c $(ICL)ft_printf.h
ft_putstr.o				:	$(SRC)ft_putstr.c $(ICL)ft_printf.h
ft_strcpy.o				:	$(SRC)ft_strcpy.c $(ICL)ft_printf.h
ft_strlen.o				:	$(SRC)ft_strlen.c $(ICL)ft_printf.h
ft_strdup.o				:	$(SRC)ft_strdup.c $(ICL)ft_printf.h
ft_strcat.o				:	$(SRC)ft_strcat.c $(ICL)ft_printf.h
ft_memset.o				:	$(SRC)ft_memset.c $(ICL)ft_printf.h
ft_memcpy.o				:	$(SRC)ft_memcpy.c $(ICL)ft_printf.h
ft_memmove.o			:	$(SRC)ft_memmove.c $(ICL)ft_printf.h
ft_isdigit.o			:	$(SRC)ft_isdigit.c $(ICL)ft_printf.h

clean					:
							$(RM) $(OBJECTS)
fclean					:	clean
							$(RM) $(TARGET)
re						:	fclean all
