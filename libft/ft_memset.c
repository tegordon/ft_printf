/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 10:08:22 by tegordon          #+#    #+#             */
/*   Updated: 2019/08/02 23:15:40 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	- Writes _len bytes of value _c (converted to unsigned char) to string _b.
**
**  - Returns first argument.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len-- > 0)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}
