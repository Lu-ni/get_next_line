#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joinstr;
	char	*startstr;
	int		i;

	if (!s1 || !s2)
		return ((char *)0);
	joinstr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joinstr)
	{
		free((char *) s1);
		return ((char *)0);
	}
	startstr = joinstr;
	i = 0;
	while (s1[i])
		*joinstr++ = s1[i++];
	i = 0;
	while (s2[i])
		*joinstr++ = s2[i++];
	*joinstr = '\0';
	free((char *) s1);
	return (startstr);
}

char	*ft_strchr(const char *str, int c)
{
	char	*strcpy;

	strcpy = (char *)str;
	while (*strcpy)
	{
		if (*strcpy == (char)c)
			return (strcpy);
		strcpy++;
	}
	if ((char)c == '\0')
		return (strcpy);
	return ((char *)0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*startsubstr;

	if (!s)
		return ((char *)0);
	if (start >= ft_strlen(s))
	{
		return ((char *)0);
	}
	if (ft_strlen(&s[start]) >= len)
		substr = (char *)malloc(len + 1);
	else
		substr = (char *)malloc(ft_strlen(&s[start]) + 1);
	if (!substr)
		return ((char *)0);
	startsubstr = substr;
	while (s[start] && (len-- > 0))
		*substr++ = s[start++];
	*substr = '\0';
	return (startsubstr);
}
