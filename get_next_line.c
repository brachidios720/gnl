/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:35:15 by raphaelcarb       #+#    #+#             */
/*   Updated: 2023/08/09 05:15:41 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>

// tant que pas newline dans carstock alors continue

char    *ft_read_to_carstock(int fd, char *carstock)
{
    char        *buf;
    ssize_t     res;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while(ft_strchr(carstock, '\n') == NULL)
    {
        res = read(fd, buf, BUFFER_SIZE);
        if(res == -1)
        {
            free(buf);
            free(carstock);
            return(NULL);
        }
        if(res == 0)
        {
            free(buf);
            return(carstock);
        }
        buf[res] = '\0';
        carstock = ft_strjoin(carstock, buf);
        if (carstock == NULL)
        {
            free(buf);
            return (NULL);
        }
    }
    free(buf);
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
    if(carstock[i] == '\0' || carstock[i + 1] == '\0')
        return(NULL);
    while(carstock[j + i] != '\0')
        j++;
    newboobies = malloc(sizeof(char) * (j + 1));
    if(newboobies == NULL)
        return(0);
    j = 0;
    i = i + 1;
    while(carstock[i] != '\0')
    {
        newboobies[j++] = carstock[i++];
    }
    newboobies[j] = '\0';
    // printf("%s %s",carstock,newboobies);
    carstock[k + 1] = '\0';
    return(newboobies);
}

char    *get_next_line(int fd)
{
    static char *carstock;
    char        *line;
    
    if(fd < 0 || BUFFER_SIZE < 0)
        return(0);
    // printf("carstock before before = '%s'", carstock);
    carstock = ft_read_to_carstock(fd, carstock);
    if(!(carstock))
        return(0);
    line = carstock;
    // printf("carstock before = '%s'", carstock);
    carstock = ft_new_carstock(carstock);
    // printf("carstock after = '%s'", carstock);
    return(line);
    // printf("%s %s",carstock,line);
} 

// int	    main(int ac, char **av)
// {
// 	int		fd;
// 	char	*line;

// 	line = NULL;
// 	fd = open(av[1], O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s\n", line);
//         free(line);
// 	}
// 	close(fd);
// }

// #include <stdio.h>
// #include <fcntl.h> // Pour les constantes O_RDONLY, O_WRONLY, O_CREAT, etc.
// #include <unistd.h> // Pour la fonction close()

// int main() {
//     int file_descriptor;
//     char *line = NULL;
//     int read_status;

//     // Ouvrir le fichier en lecture
//     file_descriptor = open("exemple.txt", O_RDONLY);
//     if (file_descriptor == -1) {
//         perror("Erreur lors de l'ouverture du fichier");
//         return 1;
//     }

//     // Lire ligne par ligne et afficher les résultats
//     while ((read_status = get_next_line(file_descriptor)) > 0) {
//         printf("%d\n", read_status);
//         free(read_status);
//     }

//     // Gérer les erreurs ou la fin du fichier
//     if (read_status == -1) {
//         perror("Erreur lors de la lecture du fichier");
//     } else if (read_status == 0) {
//         printf("Fin du fichier atteinte.\n");
//     }

//     // Fermer le fichier et libérer la mémoire
//     close(file_descriptor);
//     free(line);

//     return 0;
// }

// #include <fcntl.h>


// int main(void)
// {
//     char    *line;
//     int fd;

//     fd = open("test.txt", O_RDONLY);
//     while((line = get_next_line(fd)))
//     {
//         printf("=%s", line);
//         free(line);
//     }
//     return (0);
// }