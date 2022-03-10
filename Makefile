NAME	=	cub3D

SRCS	=	cub3D.c

SRCS_DIR	=	srcs/

OBJSDIR	=	objs

MLX_DIR	= mlx

LIBFT_DIR = libft

OBJS	=	${addprefix ${OBJSDIR}/, ${SRCS:.c=.o}}

DEP		=	${OBJS:.o=.d}

HEAD	= -I inc -I mlx

CC		=	clang

CFLAGS	=	-Wall -Werror -Wextra -MMD -MP -g3

LIB_FLAGS	= -L ${MLX_DIR} -L ${LIBFT_DIR}

MLX_FLAGS	=	-lft -lm -lmlx -lXext -lX11

.PHONY: clean fclean all re

all:	${NAME}

$(NAME): ${OBJS}
			@make -C ${MLX_DIR}
			@make -C ${LIBFT_DIR}
			${CC} ${LIB_FLAGS} ${OBJS} ${HEAD} -o $@ ${MLX_FLAGS}

-include $(DEP)
${OBJSDIR}/%.o:${SRCS_DIR}%.c | $(OBJSDIR)
				${CC} ${CFLAGS} -c $< -o $@ ${HEAD}

$(OBJSDIR):
	@mkdir -p $@

clean:
		@rm -rf ${OBJSDIR}

fclean: clean
		@rm -rf ${NAME}

re: fclean all

