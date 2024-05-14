/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:20:12 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/14 19:55:27 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countword(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_len;
	int		i;

	result = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			result[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	result[i] = NULL;
	return (result);
}
/*int main(void)
{
    char **result;

    // Teste com uma string simples
    printf("Teste 1:\n");
    result = ft_split("Isabella neves", ' ');
    if (result)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
    {
        printf("Erro: a função ft_split retornou NULL\n");
    }

    // Teste com uma string contendo múltiplos espaços
    printf("\nTeste 2:\n");
    result = ft_split("   isabella   neves   ", ' ');
    if (result)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
    {
        printf("Erro: a função ft_split retornou NULL\n");
    }

    // Teste com uma string vazia
    printf("\nTeste 3:\n");
    result = ft_split("", ' ');
    if (result)
    {
        printf("Aqui deveria estar vazio: %s\n", *result);
        free(result[0]);
        free(result);
    }
    else
    {
        printf("Erro: a função ft_split retornou NULL\n");
    }

    return 0;
    // cc ft_split.c ft_strlcpy.c ft_strlen.c ft_strchr.c ft_substr.c ft_strdup.c
}*/