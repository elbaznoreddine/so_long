/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:56:59 by noel-baz          #+#    #+#             */
/*   Updated: 2025/02/06 18:00:53 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	int		num;

	num = n;
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	if (num == 0)
		return (ft_strdup("0"));
	size = get_num(num);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size--] = '\0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num != 0)
	{
		res[size--] = (num % 10) + 48;
		num /= 10;
	}
	return (res);
}
