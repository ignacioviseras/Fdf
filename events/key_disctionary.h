/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_disctionary.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:11:31 by igvisera          #+#    #+#             */
/*   Updated: 2024/02/15 20:13:02 by igvisera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


//need to see more events


// to use it
// mlx_hook(vars.win, ON_DESTROY, 0, close, &vars);