/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pouxb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:53:18 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/25 23:28:55 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define UIMTAB uintmaxtoa_base
#define PLXEC pad_left_xedge
#define SJF ft_strjoinfree2ndptr
#define FSN ft_strnew

void		print_p(t_fs *fs, t_flgs *flgs)
{
	uintmax_t	argp;

	argp = (uintmax_t)va_arg(ARGS, void *);
	ARGBUFF = "0x";
	if (argp)
		ARGBUFF = ft_strjoinfree2ndptr(ARGBUFF, UIMTAB(argp, PBASE));
	else
		ARGBUFF = ft_strjoin(ARGBUFF, "0");
	if (!(MINUS & BIT_FLAGS))
		ARGBUFF = pad_left(fs, ARGBUFF, M_WID, ' ');
	else
		ARGBUFF = pad_right(fs, ARGBUFF, M_WID, ' ');
	arg_prnt_mgmt(fs);
}

uintmax_t	oux_lentype(t_fs *fs, t_flgs *flgs)
{
	uintmax_t	argu;

	if (DOUBLE_H & BIT_FLAGS)
		argu = (uintmax_t)va_arg(ARGS, unsigned int);
	else if (SINGLE_H & BIT_FLAGS)
		argu = (uintmax_t)va_arg(ARGS, unsigned int);
	else if (SINGLE_LC_L & BIT_FLAGS)
		argu = (uintmax_t)va_arg(ARGS, unsigned long);
	else if (DOUBLE_L & BIT_FLAGS)
		argu = (uintmax_t)va_arg(ARGS, unsigned long long);
	else if (SINGLE_Z & BIT_FLAGS)
		argu = (uintmax_t)va_arg(ARGS, size_t);
	else
		argu = (uintmax_t)va_arg(ARGS, unsigned int);
	return (argu);
}

void		print_oub(t_fs *fs, t_flgs *flgs)
{
	uintmax_t	argu;
	int			base;

	argu = oux_lentype(fs, flgs);
	if (CONV_INDEX == 5)
		base = OBASE;
	else if (CONV_INDEX == 6)
		base = UIBASE;
	else if (CONV_INDEX == 9)
		base = BBASE;
	if (argu == 0 && PCN_FLAG & BIT_FLAGS && PCN == 0 && (ARGBUFF = FSN(0)))
		((HASHTAG & BIT_FLAGS) && (CONV_INDEX == 5)) ?
		(ARGBUFF = ft_strjoinfree2ndptr("0", ARGBUFF)) : NULL;
	else
		ARGBUFF = UIMTAB(argu, base);
	if ((HASHTAG & BIT_FLAGS) && (CONV_INDEX == 5) && (argu != 0))
		ARGBUFF = ft_strjoinfree2ndptr("0", ARGBUFF);
	(PCN_FLAG & BIT_FLAGS) && (ARGBUFF = pad_left(fs, ARGBUFF, PCN, '0'));
	if (!(MINUS & BIT_FLAGS))
		ARGBUFF = pad_left(fs, ARGBUFF, M_WID, (((!(PCN_FLAG & BIT_FLAGS)) &&
											(ZERO & BIT_FLAGS)) ? '0' : ' '));
	else
		ARGBUFF = pad_right(fs, ARGBUFF, M_WID, ' ');
	arg_prnt_mgmt(fs);
}

void		print_x(t_fs *fs, t_flgs *flgs)
{
	uintmax_t	argx;

	argx = oux_lentype(fs, flgs);
	if ((argx == 0) && (PCN_FLAG & BIT_FLAGS) && (PCN == 0))
		ARGBUFF = ft_strnew(0);
	else
		ARGBUFF = UIMTAB(argx, XBASE);
	(PCN_FLAG & BIT_FLAGS) && (ARGBUFF = pad_left(fs, ARGBUFF, PCN, '0'));
	if ((HASHTAG & BIT_FLAGS) && (argx != 0))
	{
		ARGBUFF = ft_strjoinfree2ndptr("0x", ARGBUFF);
		XPRE_FLAG = 1;
	}
	if (!(MINUS & BIT_FLAGS))
		ARGBUFF = PLXEC(fs, ARGBUFF, M_WID, (((!(PCN_FLAG & BIT_FLAGS)) &&
											(ZERO & BIT_FLAGS)) ? '0' : ' '));
	else
		ARGBUFF = pad_right(fs, ARGBUFF, M_WID, ' ');
	if (CONV_INDEX == 8)
		arg_capitalize(fs);
	arg_prnt_mgmt(fs);
}

void		arg_capitalize(t_fs *fs)
{
	int	i;

	i = 0;
	while (ARGBUFF[i])
	{
		if (ARGBUFF[i] >= 'a' && ARGBUFF[i] <= 'z')
			ARGBUFF[i] -= 32;
		i++;
	}
}
