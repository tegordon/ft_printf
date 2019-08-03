/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:17:24 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/25 20:47:26 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_first_flags(t_fs *fs, t_flgs *flgs)
{
	int	i;

	i = 1;
	while (i)
	{
		i = 0;
		if ((*(FS_CURSOR) == '#') && (i = 1))
			BIT_FLAGS = HASHTAG | BIT_FLAGS;
		else if ((*(FS_CURSOR) == '0') && (i = 1))
			BIT_FLAGS = ZERO | BIT_FLAGS;
		else if ((*(FS_CURSOR) == '-') && (i = 1))
			BIT_FLAGS = MINUS | BIT_FLAGS;
		else if ((*(FS_CURSOR) == '+') && (i = 1))
			BIT_FLAGS = PLUS | BIT_FLAGS;
		else if ((*(FS_CURSOR) == ' ') && (i = 1))
			BIT_FLAGS = SPACE | BIT_FLAGS;
		if (i == 1)
			++(FS_CURSOR);
	}
}

void	parse_min_width(t_fs *fs, t_flgs *flgs)
{
	if (*(FS_CURSOR) == '*')
	{
		BIT_FLAGS = MW_FLAG | BIT_FLAGS;
		M_WID = va_arg(ARGS, int);
		++(FS_CURSOR);
	}
	else if (*(FS_CURSOR) >= '0' && *(FS_CURSOR) <= '9')
	{
		BIT_FLAGS = MW_FLAG | BIT_FLAGS;
		M_WID = ft_atoi(FS_CURSOR);
		while (*(FS_CURSOR) >= '0' && *(FS_CURSOR) <= '9')
			++(FS_CURSOR);
	}
}

void	parse_precision(t_fs *fs, t_flgs *flgs)
{
	if (*(FS_CURSOR) == '.')
	{
		++(FS_CURSOR);
		if (*(FS_CURSOR) == '*')
		{
			PCN = va_arg(ARGS, int);
			++(FS_CURSOR);
		}
		else if (*(FS_CURSOR) >= '0' && *(FS_CURSOR) <= '9')
		{
			PCN = ft_atoi(FS_CURSOR);
			while (*(FS_CURSOR) >= '0' && *(FS_CURSOR) <= '9')
				++(FS_CURSOR);
		}
		BIT_FLAGS = PCN_FLAG | BIT_FLAGS;
	}
}

void	parse_len_mod1(t_fs *fs, t_flgs *flgs)
{
	if (*(FS_CURSOR) == 'h')
	{
		if (*(FS_CURSOR + 1) == 'h')
		{
			BIT_FLAGS = DOUBLE_H | BIT_FLAGS;
			++FS_CURSOR;
		}
		else
			BIT_FLAGS = SINGLE_H | BIT_FLAGS;
		++FS_CURSOR;
	}
	if (*(FS_CURSOR) == 'l')
	{
		if (*(FS_CURSOR + 1) == 'l')
		{
			BIT_FLAGS = DOUBLE_L | BIT_FLAGS;
			++FS_CURSOR;
		}
		else
			BIT_FLAGS = SINGLE_LC_L | BIT_FLAGS;
		++FS_CURSOR;
	}
}

void	parse_len_mod2(t_fs *fs, t_flgs *flgs)
{
	if (*(FS_CURSOR) == 'L')
	{
		BIT_FLAGS = SINGLE_UC_L | BIT_FLAGS;
		++FS_CURSOR;
	}
	if (*(FS_CURSOR) == 'z')
	{
		BIT_FLAGS = SINGLE_Z | BIT_FLAGS;
		++FS_CURSOR;
	}
}
