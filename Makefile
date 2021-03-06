# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihermell <ihermell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/03 22:55:20 by ihermell          #+#    #+#              #
#    Updated: 2015/06/01 06:26:17 by ihermell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME		= wolf3d

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -O3

EXT_SRC		= GNL/get_next_line.c \
			  BMP/load_bmp.c

SRC_DIR		= src/
SRC_NAME	=	main.c \
				init_env.c \
				load_map.c \
				process.c \
				\
				player/set_player_angle.c \
				player/update_player_sight.c \
				player/turn_left.c \
				player/turn_right.c \
				player/move_forward.c \
				player/move_backward.c \
				player/move_left.c \
				player/move_right.c \
				player/process_player_movement.c \
				\
				cast/cast_to_sector_walls.c \
				\
				render/render.c \
				render/render_step_up.c \
				render/render_floor.c \
				render/render_wall.c \
				render/process_walls_intersections.c \
				render/render_sector.c \
				render/render_portal.c \
				render/render_through_portal.c \
				render/render_portal_overlay.c \
				\
				render_struct/init_render_struct.c \
				render_struct/set_render_struct_ray_angle.c \
				\
				portals/w_inter_in_portals.c \
				portals/is_portal_visible.c \
				portals/the_other_portal.c \
				portals/get_portal_new_pos.c \
				portals/get_portal_color.c \
				portals/send_portal.c \
				portals/set_portal_angle.c \
				\
				minimap/render_minimap.c \
				minimap/render_minimap_portal.c \
				\
				overlay/render_cursor.c \
				sector/get_z_in_sector.c \
				\
				walls/next_sector.c \
				\
				textures/load_texture.c \
				\
				mlx_hooks/keypress_hook.c \
				mlx_hooks/keyrelease_hook.c \
				mlx_hooks/mouse_hook.c \
				mlx_hooks/mouse_move_hook.c \
				mlx_hooks/expose_hook.c \
				mlx_hooks/loop_hook.c \
				\
				quicksort/quicksort.c \
				qs_walls_cmp.c \
				\
				set_ray.c

SRC			+= $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR		= obj/
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ			= $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIBFT_DIR	= Libft/
LIBFT_NAME	= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

INC_DIR		= -I $(addprefix $(LIBFT_DIR), include/) \
			  -I 3DSPACE/include \
			  -I MLX/ \
			  -I MLXW/ \
			  -I include/ \
			  -I GNL/ \
			  -I BMP/include/

LIBRARIES	= -L $(LIBFT_DIR) -lft -L MLX/ -lmlx 3DSPACE/space3d.a MLXW/mlxw.a

