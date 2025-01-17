/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 12:56:58 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/16 18:12:31 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	select_b(t_list **a_stack, t_list **b_stack, int *best_case, int *hash)
{
	int		best_num;
	int		cur_num;
	t_list	*temtack;
	int		i;

	i = 0;
	temtack = (*b_stack);
	best_num = *((int *)(*b_stack)->content);
	hash[best_num] = path_cnt(a_stack, b_stack, best_num, best_case);
	while (++i < 6)
		best_case[i + 5] = best_case[i];
	while (*b_stack && (temtack))
	{
		cur_num = *((int *)temtack->content);
		hash[cur_num] = path_cnt(a_stack, b_stack, cur_num, best_case);
		if (hash[best_num] > hash[cur_num] && best_num != cur_num)
		{
			i = 0;
			while (++i < 6)
				best_case[i + 5] = best_case[i];
			best_num = cur_num;
		}
		temtack = temtack->next;
	}
	return (best_num);
}

int	move_pa(int *bst_cse, t_list **a_stack, t_list **b_stack, t_list **cmd)
{
	if (bst_cse[6] == 0)
	{
		return (pa_zero(bst_cse, a_stack, b_stack, cmd));
	}
	else if (bst_cse[6] == 1)
		return (pa_one(bst_cse, a_stack, b_stack, cmd));
	else if (bst_cse[6] == 2)
		return (pa_two(bst_cse, a_stack, b_stack, cmd));
	else if (bst_cse[6] == 3)
		return (pa_thre(bst_cse, a_stack, b_stack, cmd));
	return (0);
}

int	zero_to_top(t_list **a_stack, t_list **cmd, int len)
{
	t_list	*temtack;
	int		zero_index;

	zero_index = 0;
	temtack = *a_stack;
	while (*((int *)temtack->content) != 0)
	{
		zero_index++;
		temtack = temtack->next;
	}
	if (zero_index > len / 2)
	{
		while (*((int *)((*a_stack)->content)) != 0)
			ft_lstadd_back(cmd, ft_lstnew(ft_strdup(rra(a_stack))));
	}
	else
	{
		while (*((int *)((*a_stack)->content)) != 0)
			ft_lstadd_back(cmd, ft_lstnew(ft_strdup(ra(a_stack))));
	}
	return (0);
}
