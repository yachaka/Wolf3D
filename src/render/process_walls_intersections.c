/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_walls_intersections.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 03:19:42 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 12:06:20 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			process_walls_intersections(int nb_walls, t_sector *sector,
				t_render *r, t_env *e)
{
	int			i;
	double		coef;
	double		z;
	t_w_intersection	*w_inter;

	i = -1;
	while (++i < nb_walls)
	{
		w_inter = r->w_intersection + i;
		if (w_inter->wall->column_rendered == e->column
			&& w_inter->wall->depth_rendered == r->depth)
			continue ;
		z = get_z_in_sector(sector, w_inter->intersection.x, w_inter->intersection.y);
		w_inter->distance += r->base_distance;
		w_inter->cos_distance = w_inter->distance * r->cos_ray_ref;
		coef = e->pplane->distance_to_pp / w_inter->cos_distance;
		w_inter->projected_y1 = floor(e->pplane->shifted_y -
			(PLAYER_HEIGHT - z) * coef);
		if (w_inter->wall->is_portal == 1)
			continue ;
		w_inter->projected_height = floor(w_inter->wall->height * coef);
		w_inter->projected_y2 = w_inter->projected_y1 + w_inter->projected_height;
	}
}
