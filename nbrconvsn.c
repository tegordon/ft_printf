/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrconvsn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:20:50 by tegordon          #+#    #+#             */
/*   Updated: 2019/07/21 21:34:52 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*uintmaxtoa_base(uintmax_t uintarg, int base)
{
	char	*argstr;
	int		i;

	argstr = ft_memalloc(sizeof(char) * 32);
	i = 0;
	if (uintarg == 0)
		argstr[i++] = '0';
	while (uintarg)
	{
		argstr[i++] = "0123456789abcdef"[uintarg % base];
		uintarg /= base;
	}
	argstr[i] = '\0';
	ft_strrev(argstr);
	return (argstr);
}
