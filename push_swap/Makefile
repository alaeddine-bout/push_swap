NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRCS = push_swap.c\
		./operations/operations.c\
		./operations/operations2.c\
		./operations/operations3.c\
		./sorting/sort_two.c\
		./sorting/sort_three.c\
		./sorting/sort_five.c\
		./sorting/sort_big.c\
		./utils.c\
		./utils2.c\
		./utils3.c\
		./parsing.c\
		error_handling.c

BONUS_SRCS = bonus/parsing_bonus.c\
			bonus/push_swap_bonus.c\
			bonus/get_next_line.c\
			bonus/get_next_line_utils.c\
			bonus/operations_bonus.c\
			bonus/operations2_bonus.c\
			bonus/operations3_bonus.c\
			error_handling.c


OBJ = ${SRCS:.c=.o}

BONUS_OBJ = $(BONUS_SRCS:.c=.o)

all : ${NAME}

%.o:%.c
	@cc ${CFLAGS} -c $< -o $@
	@echo "$@ \r\t\t\t is compiled"

${NAME} : ${OBJ}
	@make -C ./libft
	@cc ${CFLAGS} ${OBJ} ./libft/libft.a -o ${NAME}

bonus : ${BONUS_NAME}

${BONUS_NAME} : ${BONUS_OBJ}
	@make -C ./libft
	@cc ${CFLAGS} ${BONUS_OBJ} ./libft/libft.a -o ${BONUS_NAME}

clean :
	@make clean -C libft
	@rm -f ${OBJ}
	@rm -f ${BONUS_OBJ}
	@echo object files deleted !

fclean : clean
	@make fclean -C libft
	@rm -f ${NAME}
	@rm -f ${BONUS_NAME}
	@echo program file deleted !

re : fclean all

.PHONY : fclean clean all re
