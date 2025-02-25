/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:59:11 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/01 16:28:32 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_hex_ptr(unsigned long p)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (p >= 16)
	{
		count += print_hex_ptr(p / 16);
		count += print_hex_ptr(p % 16);
	}
	else
		count += ft_putcharc(hex[p]);
	return (count);
}

int	ft_print_p(void *ptr)
{
	int	count;

	count = 0;
	count += ft_putstrc("0x");
	if (!ptr)
		return (count += ft_putcharc('0'));
	count += print_hex_ptr((unsigned long)ptr);
	return (count);
}
