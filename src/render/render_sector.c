/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 18:57:07 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 08:31:25 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static int		check_portals(double base_distance, t_env *e)
{
	t_render	*r;

	r = e->render;
	if (e->game->lportal->wall && r->tmp_wall->id == e->game->lportal->wall->id
		&& ray_in_portal(e->game->lportal, r->tmp_wall, r->tmp_inter->intersection.x,
		r->tmp_inter->intersection.y))
	{
		render_through_portal(LEFT_PORTAL, base_distance, e);
		return (1);
	}
	if (e->game->rportal->wall && r->tmp_wall->id == e->game->rportal->wall->id
		&& ray_in_portal(e->game->rportal, r->tmp_wall, r->tmp_inter->intersection.x,
		r->tmp_inter->intersection.y))
	{
		render_through_portal(RIGHT_PORTAL, base_distance, e);
		return (1);
	}
	return (0);
}

void			render_sector(t_segment2 *ray, t_sector *sector,
	   			double base_distance, t_env *e)
{
	int			walls_intersected;
	int			i;
	t_render	*r;
	
	r = e->render;
	walls_intersected = cast_to_sector(ray, sector, base_distance, e);
	quicksort(r->sort, 0, walls_intersected - 1, qs_walls_cmp);
	i = -1;
	while (++i < walls_intersected)
	{
		r->tmp_inter = r->sort[i].content;
		r->tmp_wall = e->game->map->walls + r->tmp_inter->wall;
		r->tmp_wall->column_rendered = r->column;
		render_floor(r->tmp_inter->projected_y1, sector, e);
		if (check_portals(base_distance, e))
			;
		else if (r->tmp_wall->is_portal == 0)
			render_wall(r->tmp_inter, e);
		else
		{
			r->tmp_sector = next_sector(r->tmp_wall, sector, e->game->map->sectors);
			render_step_up(sector, r->tmp_sector, r->tmp_inter, e);
			return (render_sector(ray, r->tmp_sector, base_distance, e));
		}
	}
}
