/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:19:06 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/28 14:55:05 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

int	main(int argc, char **argv)
{
	t_bigbro	bigbro;

	if (argc < 5 || argc > 6)
		return (0);
	if (init_bigbro_data(&bigbro, argv) == -1)
		return (0);
	philosopher_thread_create(&bigbro);
	clear_bigbro_data(&bigbro);
	return (0);
}
