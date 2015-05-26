/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 18:57:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/26 21:19:48 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_sector(t_segment2 *ray, t_sector *sector, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_wall		*wall;
	t_render	*r;

	walls_intersected = cast_to_sector(ray, sector, e);
	i = -1;
	r = e->render;
	while (++i < walls_intersected)
	{
		wall = &e->game->map->walls[r->w_intersection[i].wall];
		draw_wall(wall, 0xFF0000, e);
	}
}
