#!/bin/sh
gcc main.c reader.c init.c keys.c tmp.c color.c libft/libft.a -lmlx -framework OpenGL -framework AppKit -g
