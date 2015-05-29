/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 18:57:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 05:56:41 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		check_portals(t_segment2 *ray, double base_distance, t_env *e)
{
	t_render	*r;

	r = e->render;
	if (r->tmp_wall->id == e->game->lportal->wall
		&& ray_in_portal(e->game->lportal, r->tmp_wall, r->tmp_inter->intersection.x,
		r->tmp_inter->intersection.y))
		render_through_portal(LEFT_PORTAL, ray, base_distance, e);
	if (r->tmp_wall->id == e->game->rportal
		&& ray_in_portal(e->game->rportal, r->tmp_wall, r->tmp_inter->intersection.x,
		r->tmp_inter->intersection.y))
		render_through_portal(RIGHT_PORTAL, ray, base_distance, e);
}

void			render_sector(t_segment2 *ray, t_sector *sector,
	   			double base_distance, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_render	*r;
	
	r = e->render;
	r->sector = sector;
	walls_intersected = cast_to_sector(ray, sector, base_distance, e);
	quicksort(r->sort, 0, walls_intersected - 1, qs_walls_cmp);
	i = -1;
	while (++i < walls_intersected)
	{
		r->tmp_inter = r->sort[i].content;
		r->tmp_wall = e->game->map->walls + r->tmp_inter->wall;
		check_portals(ray, base_distance, e);
		r->tmp_wall->column_rendered = r->column;
		render_floor(r->tmp_inter->projected_y1, sector, e);
		if (r->tmp_wall->is_portal == 0)
			render_wall(r->tmp_inter, e);
		else
		{
			r->tmp_sector = next_sector(r->tmp_wall, sector, e->game->map->sectors);
			render_step_up(sector, r->tmp_sector, r->tmp_inter, e);
			return (render_sector(ray, r->tmp_sector, base_distance, e));
		}
	}
}
