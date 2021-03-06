/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/24 02:31:34 by ihermell          #+#    #+#             */
/*   Updated: 2015/06/01 08:52:00 by ihermell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf.h>

static void		init_mlx(t_env *e)
{
	e->mlx = (t_mlx*)malloc(sizeof(t_mlx));
	e->mlx->mlx = mlx_init();
	e->mlx->win = mlx_new_window(e->mlx->mlx, WIN_WIDTH, WIN_HEIGHT, "Wolfie3D");
	e->screen = mlx_new_image_struct(e->mlx->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->minimap = mlx_new_image_struct(e->mlx->mlx, MMAP_WIDTH, MMAP_HEIGHT);
	mlx_hook(e->mlx->win, KeyPress, KeyPressMask, keypress_hook, e);
	mlx_hook(e->mlx->win, KeyRelease, KeyReleaseMask, keyrelease_hook, e);
	mlx_mouse_hook(e->mlx->win, mouse_hook, e);
	mlx_hook(e->mlx->win, MotionNotify, PointerMotionMask, mouse_move_hook, e);
	mlx_loop_hook(e->mlx->mlx, loop_hook, e);
}

static t_game	*init_game(void)
{
	t_game		*game;

	game = (t_game*)malloc(sizeof(t_game));
	game->map = NULL;
	game->player = (t_player*)malloc(sizeof(t_player));
	fill_point2(207, 596.7, &game->player->pos);
	game->player->z_shift = 0;
	game->player->angle = 330;
	game->player->angle_cos = cos(D2R(330));
	game->player->angle_sin = sin(D2R(330));
	game->player->fov = PLAYER_FOV;
	game->player->height = PLAYER_HEIGHT;
	game->player->speed = PLAYER_BASE_SPEED;
	update_player_sight(game->player);
	game->lportal = (t_portal*)malloc(sizeof(t_portal));
	game->rportal = (t_portal*)malloc(sizeof(t_portal));
	game->lportal->wall = NULL;
	game->rportal->wall = NULL;
	game->lportal->sector = NULL;
	game->rportal->sector = NULL;
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
	p->shifted_y = WIN_HEIGHT / 2;
	p->distance_to_pp = (p->width / 2) / tan(D2R(PLAYER_FOV / 2));
	p->angle_btw_rays = PLAYER_FOV / (double)p->width;
	return (p);
}

t_env			*init_env(void)
{
	t_env		*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->game = init_game();
	env->pplane = init_pplane();
	env->input = (t_input*)malloc(sizeof(t_input));
	ft_bzero(env->input, sizeof(t_input));
	init_mlx(env);
	return (env);
}
