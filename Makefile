# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 23:11:09 by orazafy           #+#    #+#              #
#    Updated: 2023/12/15 01:02:07 by orazafy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=500
IFLAGS = -I$(INCDIR) -I$(MINILIBXDIR) -I$(LIBFTDIR)

LIBS = $(MINILIBXDIR)/libmlx.a $(LIBFTDIR)/libft.a
LFLAGS = -lX11 -lXext -lm -L$(LIBFTDIR) -lft

SRCDIR = srcs
OBJDIR = objs
BINDIR = bin
INCDIR = include

MINILIBXDIR = minilibx
LIBFTDIR = libft

PARSINGDIR = parsing
RAYCASTINGDIR = raycasting

PARSING_FILES = build_map.c \
			build_file.c \
			ft_check_tex_files.c \
			scan_file.c \
			ft_get_tex_path.c

RAYCASTING_FILES = ft_close_window.c \
			ft_draw_line.c \
			ft_errors.c \
			ft_free_map.c \
			ft_get_pixel.c \
			ft_init_all_tex_img.c \
			ft_init_all.c \
			ft_init_drawing_param.c \
			ft_init_player_view.c \
			ft_launch_game.c \
			ft_move_player.c \
			ft_move.c \
			ft_put_pixel.c \
			ft_rotate.c

PARSING = $(addprefix $(PARSINGDIR)/, $(PARSING_FILES))
RAYCASTING = $(addprefix $(RAYCASTINGDIR)/, $(RAYCASTING_FILES))

SRCS = $(addprefix $(SRCDIR)/, cub3d.c $(PARSING) $(RAYCASTING))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCS = $(INCDIR)/cub3d.h

NAME = $(BINDIR)/cub3D

RMR = rm -rf
MKDIR_P = mkdir -p

MLX = $(MINILIBXDIR)/libmlx.a
LIBFT = $(LIBFTDIR)/libft.a

all: $(NAME)

$(MLX):
	cd $(MINILIBXDIR) && make

$(LIBFT) :
	cd $(LIBFTDIR) && make

$(NAME): $(OBJS) $(MLX) $(LIBFT)| $(BINDIR)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBS) $(LFLAGS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS) | $(OBJDIR)
	$(MKDIR_P) $(@D)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(BINDIR):
	$(MKDIR_P) $(BINDIR)

$(OBJDIR):
	$(MKDIR_P) $(OBJDIR)

clean:
		$(RMR) $(OBJDIR)
		cd $(LIBFTDIR) && make clean
		cd $(MINILIBXDIR) && make clean

fclean: clean
		$(RMR) $(BINDIR)
		cd $(LIBFTDIR) && make fclean
		$(RMR) $(LIBS)

re: fclean all

bonus:

.PHONY: all clean fclean re bonus
