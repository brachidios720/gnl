/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:35:15 by raphaelcarb       #+#    #+#             */
/*   Updated: 2023/08/09 04:19:25 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

# include <stdio.h>

// tant que pas newline dans carstock alors continue

char    *ft_read_to_carstock(int fd, char *carstock)
{
    char        buf[BUFFER_SIZE + 1];
    ssize_t     res;

    while(ft_strchr(carstock, '\n') == NULL)
    {
        res = read(fd, buf, BUFFER_SIZE);
        if(res == -1)
        {
            free(carstock);
            return(NULL);
        }
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
    i = i + 1;
    while(carstock[i] != '\0')
    {
        newboobies[j++] = carstock[i++];
    }
    // printf("%s %s",carstock,newboobies);
    carstock[k + 1] = '\0';
    return(newboobies);
}

char    *get_next_line(int fd)
{
    static char *carstock;
    char    *line;
    
    if(fd < 0 || BUFFER_SIZE < 0)
        return(0);
    carstock = ft_read_to_carstock(fd, carstock);
    if(!(carstock))
        return(0);
    line = carstock;
    carstock = ft_new_carstock(carstock);
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

//     fd = open("get_next_line.c", O_RDONLY);
//     while((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     return (0);
// }