/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_inter_in_portals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 05:03:53 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 07:00:23 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

t_portal		*w_inter_in_portals(t_w_intersection *w_inter,
				t_env *e)
{
	t_portal	*portal;

	portal = e->game->lportal;
	if (portal->wall
		&& portal->wall->id == w_inter->wall->id
		&& (fabs(portal->pos.x - w_inter->intersection.x) < PORTAL_WIDTH / 2
		&& fabs(portal->pos.y - w_inter->intersection.y) < PORTAL_WIDTH / 2))
		return (portal);
	portal = e->game->rportal;
	if (portal->wall
		&& portal->wall->id == w_inter->wall->id
		&& (fabs(portal->pos.x - w_inter->intersection.x) < PORTAL_WIDTH / 2
		&& fabs(portal->pos.y - w_inter->intersection.y) < PORTAL_WIDTH / 2))
		return (portal);
	return (NULL);
}
