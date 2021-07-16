NAME		=	philo

SRCS		=	parse_init.c \
				philo.c \
				utils.c \
				groundhog_day.c \
				

OBJS		= ${SRCS:.c=.o}

CC			= gcc
RM			= rm -rf

# CFLAGS		= -Wall -Wextra -Werror

.c.o:		= ${CC} -g ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):		${OBJS}
				${CC} ${OBJS} -o ${NAME}

all:			${NAME}

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re