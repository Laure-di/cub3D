
NAME	= libft.a

CC		= gcc

LINK	= ar rc

RM		= rm -rf

MAKEDIR	= mkdir -p

SRCS	=	ft_addrlen.c				\
			ft_addrtoa.c				\
			ft_atoi.c					\
			ft_atou.c					\
			ft_bzero.c					\
			ft_calloc.c					\
			ft_hexlen.c					\
			ft_intlen.c					\
			ft_isalnum.c				\
			ft_isalpha.c				\
			ft_isascii.c				\
			ft_isdigit.c				\
			ft_isprint.c				\
			ft_iswspace.c				\
			ft_itoa.c					\
			ft_lstadd_back.c			\
			ft_lstadd_front.c			\
			ft_lstclear.c				\
			ft_lstdelone.c				\
			ft_lstiter.c				\
			ft_lstjoin.c				\
			ft_lstlast.c				\
			ft_lstmap.c					\
			ft_lstnew.c					\
			ft_lstsize.c				\
			ft_memccpy.c				\
			ft_memchr.c					\
			ft_memcmp.c					\
			ft_memcpy.c					\
			ft_memmove.c				\
			ft_memset.c					\
			ft_putchar_fd.c				\
			ft_putendl_fd.c				\
			ft_putnbr_fd.c				\
			ft_putnstr_fd.c				\
			ft_putstr_fd.c				\
			ft_putunbr_fd.c				\
			ft_split.c					\
			ft_strcat.c					\
			ft_strncat.c				\
			ft_strlcat.c				\
			ft_strchr.c					\
			ft_strrchr.c				\
			ft_strcmp.c					\
			ft_strncmp.c				\
			ft_strcpy.c					\
			ft_strncpy.c				\
			ft_strlcpy.c				\
			ft_strdup.c					\
			ft_strjoin.c				\
			ft_strlen.c					\
			ft_strclen.c				\
			ft_strmapi.c				\
			ft_strstr.c					\
			ft_strnstr.c				\
			ft_strtrim.c				\
			ft_substr.c					\
			ft_tolower.c				\
			ft_toupper.c				\
			ft_uintlen.c				\
			ft_utoa.c					\
			ft_utolowxa.c				\
			ft_utoupxa.c				\
			get_next_line.c				\

OBJD	= objs/

OBJS	= ${SRCS:.c=.o}
OBJS	:= ${addprefix ${OBJD}, ${OBJS}}

CFLAGS	= -Wall -Wextra -Werror -c -I ../inc

LFLAGS	=

${NAME}:	${OBJS}
			${LINK} ${LFLAGS} ${NAME} ${OBJS}

all:		${NAME}

${OBJD}%.o:	${SRCD}%.c | ${OBJD}
			${CC} ${CFLAGS} $< -o $@

${OBJD}:
			${MAKEDIR} $@

clean:
			${RM} ${OBJD}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
