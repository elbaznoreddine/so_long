/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:13:52 by noel-baz          #+#    #+#             */
/*   Updated: 2024/11/11 15:28:43 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_ned;

	i = 0;
	if (!*needle)
		return ((char *) haystack);
	len_ned = ft_strlen(needle);
	while (len > i && haystack[i])
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && j + i < len)
			j++;
		if (len_ned == j)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
