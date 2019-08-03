/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:33:28 by tegordon          #+#    #+#             */
/*   Updated: 2019/08/02 23:15:07 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void    		    *ft_memcpy(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strcatend(char *s1, const char *s2);
char				*ft_strcpyend(char *dst, const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree1stptr(char const *s1, char const *s2);
char				*ft_strjoinfree2ndptr(char const *s1, char const *s2);
char				*ft_strjoinfree2ndptrnull(char const *s1, char const *s2);
char				*ft_strnew(size_t size);
char		        *ft_strcat(char *s1, const char *s2);
size_t		        ft_strlen(const char *s);
char	            *make_string(char c);
char		        *ft_strrev(char *str);
int		            ft_atoi(const char *str);

#endif
