/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:35:14 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/21 21:46:32 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format_string, ...)
{
	t_fs	fs;

	if (!format_string || !*format_string)
		return (0);
	va_start(fs.args, format_string);
	init_t_fs(format_string, &fs);
	while (*fs.format_string_cursor)
	{
		if (*(fs.format_string_cursor) == '%')
			handle_percent(&fs);
		else
		{
			fs.total_bytes_printed += so_buff_mgmt(&fs, sizeof(char));
			*fs.so_buffer_cursor = *fs.format_string_cursor;
			++fs.so_buffer_cursor;
			++fs.format_string_cursor;
		}
	}
	va_end(fs.args);
	write(1, fs.so_buffer_start, (fs.total_bytes_printed - fs.by_prntd));
	free(fs.so_buffer_start);
	fs.so_buffer_start = NULL;
	return (fs.total_bytes_printed);
}

void	init_t_fs(char *format_string, t_fs *fs)
{
	SO_START = ft_strnew(INIT_SO_BUFF_SIZE);
	SO_CURSOR = SO_START;
	FS_START = format_string;
	FS_CURSOR = FS_START;
	ARGBUFF = NULL;
	SO_BUFF_CAPAC = INIT_SO_BUFF_SIZE;
	XPRE_FLAG = 0;
	NULL_ARGLEN = 0;
	BY_PRNTD = 0;
	TOTAL_BYTES_PRNTD = 0;
}
