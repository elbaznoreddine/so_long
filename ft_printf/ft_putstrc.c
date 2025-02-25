/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:58:16 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/01 16:29:08 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrc(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write(1, s, 1);
		count++;
		s++;
	}
	return (count);
}
