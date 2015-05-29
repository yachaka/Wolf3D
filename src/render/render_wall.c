/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 19:10:37 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/29 05:07:07 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			render_wall(t_w_intersection *i, t_env *e)
{
	t_wall		*wall;
	int			y1;
	int			y2;

	wall = &e->game->map->walls[i->wall];
	y1 = i->projected_y1;
	y2 = i->projected_y2;
	if (e->render->current_top > y2)
		return ;
	if (e->render->current_top > y1)
		y1 = e->render->current_top;
	setup_x1_y1_x2(e->render->column, y1, e->render->column, e->mlx->mlx_i);
	setup_y2_color(y2, 0xdddddd00 + 0x11111100 * i->wall, e->mlx->mlx_i);
	draw_line_to_img(e->screen, e->mlx->mlx_i);
	e->render->current_top = y2;
}
