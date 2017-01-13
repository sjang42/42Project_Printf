# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:07:11 by sjang             #+#    #+#              #
#    Updated: 2016/11/10 13:21:03 by sjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET					=	a.out

LIB_PRINT				=	libftprintf.a

OBJECTS					=	main.c

SRC						=	./
ICL						=	../include/
CC						=	gcc -Wall -Wextra -Werror

RM						=	/bin/rm -f
LIB						=	-L../ -lftprintf

.PHONY					:	clean fclean re

all						:	$(TARGET)

$(TARGET)				:	$(LIB_PRINT) $(OBJECTS)
							$(CC) $(OBJECTS) -I$(ICL) $(LIB)

$(LIB_PRINT)			:	
							make -C ..

main.o					:	$(SRC)main.c $(ICL)ft_printf.h

clean					:
							$(RM) $(OBJECTS1) $(LIB1)
fclean					:	clean
							$(RM) $(TARGET)
re						:	fclean all
