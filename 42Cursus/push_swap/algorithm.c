/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhale <chanhale@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:08:09 by chanhale          #+#    #+#             */
/*   Updated: 2022/03/01 02:19:05 by chanhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_subsidiary
	(t_stack *stack_a, t_stack *stack_b, int bias, int counter)
{
	if (counter <= 0 || stack_b->quantity <= 0 || stack_a->quantity <= 0)
		return ;
	if ((bias == TYPE_OP_BIAS_A
			&& stack_a->top->content > stack_b->top->content)
		|| (bias == TYPE_OP_BIAS_B
			&& stack_a->top->content < stack_b->top->content))
	{
		operator(stack_a, stack_b, TYPE_OP_PX + bias);
		operator(stack_a, stack_b, TYPE_OP_RR + bias);
		merge_subsidiary(stack_a, stack_b, bias, counter - 1);
		operator(stack_a, stack_b, TYPE_OP_RR + bias);
	}
	else
	{
		operator(stack_a, stack_b, TYPE_OP_RR + bias);
		merge_subsidiary(stack_a, stack_b, bias, counter - 1);
		operator(stack_a, stack_b, TYPE_OP_PX + bias);
		operator(stack_a, stack_b, TYPE_OP_RR + bias);
	}
}

static void	merge_first_sequence(t_stack *stack_a, t_stack *stack_b)
{
	int	counter;

	if (check_sorted(stack_a, TYPE_STRAIGHT))
		return ;
	while (stack_a->quantity > stack_b->quantity + 2)
	{
		if (stack_a->top->content < stack_a->top->before->content)
			operator(stack_a, stack_b, TYPE_OP_SA);
		operator(stack_a, stack_b, TYPE_OP_PB);
		operator(stack_a, stack_b, TYPE_OP_PB);
	}
	counter = stack_a->quantity / 2;
	while (counter--)
	{
		if (stack_a->top->content > stack_a->top->before->content)
			operator(stack_a, stack_b, TYPE_OP_SA);
		operator(stack_a, stack_b, TYPE_OP_RA);
		operator(stack_a, stack_b, TYPE_OP_RA);
	}
	if (stack_a->quantity % 2)
		operator(stack_a, stack_b, TYPE_OP_RA);
}

static void	merge_small_seq_a(t_stack *stack_a, t_stack *stack_b, int n_a, int n_b)
{
	while (n_a && n_b)
		if (stack_a->top->content > stack_b->top->content)
		{
			operator(stack_a, stack_b, TYPE_OP_PA);
			operator(stack_a, stack_b, TYPE_OP_RA);
			n_b--;
		}
		else
		{
			operator(stack_a, stack_b, TYPE_OP_RA);
			n_a--;
		}
	while (n_a-- > 0)
		operator(stack_a, stack_b, TYPE_OP_RA);
	while (n_b-- > 0)
	{
		operator(stack_a, stack_b, TYPE_OP_PA);
		operator(stack_a, stack_b, TYPE_OP_RA);
	}
}

static void	merge_small_seq_b(t_stack *stack_a, t_stack *stack_b, int n_a, int n_b)
{
	while (n_a && n_b)
		if (stack_b->top->content > stack_a->top->content)
		{
			operator(stack_a, stack_b, TYPE_OP_PB);
			operator(stack_a, stack_b, TYPE_OP_RB);
			n_a--;
		}
		else
		{
			operator(stack_a, stack_b, TYPE_OP_RB);
			n_b--;
		}
	while (n_b-- > 0)
		operator(stack_a, stack_b, TYPE_OP_RB);
	while (n_a-- > 0)
	{
		operator(stack_a, stack_b, TYPE_OP_PB);
		operator(stack_a, stack_b, TYPE_OP_RB);
	}
}

void	merge_sort(t_stack *stack_a, t_stack *stack_b)
{	
	int	block_size;
	int	seq_counter;
	int	total_quantity;

	block_size = 1;
	total_quantity = stack_a->quantity;
	merge_first_sequence(stack_a, stack_b);
	printf("at: %d, ab: %d, bt: %d, bb: %d\n", stack_a->top->content, stack_a->bottom->content, stack_b->top->content, stack_b->bottom->content);
	while (stack_b->quantity)
	{
		block_size *= 2;
		seq_counter = total_quantity / (block_size * 2);
		while (--seq_counter >= 0)
		{
			merge_subsidiary(stack_a, stack_b, TYPE_OP_BIAS_A, block_size);
			if (--seq_counter >= 0)
				merge_subsidiary(stack_a, stack_b, TYPE_OP_BIAS_B, block_size);
		}
		if(total_quantity / (block_size * 2) % 2)
			merge_small_seq_b(stack_a, stack_b, stack_a->quantity % (block_size * 2),
			stack_b->quantity % (block_size * 2));
		else
			merge_small_seq_a(stack_a, stack_b, stack_a->quantity % (block_size * 2),
			stack_b->quantity % (block_size * 2));
	}
}

