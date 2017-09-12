/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvarela <nvarela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:00:06 by nvarela           #+#    #+#             */
/*   Updated: 2017/09/12 17:41:01 by nvarela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE		10000
# define BOLD			"\033[1;01m"
# define UNDERLINE		"\033[1;04m"
# define BLACK			"\033[1;30m"
# define RED			"\033[1;31m"
# define GREEN			"\033[1;32m"
# define YELLOW			"\033[1;33m"
# define BLUE			"\033[1;34m"
# define PURPLE			"\033[1;35m"
# define CYAN			"\033[1;36m"
# define WHITE			"\033[1;37m"
# define ORANGE			"\033[1;38m"
# define DEFAULT_COLOR	"\033[0;m"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_newfd
{
	char			*stock;
	int				fdi;
	struct s_newfd	*next;
}					t_newfd;

int					get_next_line(const int fd, char **line);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *str, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, int n);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
void				ft_putchar(char c);
void				ft_putstr(const char *str);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_ishexa(char *str);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2, int free_n);
char				*ft_strnjoin(const char *s1, const char *s2, size_t size);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putnbr(int i);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *news);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_power(int nb, int power);
int					ft_nb_words(const char *s, char c);
int					ft_count_tab(char **tab);
int					ft_counter_number(int n);
void				free_double_inttab(int **tab, int len_tab);
int					**create_double_inttab(int **tab, int lenatab, int lenbtab);
void				free_double_chartab(char **tab);
char				**ft_realloc(char **tab, char *str);
int					ft_atoi_base(char *str, char *base);
char				*ft_base_to_binary(char *str, char *base);
int					ft_count_simpletab(int *tab);
int					ft_search_final_caract(char *str, char c);
int					ft_nbr_of_caract(char *str, char c);
char				*ft_strrev(char *str);
char				**ft_sort_double_tab(char **tab, int type);
char				**ft_cpy_double_chartab(char **tab, int base);

#endif
