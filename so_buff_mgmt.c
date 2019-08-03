/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_buff_mgmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:25:14 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/23 16:38:19 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define DOUBLE(x) ((x) << 1)

void		arg_prnt_mgmt(t_fs *fs)
{
	TOTAL_BYTES_PRNTD += so_buff_mgmt(fs, ft_strlen(ARGBUFF));
	SO_CURSOR = ft_strcatend(SO_CURSOR, ARGBUFF);
	free(ARGBUFF);
	ARGBUFF = NULL;
}

size_t		so_buff_mgmt(t_fs *fs, size_t arg_len)
{
	char	*copy_s;

	while ((TOTAL_BYTES_PRNTD + arg_len) >= SO_BUFF_CAPAC)
	{
		if (!(copy_s = (char *)ft_memalloc(sizeof(char)
							* (DOUBLE(SO_BUFF_CAPAC)))))
			return (0);
		SO_BUFF_CAPAC += SO_BUFF_CAPAC;
		SO_CURSOR = ft_strcpyend(copy_s, SO_START);
		free(SO_START);
		SO_START = copy_s;
	}
	return (arg_len);
}

size_t		so_buff_mgmt_null(t_fs *fs, size_t arg_len)
{
	size_t	so_buff_len;

	if ((SO_CURSOR - SO_START) > 0)
	{
		so_buff_len = ft_strlen(SO_START);
		write(1, SO_START, so_buff_len);
		BY_PRNTD += so_buff_len;
		ft_bzero(SO_START, so_buff_len);
		free(SO_START);
		SO_START = ft_strnew(INIT_SO_BUFF_SIZE);
		SO_CURSOR = SO_START;
		SO_BUFF_CAPAC = INIT_SO_BUFF_SIZE;
	}
	write(1, ARGBUFF, arg_len);
	BY_PRNTD += arg_len;
	return (arg_len);
}
