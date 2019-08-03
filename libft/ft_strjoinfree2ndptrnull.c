/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree2ndptrnull.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tegordon <tegordon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 08:15:26 by tegordon          #+#    #+#             */
/*   Updated: 2019/08/02 23:00:03 by tegordon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** - Allocates with malloc(3) and returns a "fresh" string ending with '\0',
**   result of the concatenation of s1 and s2.
** - Frees s2.
** - If the allocation fails, the fxn returns NULL.
** - s2 is passed in as a null char so strlen(s2) is represented as 1.
*/

#include "libft.h"

char		*ft_strjoinfree2ndptrnull(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1)
		return (NULL);
	if (!(s3 = ft_strnew(ft_strlen(s1) + sizeof(char))))
		return (NULL);
	ft_memcpy(s3, s1, ft_strlen(s1));
	ft_strcat(s3, s2);
	free((char *)s2);
	return (s3);
}
