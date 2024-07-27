#include "minitalk.h"

void	dynamic_sleep(int size)
{
	if (size < 100)
		usleep(50);
	else if (size < 200)
		usleep(100);
	else if (size < 400)
		usleep(200);
	else if (size < 600)
		usleep(400);
	else if (size < 800)
		usleep(400);
	else if (size < 1000)
		usleep(800);
	else
		usleep(1600);
}

void	send_bit(int bit, __pid_t server_pid	)
{
	if (bit == 1)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	send_message(const char *message, __pid_t server_pid)
{
	int	size;
	int	idx_byte;
	int	idx_bit;
	int	bit;

	size = 0;
	while (message[size])
		size++;
	idx_byte = 0;
	while (idx_byte <= size)
	{
		idx_bit = 7;
		while (idx_bit >= 0)
		{
			bit = (message[idx_byte] >> idx_bit) & 1;
			send_bit(bit, server_pid);
			dynamic_sleep(size);
			idx_bit--;
		}
		idx_byte++;
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || !av[1] || !av[1][0])
	{
		ft_printf("Correct usage: ./client <PID> <MESSAGE>\n");
		exit(EXIT_FAILURE);
	}
	send_message(av[2], ft_atoi(av[1]));
	return (EXIT_SUCCESS);
}
