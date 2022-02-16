/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 21:34:04 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstLen;
	size_t	srcLen;

	dstLen = 0;
	srcLen = ft_strlen(src);
	while (dstLen < size && ft_isprint(dst[dstLen]))
		dstLen++;
	if (dstLen >= size)
		return (dstLen + srcLen);
	ft_strlcpy(dst + dstLen, src, size - dstLen);
	return (dstLen + srcLen);
}
