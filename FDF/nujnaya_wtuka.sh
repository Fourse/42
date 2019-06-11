#!/bin/sh
gcc main.c reader.c image.c init.c keys.c libft/libft.a -lmlx -framework OpenGL -framework AppKit -g
