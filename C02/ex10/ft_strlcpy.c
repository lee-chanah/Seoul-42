/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chahale <chahale@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:53:13 by chahale           #+#    #+#             */
/*   Updated: 2021/09/16 20:13:48 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	temp1;
	unsigned int	counter1;
	unsigned int	counter2;

	counter1 = 0;
	counter2 = 0;
	temp1 = 0;
	while (src[counter1] != '\0')
		counter1++;
	while (src[temp1] != '\0' && temp1 < size - 1)
	{
		dest[temp1] = src[temp1];
		temp1++;
	}
	if (size != 0)
		dest[temp1] = '\0';
	return (counter1);
}
