/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:49:13 by rrakman           #+#    #+#             */
/*   Updated: 2023/05/23 20:31:39 by rrakman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../push_swap.h"

int			ft_isalpha(int c);
int			ft_isdigit(int arg);
int			ft_isalnum(int arg);
int			ft_isascii(int c);
int			ft_isprint( int arg );
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);

char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strdup(const char *s1);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);

size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);

long long	ft_atol(const char *str);
#endif