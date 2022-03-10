/* ************************************************************************** */
/*                                                                            */
/*														:::	  ::::::::		  */
/*   libft.h                                            :+:      :+:    :+:   */
/*													+:+ +:+		 +:+		  */
/*   By: majacque <majacque@student.42.fr>		  +#+  +:+	   +#+			  */
/*												+#+#+#+#+#+   +#+			  */
/*   Created: 2021/03/25 15:42:15 by majacque		  #+#	#+#				  */
/*   Updated: 2021/10/21 20:50:35 by madjack          ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdbool.h>

// Structure pour liste chainee
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

// Calcule de taille
size_t	ft_strlen(const char *str);
size_t	ft_strclen(const char *str, char c);
size_t	ft_intlen(int nb);
size_t	ft_uintlen(unsigned int nb);
size_t	ft_hexlen(unsigned int nb);
size_t	ft_addrlen(uintptr_t address);

// Traitement de caractere
bool	ft_isalpha(int c);
bool	ft_isdigit(int c);
bool	ft_isalnum(int c);
bool	ft_isascii(int c);
bool	ft_isprint(int c);
bool	ft_iswspace(int c);

int		ft_toupper(int c);
int		ft_tolower(int c);

// Conversion
int		ft_atoi(const char *str);
unsigned int	ft_atou(const char *str);
char	*ft_itoa(int n);
char	*ft_addrtoa(uintptr_t address);
char	*ft_utoa(unsigned int nb);
char	*ft_utolowxa(unsigned int nb);
char	*ft_utoupxa(unsigned int nb);

// Lecture sur file descriptor
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int		get_next_line(int fd, char **line);

// Ecriture sur file descriptor
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putstr_fd(const char *s, int fd);
int		ft_putnstr_fd(int n, const char *s, int fd);
int		ft_putendl_fd(const char *s, int fd);

// Traitement de chaine de caractere
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t nb);
char	*ft_strdup(const char *src);
char	*ft_strstr(const char *str, const char *to_find);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// Traitement de memoire
void	ft_bzero(void *s, size_t n);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

// Liste chainee
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_lstadd_front(t_list **alst, t_list *new_elem);
void	ft_lstadd_back(t_list **alst, t_list *new_elem);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_lstjoin(t_list **list1, t_list *list2);

size_t	ft_lstsize(t_list *list);
#endif
