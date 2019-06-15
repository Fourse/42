#!/bin/sh
gcc main.c reader.c init.c color.c draw.c draw_line.c keys.c libft/libft.a -lmlx -framework OpenGL -framework AppKit -g
