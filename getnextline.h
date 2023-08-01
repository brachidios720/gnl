/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnextline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:40:11 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/07/30 14:32:07 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#include<stdlib.h>
#include<unistd.h>

ssize_t read(int fd, void *buf, size_t count);
char *get_next_line(int fd);
char    *strjoin(const char *s1, const char *s2);
size_t     strlen(char *str);
char    *strchr(const char  *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif