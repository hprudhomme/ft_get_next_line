#include "get_next_line.h"

static int  ft_breakline(char **src, char **line)
{
    int len;
    char *tmp;

    len = 0;
    while ((*src)[len] != '\n' && (*src)[len] != '\0')
        len++;
    if ((*src)[len] == '\n')
    {
        *line = ft_substr(*src, 0, len);
        tmp = ft_strdup(&((*src)[len + 1]));
        free(*src);
        *src = tmp;
        if ((*src)[0] == '\0')
			ft_strdel(src);
    }
    else
	{	
		*line = ft_strdup(*src);
		ft_strdel(src);
	}
    printf("line = %s\n", *line);
    printf("src-end = %s\n", *src);
	return (1);
}

static int  ft_verif(char **src, char **line, int ret, int fd)
{
    if (ret < 0)
        return (-1);
    else if (ret == 0 && src[fd] == NULL)
        return (0);
    else
        return (ft_breakline(&src[fd], line));
}

int     get_next_line(int fd, char **line)
{
    int ret;
    static char *src[4096];
    char        buf[BUFFER_SIZE + 1];
    char        *tmp;

    if (fd < 0 || line == NULL)
        return (-1);
    while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
    {   
        printf("ret = %d\n", ret);
        buf[ret] = '\0';
        if (src[fd] == NULL)
            src[fd] = ft_strdup(buf);
        else
        {
            tmp = ft_strjoin(src[fd], buf);
            free(src[fd]);
            src[fd] = tmp;
        }
        if (ft_strchr(src[fd], '\n'))
            break ;
    }
    printf("src = %s\n", src[3]);
    return(ft_verif(src, line, ret, fd));
}

int   main(int ac, char **av)
{
  (void)ac;
  char  *line;
  int   fd1;
//   int   fd2;
//   int   fd3;

int x = 0;

  fd1 = open(av[1], O_RDONLY);
//   fd2 = open(av[2], O_RDONLY);
//   fd3 = open(av[3], O_RDONLY);

while (x < 4)
{
    printf("%d\n", get_next_line(fd1, &line));
    printf(" l = %s\n", line);

    printf("------------------------ ligne %d\n", x + 1);
    x++;
}

//   printf("%d\n", get_next_line(fd1, &line));
//   printf("%s\n", line);

//   printf("---------------------------------------------------------------------------------------------------------------------------------\n");

//   printf("%d\n", get_next_line(fd1, &line));
//   printf("%s\n", line);

//   printf("---------------------------------------------------------------------------------------------------------------------------------\n");

//   printf("%d\n", get_next_line(fd1, &line));
//   printf("%s\n", line);

//   printf("---------------------------------------------------------------------------------------------------------------------------------\n");

//   printf("%d\n", get_next_line(fd1, &line));
//   printf("%s\n", line);
}