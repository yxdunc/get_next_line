/* *********************** */
/*                         */
/*  Robin Guignard-Perret  */
/*                   @42   */
/* *********************** */

#include <unistd.h>

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void		ft_putendl(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}
