#include "get_next_line.h"

size_t     ft_strlen(char *str)
{
    size_t i;

    i = 0;
    if (str == NULL)
        return (0);
    while(str[i])
    {
        i++;
    }
    return(i);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int i;
    int j;
    char    *p;

    i = 0;
    j = 0;
    p = malloc(sizeof (char *) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if(p == NULL)
    {
        free(s1);
        return(0);
    }
    while((s1 != NULL) && s1[i])
    {
        p[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        p[i] = s2[j];
        j++;
        i++;
    }
    free(s1);
    p[i] = '\0';
    return(p);
}

char    *ft_strchr(const char  *s, int c)
{
    size_t     i;

    if (s == NULL)
        return (NULL);
    i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == c)
            return((char*)s + i);
        i++;
    }
    return(NULL);
}