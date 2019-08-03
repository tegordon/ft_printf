/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_right.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:26:23 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/12 16:16:00 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pad_right(t_fs *fs, char *buff, int n, char c)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(buff);
	if (len >= n)
		return (buff);
	i = 0;
	str = ft_strnew(n);
	while (i < len)
		str[i++] = *buff++;
	while (i < n)
		str[i++] = c;
	free(ARGBUFF);
	return (str);
}
