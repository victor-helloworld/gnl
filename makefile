<<<<<<< HEAD
################################################################################
#		VARIABLE DECLARATION
################################################################################

SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj
BIN_DIR = bin

SRCS =	main.c\
		get_next_line.c\
		get_next_line_utils.c
=======
SRCS =		get_next_line.c
#	mainGnl.c\
#	get_next_line_utils.c
>>>>>>> 934c0980e7750d677486905215a16ea68b40a7e9

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS	= $(BONUS:.c=.o)


<<<<<<< HEAD
=======
CC = gcc

CFLAGS = -Wall -Werror -Wextra -o $(PROJECTNAME) -D FILEPATH=$(PATHNAME) -D BUFFER_SIZE=5

>>>>>>> 934c0980e7750d677486905215a16ea68b40a7e9
PROJECTNAME = gnl.out

PATHNAME = '"lotr.txt"'

BUFFER_SIZE = 999

CC = gcc

CFLAGS = -Wall -Werror -Wextra -o $(PROJECTNAME) -D FILEPATH=$(PATHNAME)\
		 -D BUFFER_SIZE=$(BUFFER_SIZE)

RM = rm -f

<<<<<<< HEAD
################################################################################
#		IMPLICIT RULES
################################################################################

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
	@ar rcs $(NAME) $(OBJS)

$(OBJS):	| $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

run:		re
			./$(PROJECTNAME)
=======
# Main rule is defined as "all"
all:		$(SRCS)
			${CC} ${CFLAGS} ${SRCS}
>>>>>>> 934c0980e7750d677486905215a16ea68b40a7e9

db:		$(SRCS)
			${CC} ${CFLAGS} -g ${SRCS}

clean:	
	@${RM} *.o	

fclean:		clean
	@${RM} ${NAME}

re:	fclean all fclean

<<<<<<< HEAD
# .PHONY rules are fictitial rules (always out of date)
=======
>>>>>>> 934c0980e7750d677486905215a16ea68b40a7e9
.PHONY:		all clean fclean re bonus
