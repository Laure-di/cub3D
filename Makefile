NAME	=	cub3D

SRCS	=	cub3D.c

SRCS_DIR	=	srcs/

OBJSDIR	=	objs

MLX_DIR	= mlx

OBJS	=	${addprefix ${OBJSDIR}/, ${SRCS:.c=.o}}

DEP		=	${OBJS:.o=.d}

HEAD	= -I inc -I mlx

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra -MMD -MP -g3

LIB_FLAGS	= -L ${MLX_DIR}

MLX_FLAGS	=	-lm -lmlx -lXext -lX11

.PHONY: clean fclean all re

all:	${NAME}

$(NAME): ${OBJS}
			@make -C ${MLX_DIR}
			@${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS} ${HEAD} -o $@ ${MLX_FLAGS}

-include $(DEP)
${OBJSDIR}/%.o:${SRCS_DIR}%.c | $(OBJSDIR)
				@${CC} ${CFLAGS} -c $< -o $@ ${HEAD}

$(OBJSDIR):
	@mkdir -p $@

clean:
		@rm -rf ${OBJSDIR}

fclean: clean
		@rm -rf ${NAME}

re: fclean clean

