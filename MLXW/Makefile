# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihermell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/16 16:31:14 by ihermell          #+#    #+#              #
#    Updated: 2015/05/31 15:11:54 by ihermell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, all, re, reclean, fclean
NAME = mlxw.a
CFLAGS = -Wall -Wextra -Werror
SOURCES = draw_line_to_img.c \
		  mlx_get_blended_color.c \
		  mlx_new_image_struct.c \
		  mlx_put_pixel_to_img.c \
		  mlx_clear_image.c \
		  mlx_clear_half_image.c \
		  octants_1_4.c \
		  octants_5_8.c

OBJS = $(notdir $(SOURCES:.c=.o))

all: $(NAME)

$(NAME):
	@echo ""
	@echo ".: DRAW Library (c) Fcking Bresehenamnamstyle :."
	@echo "-------------------------------------------"
	@echo ""
	@echo "             Compilation ..."
	@echo ""
	@echo ""
	@gcc $(CFLAGS) -c $(SOURCES) -I ./ -I../MLX/
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo ">> Alright. SWIFT"
	@echo ""

clean:
	@rm -f $(OBJS)

fclean: clean 
	@rm -f $(NAME)

re: fclean all
	
reclean: re
	@rm -f $(OBJS)