FRAMEWORKS	= -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(LIBFT) $(SRC) $(EXT_SRC)
	@echo "##"
	@echo "                                           === Wolfie3D ==="
	@echo "                          ...                                               ...... ..............   "
	@echo "                        ......               ......     ...                ........................ "
	@echo "                    .........               ..       ........        .. ............................"
	@echo "                    ................                .....        .................................. "
	@echo "          ..          ............                   ...   'c:':.    ...........   ...........      "
	@echo "                                                          ;xkocc:;;'',     ..       ...........     "
	@echo "         ..                                            .,dKX0xlclolc'';               .........     "
	@echo "       .......                                        .cOKXK0xoooodo, ';                   ...      "
	@echo "     ...........    ..                        ....  .,dkkOOOOkxdddko. .'           .                "
	@echo "    ...................                      ...'',:lddxO0000Okkkxxc. .'                            "
	@echo "   ....................                  .':oxO0000OxxOO0KKXK00Okxc.  .,. .                         "
	@echo "     ....     ..........            ...,cokKNNOoxOOO0KNNXXKK0OOkxc.   ..........                    "
	@echo "               ..........          .':oddookkoclOKKKXXNWNNXK0Okdo;.   ..',....,,.                   "
	@echo "                ..........  .      :xxoc:::ldONNXKKXXKKKXKKK0Oxddc;,,..... ..';:..                  "
	@echo "                  ...........    ;oxolclcccokXXXXKKKKKK0KXK00OkkOkdoc;'..',,;:oc..                  "
	@echo "                   ........    ;oxdolccllllooxOKKKKXKKKXXKK000OOOxddddolloddxxo'.                   "
	@echo "                  .....     ':oxxolccclloddooxOKXXXKKKXXXKK0OkkOOkxddxxkkOOko;.                     "
	@echo "                 .....     ;:cllcc:cccloodddkOKNWWWWNNNWNK0OOOkkkxdddkkO0Oo'...                     "
	@echo "   ..             ..     ,;,...'',,;cclooodONWWWWWMMMWMWXkxkkkdodddxOO00k:.  .                      "
	@echo " .........           ;colc:,,'.....':looodx0NNWWWWMMMMMW0kOOOkxxxxkOO0Kk;.                          "
	@echo "  ..             ,;cloxkxoc;,,'''..,codddxkxkOOKNWWXNWMWKkxxxxkxkkOOOOo,...                         "
	@echo "              ,;;:ccclddocc::;,'..'cdkkxxxdxkxx0NXXXNWWKkddxxkkkkO0Ol......                         "
	@echo "           ...',,''''',:ccc;:cc;'...;oxkxdk0XKK00KXNNNXOxddodxkOkkOKx'.......                       "
	@echo "             ..''........'.'''''',;''cxOK00XX00XK00XWWNKOkkkOK0OkOXXl........                       "
	@echo "              ..,,,'',,,,,;c;...''...;dOKKXXXXNNNNNNWWX0kdoxOXKOOKNNo........                       "
	@echo "             .':lc:,'''''.''....','',,;dOO0XNNNNWWWMWNK0OO0OOK0OKXNWd..     ..                      "
	@echo "           ..,cllc:;::::cllcccclllccc:;cdxk0KNNNXXNNNXKKKKXNNXOKNXNNd.         ..           ...     "
	@echo "         .,clllloolllcloooddxxxddollllccccoxk00KKKOk0000OxdONNXXXKNWd.                              "
	@echo "       .,cooddollllllllolldxxxxxdoolc;;cccc:cc::clooodk0KK00K00XNXXk;.                              "
	@echo "  .',,,coollodocclc::clooodddxxkkdooollc::;;:::;,';llook00KXKOOKWNO:..           ..                 "
	@echo "..';lllodolccllc::;:cccloxxdxkddkxxxdk0Oxdoc:::cllodxkOOO00KNK0XWXo'.           ....                "
	@echo "..,;:cclllcc::c::cc:cl::dOxdxxxxxxxxdkOkkkxol::cdkxddxO0000KXNXNWKo'.                        .      "
	@echo "..',,;;;;c:,;;;;;;',;:::oxxxkxooxxddxkxddooollolldxkO0O0KKKKNMWNKo..                                "
	@echo "'.','';;;:;;;:,,,,,,,;:codloxxddxxooddoolccccll::cldkOkO0KKKNWWW0:.                                 "
	@echo ",,,,''.';;;,';;;,,;,,;:coolodxxxxdxoc:::cc;;:cc::llodkkO0XXXNWN0x,.                                 "
	@echo ";'''''....',;;,,,,'';c:cdxdooxddocll;,,;::,,;:cclloooxOOO0XXNWKl..   ..........    ......           "
	@echo ";,''.'......,,,:ll:;:c:odxkdclxxl:c:,,,,,,,,;;:cccclodkO0KNWWWNx,.   ........................       "
	@echo ";,'''.........',:lcclcodddddooddddl:;;,;,,;;::;:ccclooodk0XNWWWO:.    ........................      "
	@echo ":;;,,...........';cddldxxxddxxolodo:::::c::cllccclllooookOKXNNXOc'.                   ...  ....     "
	@echo ":;,''..........''',coloxxdoddxdcllllclccclccclllodooddddk0XXNXOl;'...      ..                       "
	@echo ":,','..........''''';;cddooocodlloddoddddddoddolodddddxxxO0KKOl,......    ......   ...  ............"
	@echo "lc:,'..........''''''.'clooooooloxxxxkxxxddoodoooodxxxxkkkO0kl,................   .................."
	@echo "lc;.........''',,,,''..,;;:clcccldxxkkxxOOkkdodddddddxkOOOkdc,......................................"
	@echo "ll:;'.........',;,,,,,'''''',,,,;:coxxdxOOOOkkkxkkkxdxkOOOkc'.......................  .............."
	@echo "ooc:,.......'',,,;:::;,,'',,,,,,;;;clddxOOOOkkOOkxxxxxkkkdc,.......................            ..   "
	@echo "lol::,......',,;:cc::::::;;;;;:::c:cccodxOOkOkO0Okkkkkkkx:'.......................                  "
	@echo "loolc;'.....',;;:cllc:ccc::c::ccccccccclldxkOO00OkkkkO0xc'.........       ......    .....  ....     "
	@echo "loodo:,.....',;::ccc:clolcccccllc::ccllooooxxO00000O0kl;'...............         ................   "
	@echo "lodddc:;,....';::cccloolllloolclcccccccllodddOK000K0d:'..................   ..   ..................."
	@echo "loodoccc;''''';;:clodoooooodocoolloooocccldxdx0K0OOd,..........................  .... .............."
	@echo "oooolcll:,,'',;:cloooodddoodolooloxllodolodkkkOK0ko,..............................     ............."
	@$(CC) $(CFLAGS) $(INC_DIR) $(LIBRARIES) $(FRAMEWORKS) $(EXT_SRC) $(SRC) -o $(NAME)
	@echo " ~ WOUF WOUF ~."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null
	$(CC) $(CFLAGS) $(INC_DIR) -o $@ -c $<;
	@mkdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null

$(LIBFT):
	@make -C $(LIBFT_DIR) re

clean:
	@echo "Cleaning..."
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@make -C $(LIBFT_DIR) clean
	@echo "-- So clean."

libft_clean:
	@make -C $(LIBFT_DIR) clean

libft_fclean:
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
