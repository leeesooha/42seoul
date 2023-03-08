/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:04:51 by soohlee           #+#    #+#             */
/*   Updated: 2023/03/08 16:11:50 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **a_stack, t_list **b_stack);
{
	if (ft_lstsize(*a_stack) >= 3)
		return (hard_coding(*a_stack));
	return (0);
}
