/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdenys-a <cdenys-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 17:39:24 by cdenys-a          #+#    #+#             */
/*   Updated: 2019/02/11 16:41:10 by cdenys-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define ABS(Value) (Value >= 0 ? Value : -Value)
# define BUFF_SIZE 512
# define MALLCHECK(x) if (!x) return (0)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_stor
{
	int				fd;
	char			*buf;
	int				b_read;
	int				b_add;
	struct s_stor	*next;
}				t_stor;

size_t			ft_strlen(const char *s);

int				ft_isalpha(int c);

int				ft_isdigit(int c);

char			*ft_strdup(const char *s1);

void			*ft_memalloc(size_t size);

char			*ft_strncpy(char *dst, const char *src, size_t len);

char			*ft_strcat(char *s1, const char *s2);

size_t			ft_countwords(char const *s, char d);

void			ft_putchar(char c);

void			ft_putstr(char const *s);

void			ft_putendl(char const *s);

int				ft_atoi(const char *str_in);

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char const *s, int fd);

void			ft_bzero(void *s, size_t n);

size_t			ft_charcount(char const *s, char c);

int				ft_int_len_count(int n);

char			*ft_itoa(int n);

char			*ft_strtrim(char const *s);

int				ft_atoi(const char *str_in);

int				ft_int_len_count(int n);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isdigit(int c);

int				ft_isprint(int c);

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			ft_memdel(void **ap);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			ft_putnbr_fd(int nb, int fd);

void			ft_putnbr(int nb);

char			*ft_skipchar(char *s, char trigger);

char			*ft_strchr(const char *s, int c);

void			ft_strclr(char *s);

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcpy(char *dst, const char *src);

void			ft_strdel(char **as);

int				ft_strequ(char const *s1, char const *s2);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dst, const char *src, size_t size);

char			*ft_strmap(char const *s, char (*f)(char));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strncat(char *s1, const char *s2, size_t n);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strnew(size_t size);

char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);

char			*ft_strrchr(const char *s, int c);

char			*ft_strstr(const char *haystack, const char *needle);

char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*ft_strtrim(char const *s);

int				ft_tolower(int c);

int				ft_toupper(int c);

void			ft_putendl_fd(char const *s, int fd);

char			*ft_strtrim_char(char const *s, char c);

char			**ft_strsplit(char const *s, char c);

t_list			*ft_lstnew(void const *cntnt, size_t content_sz);

void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void			ft_lstadd(t_list **alst, t_list *new);

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

char			*ft_strrev(const char *in);

void			ft_lstdel_fn(void *ptr, size_t size);

int				get_next_line(const int fd, char **line);

#endif
