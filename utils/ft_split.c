/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamendes <mamendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 14:13:34 by mamendes          #+#    #+#             */
/*   Updated: 2026/06/08 14:13:46 by mamendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	k;
	int	count_words;

	count_words = 0;
	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c && k == 0)
		{
			k = 1;
			count_words++;
		}
		if (s[i] == c)
			k = 0;
		i++;
	}
	return (count_words);
}

static char	*get_word(char const *s, char c, int start)
{
	int		i;
	int		end;
	char	*word;

	i = 0;
	end = start;
	while (s[end] != c && s[end])
		end++;
	word = malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	*full_free(char **s, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	fill_words(char **result, char const *s, char c, int words)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && j < words)
	{
		if (s[i] != c)
		{
			result[j] = get_word(s, c, i);
			if (result[j] == NULL)
				return (full_free(result, j), 0);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	result = ft_calloc(words + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (!fill_words(result, s, c, words))
		return (NULL);
	return (result);
}
