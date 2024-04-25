#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_timestamp
{
	struct timeval	start;
	struct timeval	end;
	long			ms;
} t_timestamp;

int	main(void)
{
	t_timestamp *time;

	time = malloc(sizeof(t_timestamp));
	gettimeofday(&time->start, NULL);
	printf("formato padrao segundo: %ld\n", time->start.tv_sec);
	printf("formato padrao microsegundo: %ld\n", time->start.tv_usec);
	printf("-------------------------\n");
	usleep(2777);
	gettimeofday(&time->end, NULL);
	printf("tempo de espera em segundos: %ld\n", time->end.tv_sec - time->start.tv_sec);
	printf("tempo de espera em microssegundos: %ld\n", time->end.tv_usec - time->start.tv_usec);
	time->ms = (time->end.tv_sec - time->start.tv_sec)*1000 + (time->end.tv_usec - time->start.tv_usec)/1000;
	printf("tempo de espera em milissegundos: %.6fms\n", time->ms/1000.0);
	return (0);
}