/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad_left.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 22:25:59 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/23 17:56:41 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pad_left(t_fs *fs, char *buff, int n, char c)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(buff);
	if (len >= n)
		return (buff);
	i = 0;
	str = ft_strnew(n);
	if ((buff[i] == '-' || buff[i] == '+' || buff[i] == ' ') && (c == '0'))
	{
		str[i++] = *buff++;
		len--;
	}
	while (i < (n - len))
		str[i++] = c;
	while (i < n)
		str[i++] = *buff++;
	free(ARGBUFF);
	return (str);
}

/*
** - pad_left_xedge addresses the case when there is '0' flag, no PCN,
**   minw padding needed, and a HASHTAG flag has been added to conversions
**   x or X. This is a special case where the padding is inserted between
**   the 0x/0X and the rest of the number.
*/

char	*pad_left_xedge(t_fs *fs, char *buff, int n, char c)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(buff);
	if (len >= n)
		return (buff);
	i = 0;
	str = ft_strnew(n);
	if ((XPRE_FLAG == 1) && (c == '0'))
	{
		str[i++] = *buff++;
		str[i++] = *buff++;
		len -= 2;
	}
	while (i < (n - len))
		str[i++] = c;
	while (i < n)
		str[i++] = *buff++;
	free(ARGBUFF);
	XPRE_FLAG = 0;
	return (str);
}
