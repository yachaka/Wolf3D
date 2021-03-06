/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 22:24:27 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/31 10:14:21 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

void			process(t_env *e)
{
	if (e->input->a == 1)
		move_left(e);
	else if (e->input->d == 1)
		move_right(e);
	if (e->input->w == 1)
		move_forward(e);
	else if (e->input->s == 1)
		move_backward(e);
}
