/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_getlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:53:17 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:04:30 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_getlen(char *str)
{
	int	len;
	int	ret;

	len = 0;
	if (!str)
	{
		ret = ft_putstr_getlen("(null)");
		if (ret == -1)
			return (-1);
		return (6);
	}
	while (str[len] != '\0')
	{
		ret = write(STDOUT_FILENO, &str[len], 1);
		if (ret == -1)
			return (-1);
		len++;
	}
	return (len);
}
