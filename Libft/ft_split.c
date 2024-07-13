/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:21:07 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/13 16:31:29 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *str, char sep)
{
	int	count;

	count = 0;
	if (!*str)
		return (count);
	while (*str == sep)
		str++;
	if (*str)
		count = 1;
	while (*str)
	{
		if (*str == sep && *(str + 1) != 0 && *(str + 1) != sep)
			count++;
		str++;
	}
	return (count);
}

static size_t	ft_word_lenght(const char *str, char sep)
{
	size_t	len;

	len = 0;
	while (*str != sep && *str)
	{
		len++;
		str++;
	}
	return (len);
}

static void	*ft_free(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**fak_norminette(const char *s, char c, char **sarr, int words)
{
	int	wlen;
	int	start;
	int	i;

	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] == c)
			(start)++;
		wlen = ft_word_lenght(&s[start], c);
		sarr[i] = ft_substr(s, start, wlen);
		if (!sarr[i])
		{
			ft_free(sarr, i);
			return (NULL);
		}
		start += wlen;
		(i)++;
	}
	sarr[i] = NULL;
	return (sarr);
}

char	**ft_split(const char *s, char c)
{
	char	**sarr;
	int		words;

	words = ft_count_words(s, c);
	sarr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!sarr)
		return (NULL);
	sarr = fak_norminette(s, c, sarr, words);
	if (!sarr)
		return (NULL);
	return (sarr);
}
/*   #include <stdio.h>

int	main(void)
{
	char	str[] = "ola mundo  maluco!  ";
	char	charset;
	char	**result;

	charset = ' ';
	result = ft_split(str, charset);
	ft_printf("string:%s\n", str);
	ft_printf("Split result:\n");
	for (int i = 0; result[i] != NULL; i++)
		ft_printf("%s\n", result[i]);
	ft_free(result, ft_count_words(str, charset) + 1);
	return (0);
}  */
/*
while (i < words)
{
	while (s[start] == c)
		start++;
	wlen = ft_word_lenght(&s[start], c);
	sarr[i] = ft_substr(s, start, wlen);
	if (!sarr[i])
	{
		ft_free(sarr, i);
		return (NULL);
	}
	start += wlen;
	i++;
}
*/