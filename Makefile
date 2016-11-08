# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:07:11 by sjang             #+#    #+#              #
#    Updated: 2016/11/05 11:07:12 by sjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = a.out

LIB1 = libftprintf.a
LIB2 = libft.a

OBJECTS1 = ft_dealflags.o ft_dealminus.o ft_dealprecision.o ft_dealtypes.o\
			ft_dealtypes_part2.o ft_dealwidth.o ft_getspecifies.o\
			ft_getspecifies_sub.o ft_itoa_base_prtf.o ft_mknbr.o ft_wchar.o\
			ft_printf.o ft_utfconvert.o
OBJECTS2 = main.c

SRC = ./src/
ICL = ./include/
CC = gcc
CFLAG = -c
AR = ar rc
RLIB = ranlib
RM = /bin/rm -f
LB = -L./ -lftprintf  -L./lib/ -lft

.PHONY : clean fclean re

all : $(TARGET)

$(TARGET) : $(LIB1) $(OBJECTS2)
	$(CC) $(OBJECTS2) $(LB)

$(LIB1) : $(OBJECTS1)
	$(AR) $(LIB1) $(OBJECTS1)
	$(RLIB) $(LIB1)


ft_utfconvert.o : $(SRC)ft_utfconvert.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_utfconvert.c

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

ft_printf.o : $(SRC)ft_printf.c $(ICL)libft.h $(ICL)ft_printf.h
	$(CC) $(CFLAG) -I$(ICL) $(SRC)ft_printf.c

clean :
	$(RM) $(OBJECTS1)
fclean : clean
	$(RM) $(TARGET)
re : fclean all