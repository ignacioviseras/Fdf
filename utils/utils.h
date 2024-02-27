/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 21:24:50 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/27 21:24:50 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 200
# endif

# ifndef HEXLOWER
#  define HEXLOWER "0123456789abcdef"
# endif

# ifndef HEXUPPER
#  define HEXUPPER "0123456789ABCDEF"
# endif

# include "stdarg.h"
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct pixel
{
	int value;
	int color;
} t_pixel;

int	atoi_base(const char *str, int str_base);
void	**free_all(char **str);
int	ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_realloc(void *ptr, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int	ft_printf(char const *format, ...);
int	ft_print_char(int s);
int	ft_print_string(char *s);
int	ft_print_percent(void);
int	ft_print_unsigned(unsigned int n);
int	ft_print_int(int n);
int	ft_print_hex(unsigned long long n, char *baseFormat);
int	ft_print_pointer(unsigned long long n);
char	***load_map(int fd);
t_pixel	**struct_map(t_pixel **map, char *line, int c, int map_pos);

#endif
