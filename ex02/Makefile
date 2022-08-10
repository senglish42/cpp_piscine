NAME	=	a.out

OBJ_DIR	=	.obj

SRCS	=	main.cpp		ClassA.cpp	ClassB.cpp	ClassC.cpp	ClassBase.cpp

CFLAGS	=	-std=c++98 -Wall -Werror -Wextra

OBJ		= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

CC		=	c++

RM		=	rm -rf

HEADER	=	ClassA.hpp	ClassB.hpp	ClassC.hpp	ClassBase.hpp

$(OBJ_DIR)/%.o:%.cpp $(HEADER)
	mkdir -p $(OBJ_DIR)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(SRCS)

clean	:
	$(RM) $(OBJ_DIR)

fclean	:	clean
	$(RM) $(NAME)

re		: fclean all