/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:35:15 by raphaelcarb       #+#    #+#             */
/*   Updated: 2023/08/01 19:52:37 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

ssize_t read(int fd, void *buf, size_t count)
{
        
}

char    *ft_read_to_carstock(int fd, char *carstock)
{
    char        buf[BUFFER_SIZE + 1];
    ssize_t     res;

    while(ft_strchr(carstock, '\n'))
    {
        res = read(fd, buf, BUFFER_SIZE);
        if(res == -1)
            return(NULL);
        if(res == 0)
            return(carstock);
        buf[res] = '\0';
        carstock = ft_strjoin(carstock, buf);
        if (carstock == NULL)
            return (NULL);
    }
    return(carstock);
}

char    *ft_new_carstock(char *carstock)
{
    char    *newboobies;
    int     i;
    int     j;
    int     k;
    
    i = 0; 
    j = 0;
    while(carstock[i] != '\n' && carstock[i] != '\0')
        i++;
    k = i;
    if(carstock[i] == '\0')
        return(0);       
    while(carstock[j + i] != '\0')
        j++;
    newboobies = malloc(sizeof(char) * (j + 1));
    if(newboobies == NULL)
        return(0);
    j = 0;
    while(carstock[i] != '\0')
        newboobies[j++] = carstock[i++];
    carstock[k + 1] = '\0';
    return(newboobies);
}

char *get_next_line(int fd)
{
    static char *carstock;
    char    *new;
    
    if(fd > 0 || BUFFER_SIZE >= 0 || read(fd, 0, 0) > fd)
        return(0);
    carstock = *ft_read_to_carstock(fd, carstock);
    if(!(carstock))
        return(0);
    new = *ft_new_carstock(carstock);
    return(new);
}


