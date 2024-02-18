/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:20:09 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/18 20:50:42 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../utils.h"
/*
	Escriba una función que convierta el argumento de 
	cadena str (base N <= 16) a un número entero (base 10) y lo devuelve.
	Los caracteres reconocidos en la entrada son: 0123456789abcdef
	Por supuesto, estos deben recortarse según la base solicitada.
	Para Por ejemplo, la base 4 reconoce "0123" y la base 16 reconoce "0123456789abcdef".
	También se deben reconocer las letras mayúsculas: "12fdb3" es lo mismo que "12FDB3".
	Los signos menos ('-') se interpretan sólo si son el primer carácter del cadena.
	Su función debe declararse de la siguiente manera:
*/

int	ft_atoi_base(const char *str, int str_base)
{
	// HEXUPPER
	char	*str_upper;
	// int	aux;

	str_upper = ft_toupper(str);
	// if (n > 15)
	// {
	// 	count += ft_print_hex((n / 16), baseFormat);
	// 	aux = baseFormat[(n % 16)];
	// 	count = &aux;
	// }
	// else
	// {
	// 	aux = baseFormat[(n % 16)];
	// 	count += write(1, &aux, 1);
	// }
	return (0);
}

// static char	*ft_toupper(char *s)
// {
// 	// , int c
// 	int	i;

// 	i = 2;
// 	ft_printf("accede-> '%s'\n", s);
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] >= 'a' && s[i] <= 'z')
// 			s[i] = s[i] - 32;
// 		i++;
// 	}
// 	ft_printf("formateado-> '%s'\n", s);
// 	return (s);
// }

int main()
{
	ft_toupper("0xFF0000");
	return (0);
}