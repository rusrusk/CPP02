NAME			=			fixed_point_number

CC				=			c++

CFLAGS			=			-Wall -Werror -Wextra --std=c++98 -pedantic

RM				=			rm -rf

SRCS			=			main.cpp Fixed.cpp

OBJSDIR			=			objs

OBJS			=			$(SRCS:%.cpp=$(OBJSDIR)/%.o)

all				:			$(NAME)


$(NAME) : $(OBJS)
		$(CC) $(OBJS) -o $(NAME)


$(OBJSDIR)/%.o : %.cpp
		mkdir -p '$(@D)'
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		$(RM) $(OBJS)
		$(RM) $(OBJSDIR)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : clean fclean re