/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:40:11 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/08/09 04:53:46 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>

ssize_t read(int fd, void *buf, size_t count);
char *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
size_t     ft_strlen(char *str);
char    *ft_strchr(const char  *s, int c);
char    *ft_read_to_carstock(int fd, char *carstock);
char    *ft_new_carstock(char *carstock);


#endif