/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 19:49:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:43:10 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
		send_portal(e->game->lportal, e->game->player, e);
	else if (button == 2)
		send_portal(e->game->rportal, e->game->player, e);
	(void)x;
	(void)y;
	(void)e;
	return (0);
}
