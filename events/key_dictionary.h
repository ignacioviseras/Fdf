/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_dictionary.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:11:31 by igvisera          #+#    #+#             */
/*   Updated: 2024/03/07 13:07:18 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum asd{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	N_1 = 83,
	N_2 = 84,
	N_3 = 85,
	ESC = 53,
};


//need to see more events


// to use it
// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);