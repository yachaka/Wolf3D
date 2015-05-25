/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_to_sector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 21:14:44 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/25 23:56:52 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

int				cast_to_sector(t_segment2 *ray, t_sector *sector, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_point2	intersection;

	walls_intersected = 0;
	i = -1;
	while (++i < sector->nb_walls)
		if (intersection_segment2_to_segment2(ray,
			&e->game->map->walls[sector->walls[i]].seg, &intersection))
		{
			e->render->w_intersection[walls_intersected].wall = sector->walls[i];
			e->render->w_intersection[walls_intersected].distance = distance_point2(&intersection,
				&e->game->player->pos);
			walls_intersected++;
		}
	return (walls_intersected);
}