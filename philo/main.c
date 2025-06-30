#include "philosopher.h"

void	calcul_time(void)
{
	struct timeval tv;
	long	time_ms;

	gettimeofday(&tv, NULL);
	time_ms = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	
}
int	main()
{
	calcul_time();
}