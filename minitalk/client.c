#include "minitalk.h"

void	send_data(char c, int pid)
{
	int	a;
	int	f;

	a = 128;
	f = 0;
	(void)pid;
	while (a > 0)
	{
		if ((c & a) == a)
			a = kill(pid, SIGUSR1);
		else
			f = kill(pid, SIGUSR2);
		a = a / 2;
		usleep(150);
	}
	ft_error("", f);
}

int	main(int argc, char **argv)
{
	int	a;
	int	i;

	i = 0;
	if (argc == 3)
	{
		a = ft_atoi(argv[1]);
		while (argv[2][i])
			send_data(argv[2][i++], a);
		send_data('\0', a);
	}
	else
		write(1, "Error : Format ./client <server_pid> <message>\n", 48);
}
