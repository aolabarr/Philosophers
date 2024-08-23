
#include "../philo.h"

void	final_info(t_data *data)
{
	int i = -1;

	printf("\nINFO\n");
	while(++i < data->nbr_philos)
		printf("philo %d meals: %d\n", data->philos[i].id, data->philos[i].meals);
	printf("full, die: (%d, %d)\n", data->full, data->die);

}

void	philo_info(t_philo *philo)
{
	printf("\nmeals-full-die: philo %d (%d, %d, %d)\n", philo->id, philo->meals, philo->full, philo->die);
}
