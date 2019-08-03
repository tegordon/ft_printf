/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 00:11:04 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/30 15:39:41 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_percent(t_fs *fs)
{
	t_flgs	flgs;

	++(FS_CURSOR);
	init_t_flgs(&flgs);
	parse_all_flags(fs, &flgs);
	parse_conv_type(fs, &flgs);
	print_conv_arg(fs, &flgs);
}

void	init_t_flgs(t_flgs *flgs)
{
	BIT_FLAGS = 0;
	M_WID = 0;
	PCN = 0;
	CONV_INDEX = 12;
}

void	parse_all_flags(t_fs *fs, t_flgs *flgs)
{
	parse_first_flags(fs, flgs);
	parse_min_width(fs, flgs);
	parse_precision(fs, flgs);
	while ((*(FS_CURSOR) == 'l') || (*(FS_CURSOR) == 'h') ||
			(*(FS_CURSOR) == 'L') || (*(FS_CURSOR) == 'z'))
	{
		parse_len_mod1(fs, flgs);
		parse_len_mod2(fs, flgs);
	}
}

void	parse_conv_type(t_fs *fs, t_flgs *flgs)
{
	char	*conv_types;
	int		i;

	i = 0;
	conv_types = CONVS_SPECS;
	while (conv_types[i] != '\0')
	{
		if (*(FS_CURSOR) == conv_types[i])
		{
			CONV_INDEX = i;
			++(FS_CURSOR);
			break ;
		}
		++i;
	}
}

void	print_conv_arg(t_fs *fs, t_flgs *flgs)
{
	static t_func_table dispatcher[] = {
		print_s,
		print_c,
		print_p,
		print_di,
		print_di,
		print_oub,
		print_oub,
		print_x,
		print_x,
		print_oub,
		print_di,
		print_percent,
		NULL
	};

	dispatcher[CONV_INDEX](fs, flgs);
}
