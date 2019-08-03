/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:23:49 by tegordon          #+#    #+#             */
/*   Updated: 2019/08/02 23:00:03 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	- appends a copy of the null-terminated string /s2 to the end of the
**  null-terminated string /s1, then adds a terminating '\0'.
**
**  - returns a pointer to the null-termination at the end of the string.
**
**	- string /s1 must have sufficient space to hold the result.
*/

#include "libft.h"

char		*ft_strcatend(char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j])
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (&s1[i]);
}
