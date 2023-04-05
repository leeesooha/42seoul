/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohlee <soohlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:23:26 by soohlee           #+#    #+#             */
/*   Updated: 2023/04/05 14:08:04 by soohlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int path_check(t_config *flag)
{
    int x;
    int y;

    x = flag->start_xy[0];
    y = flag->start_xy[1];
    dfs(x, y, *flag);
    return (0);
}

int dfs(int x, int y, t_config flag)
{
    
    return (0);
}