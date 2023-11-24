/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase_getlen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:54:02 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:07:26 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_putbase_getlen(unsigned long num, int base, int upper)
{
	static const char	set[] = "0123456789abcdef";
	char				c;
	int					len;

	len = 0;
	if (num >= (unsigned long)base)
		len += ft_putbase_getlen(num / base, base, upper);
	if (len == -1)
		return (-1);
	c = set[num % base];
	if (upper == 1)
		c = ft_toupper(c);
	len += write(STDOUT_FILENO, &c, 1);
	if (len == -1)
		return (-1);
	return (len);
}
