#include "libft.h"

char          **ft_cpy_double_chartab(char **tab, int base)
{
  char        **newtab;
  int         len;
  int         i;

  i = base;
  len = 0;
  while (tab[i])
  {
      len++;
      i++;
  }
  if(!(newtab = (char **)malloc(sizeof(char *) * len + 1)))
    return (NULL);
  i = 0;
  while (tab[base] != '\0')
  {
    newtab[i] = ft_strdup(tab[base]);
    base++;
    i++;
  }
  newtab[i] = NULL;
  return(newtab);
}
