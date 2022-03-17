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

PROJECTNAME = gnl

PATHNAME = '"lotr.txt"'

BUFFER_SIZE = 999

CC = gcc

CFLAGS = -Wall -Werror -Wextra -o $(PROJECTNAME) -D FILEPATH=$(PATHNAME)\
		 -D BUFFER_SIZE=$(BUFFER_SIZE)

RM = rm -rf

################################################################################
#		IMPLICIT RULES
################################################################################

all:  $(NAME)

$(NAME): $(OBJS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: re
	./$(PROJECTNAME)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $?

clean:	
	@$(RM) *.o	

fclean:		clean
	@$(RM) $(NAME) $(OBJ_DIR)

re:	fclean all 

# .PHONY rules are fictitial rules (always out of date)
.PHONY:		all clean fclean re bonus
