/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:55:14 by fwahl             #+#    #+#             */
/*   Updated: 2023/10/14 16:14:37 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// typecast to unsigned char to go byte-by-byte
// traverses through the memory block '*b' and 
// assigns the value of 'c' for a number of 'len' bytes

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*conv_str;
	unsigned char	conv_c;
	size_t			i;

	conv_str = (unsigned char *)b;
	conv_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		conv_str[i] = conv_c;
		i++;
	}
	return (b);
}
