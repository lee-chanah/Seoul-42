/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:13:15 by chanhale          #+#    #+#             */
/*   Updated: 2021/09/30 18:37:52 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char	c;
	i = -1;
	if (argc == 2)
		while(argv[1][++i])
		{
			c = argv[1][i];
			if (c <= 90 && c >= 65)
				c = 155 - c;
			if (c <= 122 && c >= 97)
				c = 219 - c;
			write(1, &c, 1);
		}
	write(1, "\n", 1);
}
