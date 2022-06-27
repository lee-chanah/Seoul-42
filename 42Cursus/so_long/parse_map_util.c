/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:47:48 by chanhale          #+#    #+#             */
/*   Updated: 2022/06/27 18:42:26 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./so_long.h"

int	check_only_wall_in_line(char *line)
{
	size_t	index;

	index = 0;
	if (line == NULL)
		return (-1);
	while(line[index] != '\n' && line[index] != '\0')
	{
		if(line[index] != '1')
			return (-1);
		index++;
	}
	return (0);
}


void	printmap(t_map *map)
{
	t_pos *temp;
	int counter;
	printf("size_x: %zu\n", map->size_x);
	printf("size_y: %zu\n", map->size_y);
	printf("obstacles:\n");
	temp = map->obstacles;
	counter = 0;
	while (temp != NULL)
	{
		printf("obstacles[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("enemies:\n");
	temp = map->enemies;
	counter = 0;
	while (temp != NULL)
	{
		printf("enemies[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("exits:\n");
	temp = map->exits;
	counter = 0;
	while (temp != NULL)
	{
		printf("exits[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("collectibles:\n");
	temp = map->collectibles;
	counter = 0;
	while (temp != NULL)
	{
		printf("exits[%d] x:%zu y:%zu\n", counter, temp->x, temp->y);
		temp = temp->next;
		counter++;
	}
	printf("==================\n\n");
}