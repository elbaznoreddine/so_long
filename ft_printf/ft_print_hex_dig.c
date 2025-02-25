/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_dig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:59:21 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/01 16:28:27 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_dig(unsigned int n, int flag, int base)
{
	int		count;
	char	*hex;

	count = 0;
	if (flag == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n >= (unsigned int)base)
	{
		count += ft_print_hex_dig(n / base, flag, base);
		count += ft_print_hex_dig(n % base, flag, base);
	}
	else
	{
		if (flag == 2)
			count += ft_putcharc(n + 48);
		else
			count += ft_putcharc(hex[n]);
	}
	return (count);
}
