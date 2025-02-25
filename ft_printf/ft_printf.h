/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noel-baz <noel-baz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:58:08 by noel-baz          #+#    #+#             */
/*   Updated: 2024/12/04 11:58:08 by noel-baz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putstrc(char *s);
int	ft_putnbrc(int n);
int	ft_putcharc(char c);
int	ft_print_p(void *ptr);
int	ft_print_hex_dig(unsigned int n, int flag, int base);
int	ft_show(char sp, va_list ap);

#endif