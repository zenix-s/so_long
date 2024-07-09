/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:42 by serferna          #+#    #+#             */
/*   Updated: 2024/06/12 14:02:41 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// va_list, va_arg, va_start, va_end
# include <stdarg.h>
// write
# include <unistd.h>
// malloc, free, exit
# include <stdlib.h>
// #include <limits.h>

// SIZE_MAX
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef enum s_bool
{
	FALSE,
	TRUE
}					t_bool;

# define HEX_LOW_BASE "0123456789abcdef"
# define HEX_UP_BASE "0123456789ABCDEF"
# define DEC_BASE "0123456789"

int					ft_isalpha(int chr);

int					ft_isdigit(int chr);

int					ft_isalnum(int chr);

int					ft_isascii(int chr);

int					ft_isprint(int chr);

int					ft_toupper(int chr);

int					ft_tolower(int chr);

size_t				ft_strlen(const char *str);

char				*ft_strchr(const char *str, int chr);

char				*ft_strrchr(const char *str, int chr);

int					ft_strncmp(const char *str1, const char *str2, size_t len);

char				*ft_strnstr(const char *str, const char *str_to_find,
						size_t len);

char				*ft_strdup(const char *str);

void				*ft_memset(void *ptr, int chr, size_t len);

void				ft_bzero(void *ptr, size_t len);

void				*ft_memcpy(void *dest, const void *src, size_t len);

void				*ft_memmove(void *dest, const void *src, size_t len);

void				*ft_memchr(const void *ptr, int chr, size_t len);

int					ft_memcmp(const void *ptr1, const void *ptr2, size_t len);

int					ft_atoi(const char *str);

void				*ft_calloc(size_t count, size_t len);

char				*ft_substr(const char *str, unsigned int start, size_t len);

char				*ft_strjoin(const char *s1, const char *s2);

char				*ft_strtrim(const char *str, const char *set);

size_t				ft_strlcpy(char *dst, const char *src, size_t len);

char				**ft_split(char const *str, char chr);

char				*ft_itoa(int num);

char				*ft_strmapi(const char *str, char (*f)(unsigned int, char));

void				ft_striteri(char *str, void (*f)(unsigned int, char *));

t_list				*ft_lstnew(void *content);

void				ft_lstadd_front(t_list **lst, t_list *newNode);

int					ft_lstsize(t_list *lst);

t_list				*ft_lstlast(t_list *lst);

void				ft_lstadd_back(t_list **lst, t_list *newNode);

void				ft_lstdelone(t_list *lst, void (*del)(void *));

void				ft_lstclear(t_list **lst, void (*del)(void *));

void				ft_lstiter(t_list *lst, void (*f)(void *));

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// PRINTER
int					print_int_base(int number, int base, char *base_str);
int					print_uint_base(unsigned int number, unsigned int base,
						char *base_str);
int					print_pointer(unsigned long long pointer);

int					ft_putchar_fd(char chr, int fd);
int					ft_putstr_fd(char *str, int fd);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr_fd(int num, int fd);

int					ft_printf(const char *format, ...);

#endif
