/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2021/11/26 21:34:12 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	lenNeedle;
	size_t	i;

	lenNeedle = ft_strlen(needle);
	i = 0;
	if (lenNeedle > ft_strlen(haystack))
		return (NULL);
	if (lenNeedle == 0)
		return ((char *)&haystack[i]);
	if (len == 0)
		return (NULL);
	while (i <= (len - lenNeedle) && haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, lenNeedle) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
