/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:58:47 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/01 16:29:03 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrc(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += ft_putcharc('-');
		n = -n;
	}
	if (n > 9)
	{
		count += ft_putnbrc(n / 10);
		count += ft_putnbrc(n % 10);
	}
	else
		count += ft_putcharc(n + 48);
	return (count);
}
