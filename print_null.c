/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 23:11:40 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/25 18:37:48 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define MS make_string
#define SJN ft_strjoinfree2ndptrnull
#define PADRN pad_right_null
#define PADLN pad_left_null

int		print_null(t_fs *fs, t_flgs *flgs)
{
	char	c;

	c = 0;
	ARGBUFF = SJN(ARGBUFF, MS(c));
	if ((MINUS & BIT_FLAGS) && (MW_FLAG & BIT_FLAGS))
		ARGBUFF = PADRN(fs, ARGBUFF, M_WID, ' ');
	else if (MW_FLAG & BIT_FLAGS)
		ARGBUFF = PADLN(fs, ARGBUFF, M_WID, ' ');
	else
		NULL_ARGLEN = 1;
	TOTAL_BYTES_PRNTD += so_buff_mgmt_null(fs, NULL_ARGLEN);
	free(ARGBUFF);
	ARGBUFF = NULL;
	NULL_ARGLEN = 0;
	return (1);
}

char	*pad_left_null(t_fs *fs, char *buff, int n, char c)
{
	char	*str;
	int		len;
	int		i;

	len = sizeof(char);
	if (len >= n)
		return (buff);
	i = 0;
	str = ft_strnew(n);
	while (i < (n - len))
		str[i++] = c;
	str[i++] = 0;
	free(ARGBUFF);
	NULL_ARGLEN = (size_t)i;
	return (str);
}

char	*pad_right_null(t_fs *fs, char *buff, int n, char c)
{
	char	*str;
	int		len;
	int		i;

	len = sizeof(char);
	if (len >= n)
		return (buff);
	i = 0;
	str = ft_strnew(n);
	str[i++] = 0;
	while (i < n)
		str[i++] = c;
	free(ARGBUFF);
	NULL_ARGLEN = (size_t)i;
	return (str);
}
