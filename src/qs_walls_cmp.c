/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_walls_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 00:49:12 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/30 03:15:59 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

double					qs_walls_cmp(void *w1, void *w2)
{
	return (((t_w_intersection*)w1)->distance -
		((t_w_intersection*)w2)->distance);
}
