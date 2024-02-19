/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:58:11 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/19 21:59:00 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

int	ft_atoi(const char *nptr)
{
	int	index;
	int	sign;
	int	num;

	index = 0;
	sign = 1;
	num = 0;
	while (nptr[index] == ' ' || nptr[index] == '\t' || nptr[index] == '\n'
		|| nptr[index] == '\v' || nptr[index] == '\f' || nptr[index] == '\r')
		index++;
	while (nptr[index] == '+' || nptr[index] == '-')
	{
		if (nptr[index + 1] == '+' || nptr[index + 1] == '-')
			return (0);
		if (nptr[index] == '-')
			sign *= -1;
		index++;
	}
	while (nptr[index] < '0' && nptr[index] > '9')
		index++;
	while (nptr[index] >= '0' && nptr[index] <= '9')
		num = num * 10 + (nptr[index++] - '0');
	num *= sign;
	return (num);
}
