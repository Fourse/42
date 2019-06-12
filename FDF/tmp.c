#include "fdf.h"
void	image_set_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (x < 0 || x >= WEIGHT || y < 0 || y >= HEIGHT)
		return ;
	*(int *)(fdf->adr + ((x + y * WEIGHT) * fdf->bpp)) = color;
}

int			line_process_point(t_fdf *mlx, t_line *l, t_pixel *p1,
		t_pixel *p2)
{
	double	percent;

	if (p1->x < 0 || p1->x >= WEIGHT || p1->y < 0 || p1->y >= HEIGHT
		|| p2->x < 0 || p2->x >= WEIGHT || p2->y < 0 || p2->y >= HEIGHT)
		return (1);
	percent = (l->dx > l->dy ?
			ft_ilerp((int)p1->x, (int)l->start.x, (int)l->stop.x)
			: ft_ilerp((int)p1->y, (int)l->start.y, (int)l->stop.y));
	image_set_pixel(mlx, (int)p1->x, (int)p1->y, clerp(p1->color,
				p2->color, percent));
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void	clip_xy(t_pixel *v, t_pixel *p1, t_pixel *p2, int rout)
{
	if (rout & 1)
	{
		v->x = p1->x + (p2->x - p1->x) * (HEIGHT - p1->y) / (p2->y - p1->y);
		v->y = HEIGHT - 1;
	}
	else if (rout & 2)
	{
		v->x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
		v->y = 0;
	}
	else if (rout & 4)
	{
		v->x = WEIGHT - 1;
		v->y = p1->y + (p2->y - p1->y) * (WEIGHT - p1->x) / (p2->x - p1->x);
	}
	else
	{
		v->x = 0;
		v->y = p1->y + (p2->y - p1->y) * -p1->x / (p2->x - p1->x);
	}
}

int		region(int x, int y)
{
	int c;

	c = 0;
	if (y >= HEIGHT)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= WEIGHT)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

int		lineclip(t_pixel *p1, t_pixel *p2)
{
	t_pixel	v;
	int			r1;
	int			r2;
	int			rout;

	r1 = region(p1->x, p1->y);
	r2 = region(p2->x, p2->y);
	while (!(!(r1 | r2) || (r1 & r2)))
	{
		rout = r1 ? r1 : r2;
		clip_xy(&v, p1, p2, rout);
		if (rout == r1)
		{
			p1->x = v.x;
			p1->y = v.y;
			r1 = region(p1->x, p1->y);
		}
		else
		{
			p2->x = v.x;
			p2->y = v.y;
			r2 = region(p2->x, p2->y);
		}
	}
	return (!(r1 | r2));
}

void		line(t_fdf *mlx, t_pixel p1, t_pixel p2)
{
	t_line	line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	if (!lineclip(&p1, &p2))
		return ;
	line.dx = (int)ft_abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)ft_abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (line_process_point(mlx, &line, &p1, &p2))
			break ;
}

t_pixel	vector_at(t_map *map, int x, int y)
{
	return (*map->pixel[y * map->weigth + x]);
}

t_pixel	rotate(t_pixel p, t_cam *r)
{
	t_pixel	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}

t_pixel	project_vector(t_pixel v, t_fdf *mlx)
{
	v.x -= (double)(mlx->map->weigth - 1) / 2.0;
	v.y -= (double)(mlx->map->heigth - 1) / 2.0;
	v.z -= (double)(mlx->map->depthmin + mlx->map->depthmax) / 2.0;
	v = rotate(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	return (v);
}

void	clear_image(t_fdf *fdf)
{
	ft_bzero(fdf->adr, WEIGHT * HEIGHT * fdf->bpp);
}

void		render(t_fdf *fdf, t_map *map)
{
	int			x;
	int			y;
	t_pixel	v;
//	t_map		*map;

//	map = fdf->map;
	clear_image(fdf);
	x = 0;
	while (x < map->weigth)
	{
		y = 0;
		while (y < map->heigth)
		{
			v = project_vector(vector_at(map, x, y), fdf);
			if (x + 1 < map->weigth)
				line(fdf, v, project_vector(vector_at(map, x + 1, y), fdf));
			if (y + 1 < map->heigth)
				line(fdf, v, project_vector(vector_at(map, x, y + 1), fdf));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
}
