/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:40:14 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/07/22 17:40:23 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void   ft_putstr(char *c)
{
    size_t     i;

    i = 0;
    while(c[i])
    {
        ft_putchar(c[i]);
        i++;
    }
}

