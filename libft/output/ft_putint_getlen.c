/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_getlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:59:58 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:05:59 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putint_getlen(long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		len += ft_putchar_getlen('-');
		if (len == -1)
			return (-1);
		num = -num;
	}
	len += ft_putbase_getlen(num, 10, 0);
	return (len);
}
