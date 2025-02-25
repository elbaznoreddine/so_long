/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:07:12 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/01 16:29:12 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_show(char sp, va_list ap)
{
	if (sp == 's')
		return (ft_putstrc(va_arg(ap, char *)));
	else if (sp == 'd' || sp == 'i')
		return (ft_putnbrc(va_arg(ap, int)));
	else if (sp == 'x')
		return (ft_print_hex_dig(va_arg(ap, unsigned int), 0, 16));
	else if (sp == 'X')
		return (ft_print_hex_dig(va_arg(ap, unsigned int), 1, 16));
	else if (sp == 'u')
		return (ft_print_hex_dig(va_arg(ap, unsigned int), 2, 10));
	else if (sp == 'p')
		return (ft_print_p(va_arg(ap, void *)));
	else if (sp == 'c')
		return (ft_putcharc(va_arg(ap, int)));
	return (0);
}
