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

TARGET = libftprintf.a
OBJECTS = ft_dealflags.o ft_dealminus.o ft_dealprecision.o ft_dealtypes.o\
			ft_dealtypes_part2.o ft_dealwidth.o ft_getspecifies.o\
			ft_getspecifies_sub.o ft_itoa_base_prtf.o ft_mknbr.o ft_wchar.o\
			ft_printf.o

SRC = ../src/
ICL = ../include/
CC = gcc
CFLAG = -Werror -Wall -Wextra -c
AR = ar rc
RLIB = ranlib
RM = /bin/rm -f
LB = -L./ -lft

.PHONY : clean fclean re

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(AR) $(TARGET) $(OBJECTS)
	$(RLIB) $(TARGET)

ft_printf.o : $(SRC)ft_printf.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_printf.c

ft_dealflags.o : $(SRC)ft_dealflags.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_dealflags.c

ft_dealminus.o : $(SRC)ft_dealminus.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_dealminus.c

ft_dealprecision.o : $(SRC)ft_dealprecision.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_dealprecision.c

ft_dealtypes.o : $(SRC)ft_dealtypes.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_dealtypes.c

ft_dealtypes_part2.o : $(SRC)ft_dealtypes_part2.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_dealtypes_part2.c

ft_dealwidth.o : $(SRC)ft_dealwidth.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_dealwidth.c

ft_getspecifies.o : $(SRC)ft_getspecifies.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_getspecifies.c

ft_getspecifies_sub.o : $(SRC)ft_getspecifies_sub.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_getspecifies_sub.c

ft_itoa_base_prtf.o : $(SRC)ft_itoa_base_prtf.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_itoa_base_prtf.c

ft_mknbr.o : $(SRC)ft_mknbr.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_mknbr.c

ft_wchar.o : $(SRC)ft_wchar.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_wchar.c

clean :
	$(RM) $(OBJECTS)
fclean : clean
	$(RM) $(TARGET)
re : fclean all
