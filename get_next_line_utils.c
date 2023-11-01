#include <stdlib.h>

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	char *destcpy;
	char *srccpy;

	destcpy = (char *) dst;
	srccpy = (char *) src;
	if (!dst && !src)
		return (dst);
	while (n > 0)
	{
		*destcpy++ = *srccpy++;
		n--;
	}
	return (dst);
}

char *ft_strjoin(char *s1, char *s2, char *starts1)
{
	char *joinstr;
	char *startstr;
	int   i;

	if (!s1 || !s2)
		return ((char *) 0);
	joinstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joinstr)
		return ((char *) 0);
	startstr = joinstr;
	i = 0;
	while (s1[i])
		*joinstr++ = s1[i++];
	i = 0;
	while (s2[i])
		*joinstr++ = s2[i++];
	*joinstr = '\0';
	free(starts1);
	free(s2);
	return (startstr);
}
