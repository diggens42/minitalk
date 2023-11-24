/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_getlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:06:02 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:03:59 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_getlen(unsigned long num)
{
	int	len;
	int	ret;

	ret = ft_putstr_getlen("0x");
	if (ret == -1)
		return (-1);
	len = ft_putbase_getlen(num, 16, 0) + 2;
	if (len == -1)
		return (-1);
	return (len);
}
