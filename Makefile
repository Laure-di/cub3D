#######################################
#              COMPILER               #
#######################################
CC		= clang

######################################
#             EXECUTABLE             #
######################################
NAME	= cub3D

#######################################
#             DIRECTORIES             #
#######################################
SRCS_DIR	= srcs/
OBJSDIR		= objs
MLX_DIR		= mlx
LIBFT_DIR	= libft

######################################
#            SOURCE FILES            #
######################################
SRCS	= cub3D.c			\
		  check_extension.c	\
		  draw_utils.c		\
		  error_parsing.c	\
		  get_infos_map.c	\
		  get_textures.c	\
		  get_map.c			\
		  parsing.c			\
		  pixel.c			\
		  player.c			\
		  randian_degree.c	\
		  render_map.c		\
		  set_color.c		\
		  set_texture.c		\
		  setup_game.c		\
		  check_map.c		\
		  print_debug.c		\
		  colors.c			\

######################################
#            OBJECT FILES            #
######################################
OBJS	= ${addprefix ${OBJSDIR}/, ${SRCS:.c=.o}}

DEP		= ${OBJS:.o=.d}

#######################################
#                FLAGS                #
#######################################
HEAD		= -I inc -I mlx

CFLAGS		= -Wall -Werror -Wextra -MMD -MP -g3

LIB_FLAGS	= -L ${MLX_DIR} -L ${LIBFT_DIR}

MLX_FLAGS	= -lft -lm -lmlx -lXext -lX11

#######################################
#                RULES                #
#######################################
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
