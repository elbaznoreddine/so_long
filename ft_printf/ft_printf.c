/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:40:22 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/01 16:28:40 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_sp(char c)
{
	return (c == 's' || c == 'i' || c == 'd' || c == 'X'
		|| c == 'x' || c == 'u' || c == 'p' || c == 'c');
}

static int	check_format(const char *format, va_list ap)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && is_sp(format[i + 1]))
		{
			count += ft_show(format[++i], ap);
		}
		else if (format[i] == '%' && format[i + 1] == '%')
			count += ft_putcharc(format[++i]);
		else if (format[i] == '%' && !is_sp(format[i + 1]))
		{
			if (format[i + 1])
				count += ft_putcharc(format[++i]);
			else
				break ;
		}
		else
			count += ft_putcharc(format[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	argument_pointer;
	int		counter_format;

	counter_format = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(argument_pointer, format);
	counter_format += check_format(format, argument_pointer);
	va_end(argument_pointer);
	return (counter_format);
}
