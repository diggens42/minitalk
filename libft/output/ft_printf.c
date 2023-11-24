/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:48:02 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:24:34 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_format(char format, va_list *ap)
{
	if (format == '%')
		return (ft_putchar_getlen('%'));
	if (format == 'c')
		return (ft_putchar_getlen(va_arg(*ap, int)));
	if (format == 's')
		return (ft_putstr_getlen(va_arg(*ap, char *)));
	if (format == 'p')
		return (ft_putptr_getlen(va_arg(*ap, unsigned long)));
	if (format == 'd' || format == 'i')
		return (ft_putint_getlen(va_arg(*ap, int)));
	if (format == 'u')
		return (ft_putbase_getlen(va_arg(*ap, unsigned int), 10, 0));
	if (format == 'x')
		return (ft_putbase_getlen(va_arg(*ap, unsigned int), 16, 0));
	if (format == 'X')
		return (ft_putbase_getlen(va_arg(*ap, unsigned int), 16, 1));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	ap;
	char	*format;
	int		len;

	format = (char *)f;
	len = 0;
	va_start(ap, f);
	while (*format != '\0')
	{
		if (len == -1)
			return (-1);
		if (*format == '%')
		{
			format++;
			if (*format != '\0')
				len += ft_check_format(*format, &ap);
		}
		else
			len += ft_putchar_getlen(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
