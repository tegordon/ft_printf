/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csdi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 23:10:06 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/29 16:53:23 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MS make_string
#define SJF ft_strjoinfree2ndptr
#define UIMTAB uintmaxtoa_base

void		print_c(t_fs *fs, t_flgs *flgs)
{
	char	c;

	ARGBUFF = "";
	c = (char)va_arg(ARGS, void *);
	if (!c && print_null(fs, flgs))
		return ;
	ARGBUFF = SJF(ARGBUFF, MS(c));
	if ((MINUS & BIT_FLAGS) && (MW_FLAG & BIT_FLAGS))
		ARGBUFF = pad_right(fs, ARGBUFF, M_WID, ' ');
	else if (MW_FLAG & BIT_FLAGS)
		ARGBUFF = pad_left(fs, ARGBUFF, M_WID, ' ');
	arg_prnt_mgmt(fs);
}

void		print_s(t_fs *fs, t_flgs *flgs)
{
	char	*str;
	int		len;

	str = va_arg(ARGS, char *);
	ARGBUFF = ft_strnew(0);
	len = ((str) ? ft_strlen(str) : 6);
	(!str) && (str = "(null)");
	if (*str)
		ARGBUFF = ft_strjoinfree1stptr(ARGBUFF, str);
	if ((PCN_FLAG & BIT_FLAGS) && (PCN < len))
		ARGBUFF = cut_right(fs, ARGBUFF, (len - PCN));
	if (!(MINUS & BIT_FLAGS))
		ARGBUFF = pad_left(fs, ARGBUFF, M_WID, ' ');
	else
		ARGBUFF = pad_right(fs, ARGBUFF, M_WID, ' ');
	arg_prnt_mgmt(fs);
}

intmax_t	di_lentype(t_fs *fs, t_flgs *flgs)
{
	intmax_t	argi;

	if (DOUBLE_H & BIT_FLAGS)
		argi = (intmax_t)va_arg(ARGS, int);
	else if (SINGLE_H & BIT_FLAGS)
		argi = (intmax_t)va_arg(ARGS, int);
	else if (SINGLE_LC_L & BIT_FLAGS)
		argi = (intmax_t)va_arg(ARGS, long);
	else if (DOUBLE_L & BIT_FLAGS)
		argi = (intmax_t)va_arg(ARGS, long long);
	else if (SINGLE_Z & BIT_FLAGS)
		argi = (intmax_t)va_arg(ARGS, size_t);
	else
		argi = (intmax_t)va_arg(ARGS, int);
	return (argi);
}

void		print_di(t_fs *fs, t_flgs *flgs)
{
	intmax_t	argi;
	char		*pre;

	argi = di_lentype(fs, flgs);
	if (argi >= 0)
	{
		if (PLUS & BIT_FLAGS)
			pre = "+";
		else
			pre = ((SPACE & BIT_FLAGS) ? " " : "");
	}
	else
		(argi *= -1) && (pre = "-");
	if ((argi == 0) && (PCN_FLAG & BIT_FLAGS) && (PCN == 0))
		ARGBUFF = ft_strnew(0);
	else
		ARGBUFF = UIMTAB(argi, IBASE);
	(PCN_FLAG & BIT_FLAGS) && (ARGBUFF = pad_left(fs, ARGBUFF, PCN, '0'));
	ARGBUFF = ft_strjoinfree2ndptr(pre, ARGBUFF);
	if (!(MINUS & BIT_FLAGS))
		ARGBUFF = pad_left(fs, ARGBUFF, M_WID, (((!(PCN_FLAG & BIT_FLAGS)) &&
											(ZERO & BIT_FLAGS)) ? '0' : ' '));
	else
		ARGBUFF = pad_right(fs, ARGBUFF, M_WID, ' ');
	arg_prnt_mgmt(fs);
}

void		print_percent(t_fs *fs, t_flgs *flgs)
{
	ARGBUFF = "";
	ARGBUFF = ft_strjoin("%", ARGBUFF);
	if (!(MINUS & BIT_FLAGS))
		ARGBUFF = pad_left(fs, ARGBUFF, M_WID, (ZERO & BIT_FLAGS) ? '0' : ' ');
	else
		ARGBUFF = pad_right(fs, ARGBUFF, M_WID, ' ');
	arg_prnt_mgmt(fs);
}
