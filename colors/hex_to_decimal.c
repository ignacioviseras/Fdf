/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 20:38:35 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/27 21:47:15 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static int	parse_int(char s)
{
	if (s >= '0' && s <= '9')
		return (s - '0');
	else if (s >= 'A' && s <= 'Z')
		return (s - 'A' + 10);
	else if (s >= 'a' && s <= 'z')
		return (s - 'a' + 10);
	else
		return (-1);
}

int	hex_to_decimal(const char *str, int str_base)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str + 1 == '+' || *str + 1 == '-')
			return (0);
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0')
	{
		result = result * str_base + parse_int(*str);
		str++;
	}
	return (result * sign);
}
