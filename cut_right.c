/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:25:43 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/25 19:07:41 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*cut_right(t_fs *fs, char *buff, int n)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(buff);
	if (n >= len)
		str = ft_strnew(0);
	else
	{
		i = 0;
		str = ft_strnew(len - n);
		while (i < (len - n))
			str[i++] = *buff++;
	}
	free(ARGBUFF);
	return (str);
}
