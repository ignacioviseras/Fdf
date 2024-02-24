/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:23:01 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/24 19:27:21 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static int	parse_int(char s)
{
    if (s >= '0' && s <= '9')
        return s - '0';
    else if (s >= 'A' && s <= 'Z')
        return s - 'A' + 10;
    else if (s >= 'a' && s <= 'z')
        return s - 'a' + 10;
    else
        return -1;
}

int	atoi_base(const char *str, int str_base)
{
	int result = 0;
    int sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
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
    return result * sign;
}
