/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbecke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 17:16:35 by ealbecke          #+#    #+#             */
/*   Updated: 2016/06/28 11:38:55 by ealbecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <wchar.h>

# define FTL_ERROR 1
# define FTL_ERR -1
# define FTL_OUT_ERR 2
# define FTL_6B 63
# define FTL_B7 128
# define FTL_B11 2047
# define FTL_B16 65536
# define FTL_B20 1048576
# define FTL_B31 2147483648
# define FTL_BIT_N(pos) (1 << ((pos) - 1))
# define FTL_STR_HEX "0123456789ABCDEF"
# define FTL_STR_DEC "0123456789"
# define FTL_STR_OCT "01234567"
# define FTL_STR_BIN "01"
# define FTL_INTMIN -2147483648
# define FTL_LONGMIN -9223372036854775808
# define FTL_ABS(x) ((x) < 0 ? (x) * -1 : (x))
# define FTL_PRCT(x, per) ((x) * (per) / 100)
# define FTL_POW2(x) ((x) * (x))

/*
** PART I
** ------
*/
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);

/*
** PART II
** -------
*/
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd_2(int fd, ...);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl_fd_exit(char const *s, int fd, int exit_code);
void			ft_putnbr_fd(int n, int fd);

/*
** BONUS
** -----
*/
typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elm));

/*
** OTHER
** -----
*/
unsigned int	ft_numlen(int num);
unsigned int	ft_lnumlen(long long int num);
char			*ft_strpath(const char *origin, char *file);
char			*ft_strnopath(char *over_path);
void			ft_swap(char *a, char *b);
long long int	ft_nummoy(int *num, unsigned int n);
unsigned int	ft_strclen(const char *str, char c);
unsigned int	ft_charflag(char c, const char *flags);
unsigned int	ft_strflag(const char *str, const char **sflags);
unsigned int	ft_convunilen(wchar_t wcc);
char			*ft_wcconvuni(wchar_t wcc);
char			*ft_litoa(long long int n);
unsigned int	ft_alphalen(const char *str);
unsigned int	ft_digitlen(const char *str);
unsigned int	ft_alnumlen(const char *str);
unsigned int	ft_asciilen(const char *str);
unsigned int	ft_printlen(const char *str);
char			*ft_basenum(unsigned int n, const char *base);
char			*ft_lbasenum(unsigned long long n, const char *base);
unsigned int	ft_basesize(unsigned int n, unsigned int base);
unsigned int	ft_lbasesize(unsigned long long n, unsigned int base);
char			**ft_argdup(char **arg);
unsigned int	ft_arglen(char **arg);
void			ft_argdel(char ***arg);
void			ft_putarg(char **arg);
char			**ft_argnew(unsigned int n);
char			**ft_argcpy(char **dst, char **src);
int				ft_puterr(const char *s1, const char *s2, const char *issu);
unsigned int	ft_cntwrd(const char *str);

#endif
