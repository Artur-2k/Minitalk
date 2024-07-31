/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:16:03 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/31 13:17:01 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "minitalk.h"

unsigned char	*append_char_to_str(unsigned char *str, char c)
{
	unsigned char	*nstr;
	int				i;

	i = 0;
	while (str && str[i++])
		i++;
	nstr = (unsigned char *)malloc(sizeof(char) * i + 2);
	if (!nstr)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = c;
	nstr[++i] = 0;
	return (nstr);
}

void	bit_to_char(int bit)
{
	static unsigned char	*message;
	static unsigned char	c;
	static int				idx_bit;

	if (bit == 1)
		c = (c << 1) | 1;
	else
		c <<= 1;
	if (idx_bit < 7)
		idx_bit++;
	else
	{
		message = append_char_to_str(message, c);
		if (c == 0)
		{
			ft_printf("Client said: %s\n", message);
			free(message);
			message = NULL;
		}
		idx_bit = 0;
	}
}

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
		bit_to_char(1);
	else
		bit_to_char(0);
}

void	print_mickey(void)
{
	ft_printf("\e[0;31m             .-\"\"\"-.\n");
	ft_printf("            /       \\\n");
	ft_printf("            \\       /\n");
	ft_printf("     .-\"\"\"-.-`.-.-.<  _\n");
	ft_printf("    /      _,-\\ O_O-_/ )  ~champagne, monsieur?\n");
	ft_printf("    \\     / ,  `   . `|\n");
	ft_printf("     '-..-| \\-.,__~ ~ /          .,\n");
	ft_printf("           \\ `-.__/  /          /\"/\n");
	ft_printf("          / `-.__.-\\`-._    ,\",' ;\n");
	ft_printf("         / /|    ___\\-._`-.; /  ./-.  \n");
	ft_printf("        ( ( |.-\"`   `\' '-( /  //.-' \n");
	ft_printf("         \\ \\/    {}{}  |   /-. /.-'\n");
	ft_printf("          \\|           /   '..' \n");
	ft_printf("           \\        , /\n");
	ft_printf("           ( __`;-;'__`)\n");
	ft_printf("           `//'`   `||`\n");
	ft_printf("   +/-    _//       ||\n");
	ft_printf("  .-\"-._,(__)     .(__).-\"\"-.\n");
	ft_printf(" /          \\    /           \\\n");
	ft_printf(" \\          /    \\           /\n");
	ft_printf("  `'-------`      `--------'`\n\e[0m");
}

int	main(void)
{
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_handler = &signal_handler;
	sa1.sa_flags = SA_RESTART;
	sigemptyset(&sa1.sa_mask);
	sa2.sa_handler = &signal_handler;
	sa2.sa_flags = SA_RESTART;
	sigemptyset(&sa2.sa_mask);
	print_mickey();
	ft_printf("\n The server's process id is: %d\n", getpid());
	ft_printf("\nPress ctrl + z to close the server.\n");
	ft_printf("\nWaiting for something to happen...\n");
	sigaction(SIGUSR1, &sa1, NULL);
	sigaction(SIGUSR2, &sa2, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
