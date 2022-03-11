SRCS =		get_next_line.c
#	mainGnl.c\
#	get_next_line_utils.c

#BONUS =	ft_lstadd_back_bonus.c\
#		ft_lstadd_front_bonus.c\
#		ft_lstclear_bonus.c\
#		ft_lstdelone_bonus.c\
#		ft_lstiter_bonus.c\
#		ft_lstlast_bonus.c\
#		ft_lstmap_bonus.c\
#		ft_lstnew_bonus.c\
#		ft_lstsize_bonus.c\

OBJS = ${SRCS:.c=.o}

BONUS_OBJS	= $(BONUS:.c=.o)


CC = gcc

CFLAGS = -Wall -Werror -Wextra -o $(PROJECTNAME) -D FILEPATH=$(PATHNAME) -D BUFFER_SIZE=5

PROJECTNAME = gnl.out

PATHNAME = '"lotr.txt"'

RM = rm -f

# Main rule is defined as "all"
all:		$(SRCS)
			${CC} ${CFLAGS} ${SRCS}

db:		$(SRCS)
			${CC} ${CFLAGS} -g ${SRCS}

clean:
			${RM} *.o	

fclean:		clean
			${RM} ${NAME}

re:		fclean all fclean

.PHONY:		all clean fclean re bonus

