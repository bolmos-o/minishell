#include "minishell.h"


void	inthandler(int sig)
{
	(void)sig;
	write(1, "\nminishell$ ", 12);
}

void	inthandler2(int sig)
{
	extern int signum;

	//(void)sig;
	signum = sig;
	//signal(sig, SIG_DFL);
	signal(SIGINT, inthandler);
	write(1,"\n",1);
}
