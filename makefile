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

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS	= $(BONUS:.c=.o)

NAME = libft.a

PROJECTNAME = gnl.out

PATHNAME = '"lotr.txt"'

BUFFER_SIZE = 999

CC = gcc

CFLAGS = -Wall -Werror -Wextra -o $(PROJECTNAME) -D FILEPATH=$(PATHNAME)\
		 -D BUFFER_SIZE=$(BUFFER_SIZE)

RM = rm -f

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

bonus:		$(BONUS_OBJS)
			ar rc $(NAME) $?

clean:	
	@${RM} *.o	

fclean:		clean
	@${RM} ${NAME}

re:	fclean all fclean

# .PHONY rules are fictitial rules (always out of date)
.PHONY:		all clean fclean re bonus
