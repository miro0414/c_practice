#include<stdio.h>
#include <sys/timerfd.h>//only for Linux
#include <time.h>
#include <stdlib.h>
struct periodic_info
{
	int timer_fd;
	unsigned int interval; /* millisecond */
	unsigned long long wakeups_missed;
};

int make_periodic (unsigned int period, struct periodic_info *info)
{
	int ret;
	unsigned int ns;
	unsigned int sec;
	int fd;
	struct itimerspec itval;

	/* Create the timer */
	fd = timerfd_create (CLOCK_MONOTONIC, 0);
	info->wakeups_missed = 0;
	info->interval = period / 1000;
	info->timer_fd = fd;
	if (fd == -1)
		return fd;

	/* Make the timer periodic */
	sec = period/1000000;
	ns = (period - (sec * 1000000)) * 1000;
	itval.it_interval.tv_sec = sec;
	itval.it_interval.tv_nsec = ns;
	itval.it_value.tv_sec = sec;
	itval.it_value.tv_nsec = ns;
	ret = timerfd_settime (fd, 0, &itval, NULL);
	return ret;
}

int modify_periodic(unsigned int period, struct periodic_info *info)
{
	unsigned int ns;
	unsigned int sec;
	struct itimerspec nitval = {{0}};

	info->interval = period / 1000; // 1

	sec = period/1000000; // 1/1000 = 1ms
	ns = (period - (sec * 1000000)) * 1000; // 0
	nitval.it_interval.tv_sec = sec;
	nitval.it_interval.tv_nsec = ns;
	nitval.it_value.tv_sec = sec;
	nitval.it_value.tv_nsec = ns;

	return timerfd_settime (info->timer_fd, 0, &nitval, NULL);
}

void wakeup_period(unsigned int period, struct periodic_info *info)
{
	modify_periodic(1000, info); 
	usleep(1100);
	modify_periodic(period, info);
}


int main(){
	unsigned int i,x;
	int period = 1000000;
	struct periodic_info timer;

	make_periodic(period,&timer);
	printf("wake up");
	wakeup_period(period,&timer);

	return 0;
}
