/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 16:19:06 by chanhale          #+#    #+#             */
/*   Updated: 2022/07/26 23:30:14 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"
#include "./do_not_submit/do_not_submit.h"

int	main(int argc, char **argv)
{
	t_bigbro	bigbro;

	int			error_ret;

	if (argc < 5 || argc > 6)
		return (0);
	if(init_bigbro_data(&bigbro, argv) == -1)
		return (0);
	//print_bigbro(&bigbro);
	error_ret = philosopher_thread_create(&bigbro);
	philosopher_thread_join(&bigbro, error_ret);
	clear_bigbro_data(&bigbro);
	system("leaks philosophers");
	return (0);
}
