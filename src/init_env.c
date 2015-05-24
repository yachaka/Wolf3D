/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 02:31:34 by ihermell          #+#    #+#             */
/*   Updated: 2015/05/24 05:44:13 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static t_mlx	*init_mlx(void)
{
	t_mlx		*m;

	m = (t_mlx*)malloc(sizeof(t_mlx));
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 1400, 1000, "Wolfie3D");
	return (m);
}

static t_game	*init_game(void)
{
	t_game		*game;

	game = (t_game*)malloc(sizeof(t_game));
	game->input = (t_input*)malloc(sizeof(t_input));
	game->map = NULL;
	game->player = (t_player*)malloc(sizeof(t_player));
	game->player->x = 100;
	game->player->y = 400;
	game->player->angle = 135;
	game->player->fov = PLAYER_FOV;
	game->player->height = PLAYER_HEIGHT;
	game->player->current_sector = 0;
	return (game);
}

static t_pplane	*init_pplane(void)
{
	t_pplane	*p;

	p = (t_pplane*)malloc(sizeof(t_pplane));
	p->width = WIN_WIDTH;
	p->height = WIN_HEIGHT;
	p->center_x = WIN_WIDTH / 2;
	p->center_y = WIN_HEIGHT / 2;
	p->distance_to_pp = (p->width / 2) / tan(D2R(PLAYER_FOV / 2));
	p->angle_btw_rays = PLAYER_FOV / p->width;
	return (p);
}

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->game = init_game();
	env->mlx = init_mlx();
	env->pplane = init_pplane();
	mlx_key_hook(env->mlx->win, key_hook, &env);
	return (env);
}
