/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:43:36 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/13 18:31:43 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char *argv[])
{
    char *file;
    
    if (argc != 2)
        return (0);
    else
    {
        file = argv[1];
        char *x = ft_strjoin("cat ", file);
    	system(x);

    }
        // printf("%s", argv[1]);
    return (0);
}
