NAME	=	a.out

OBJ_DIR	=	.obj

SRCS	=	main.cpp	ClapTrap.cpp	ScavTrap.cpp	FragTrap.cpp\
			DiamondTrap.cpp

CFLAGS	=	-std=c++98 -Wall -Werror -Wextra -Wshadow -Wno-shadow

OBJ		= 	$(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

CC		=	c++

RM		=	rm -rf

HEADER	=	ClapTrap.hpp ScavTrap.hpp	FragTrap.hpp DiamondTrap.hpp

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