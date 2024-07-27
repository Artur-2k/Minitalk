#define _POSIX_C_SOURCE 200809L
#include "minitalk.h"

void	bit_to_char(int bit)
{
	static unsigned char	c;
	static int				idx_bit;
	static int				first_call = 1;

	if (first_call == 1)
	{
		first_call = 0;
		ft_printf("Client said: ");
	}
	if (bit == 1)
		c = (c << 1) | 1;
	else
		c <<= 1;
	if (idx_bit < 7)
		idx_bit++;
	else
	{
		if (c != 0)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		if (c == 0)
			first_call = 1;
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
