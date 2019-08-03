/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 14:32:02 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/30 15:30:01 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define INIT_SO_BUFF_SIZE 512

# define NONE 42

# define ARGS fs->args
# define SO_START fs->so_buffer_start
# define FS_START fs->format_string_start
# define SO_CURSOR fs->so_buffer_cursor
# define FS_CURSOR fs->format_string_cursor
# define ARGBUFF fs->arg_buffer
# define SO_BUFF_CAPAC fs->so_buffer_capacity
# define NULL_ARGLEN fs->null_arglen
# define XPRE_FLAG fs->xpre_flag
# define BY_PRNTD fs->by_prntd
# define TOTAL_BYTES_PRNTD fs->total_bytes_printed

# define HASHTAG 0x1
# define ZERO 0x2
# define MINUS 0x4
# define PLUS 0x8
# define SPACE 0x10
# define MW_FLAG 0x20
# define MW_STAR 0x40
# define PCN_FLAG 0x80
# define PCN_STAR 0x100

# define DOUBLE_H 0x200
# define DOUBLE_L 0x400
# define SINGLE_H 0x800
# define SINGLE_LC_L 0x100
# define SINGLE_UC_L 0x2000
# define SINGLE_Z 0x4000

# define CONVS_SPECS "scpdiouxXbf%"

# define BIT_FLAGS flgs->all_flags
# define M_WID flgs->mwidth
# define PCN flgs->pcn
# define CONV_INDEX flgs->conv_type_index

# define IBASE 10
# define PBASE 16
# define OBASE 8
# define UIBASE 10
# define XBASE 16
# define BBASE 2

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_fs
{
	va_list			args;
	char			*so_buffer_start;
	char			*format_string_start;
	char			*so_buffer_cursor;
	char			*format_string_cursor;
	char			*arg_buffer;
	size_t			so_buffer_capacity;
	size_t			null_arglen;
	int				xpre_flag;
	size_t			by_prntd;
	size_t			total_bytes_printed;
}					t_fs;

typedef struct		s_flgs
{
	int				all_flags;
	int				mwidth;
	int				pcn;
	int				conv_type_index;
}					t_flgs;

typedef void		(*t_func_table)(t_fs *, t_flgs *);

int					ft_printf(char *format_string, ...);
void				handle_percent(t_fs *fs);

void				init_t_flgs(t_flgs *flgs);
void				init_t_fs(char *format_string, t_fs *fs);

void				parse_all_flags(t_fs *fs, t_flgs *flgs);
void				parse_first_flags(t_fs *fs, t_flgs *flgs);
void				parse_min_width(t_fs *fs, t_flgs *flgs);
void				parse_precision(t_fs *fs, t_flgs *flgs);
void				parse_len_mod1(t_fs *fs, t_flgs *flgs);
void				parse_len_mod2(t_fs *fs, t_flgs *flgs);
void				parse_conv_type(t_fs *fs, t_flgs *flgs);

void				print_conv_arg(t_fs *fs, t_flgs *flgs);

void				print_s(t_fs *fs, t_flgs *flgs);
void				print_c(t_fs *fs, t_flgs *flgs);
void				print_p(t_fs *fs, t_flgs *flgs);
void				print_di(t_fs *fs, t_flgs *flgs);
void				print_oub(t_fs *fs, t_flgs *flgs);
void				print_x(t_fs *fs, t_flgs *flgs);
void				print_percent(t_fs *fs, t_flgs *flgs);
int					print_null(t_fs *fs, t_flgs *flgs);

intmax_t			di_lentype(t_fs *fs, t_flgs *flgs);
uintmax_t			oux_lentype(t_fs *fs, t_flgs *flgs);

void				arg_prnt_mgmt(t_fs *fs);
size_t				so_buff_mgmt(t_fs *fs, size_t arg_len);
size_t				so_buff_mgmt_null(t_fs *fs, size_t arg_len);

char				*cut_right(t_fs *fs, char *buff, int n);
char				*pad_left(t_fs *fs, char *buff, int n, char c);
char				*pad_left_null(t_fs *fs, char *buff, int n, char c);
char				*pad_left_xedge(t_fs *fs, char *buff, int n, char c);
char				*pad_right(t_fs *fs, char *buff, int n, char c);
char				*pad_right_null(t_fs *fs, char *buff, int n, char c);
char				*make_string(char c);
void				arg_capitalize(t_fs *fs);

char				*uintmaxtoa_base(uintmax_t uintarg, int base);

int					ft_isalnum(int c);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
size_t				ft_intlen(int n);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_iswspace(int c);
char				*ft_itoa(int n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
int					ft_numlen(int c);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcatend(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcpyend(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree1stptr(char const *s1, char const *s2);
char				*ft_strjoinfree2ndptr(char const *s1, char const *s2);
char				*ft_strjoinfree2ndptrnull(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *big, const char *little,
															size_t len);
char				*ft_strrev(char *str);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
void				ft_swap(int *a, int *b);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wordccount(char const *s, char delim_c);
int					ft_wordcount(char *s);

#endif
