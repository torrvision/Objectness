#pragma once
#include <sys/time.h>
class CmTimer
{
public:	
    CmTimer(CStr t):title(t) { is_started = false; gettimeofday(&start_clock,NULL); gettimeofday(&end_clock,NULL); n_starts = 0; }

	~CmTimer(){	if (is_started) printf("CmTimer '%s' is started and is being destroyed.\n", title.c_str());	}

	inline void Start();
	inline void Stop();
	inline void Reset();

	inline bool Report();
	inline bool StopAndReport() { Stop(); return Report(); }
	inline float TimeInSeconds();

private:
	CStr title;
	
	bool is_started;
    struct timeval start_clock, end_clock;
    //clock_t start_clock;
    //clock_t cumulative_clock;
	unsigned int n_starts;
};

/************************************************************************/
/*                       Implementations                                */
/************************************************************************/

void CmTimer::Start()
{
	if (is_started){
		printf("CmTimer '%s' is already started. Nothing done.\n", title.c_str());
		return;
	}

	is_started = true;
	n_starts++;
    //start_clock = clock();
    gettimeofday(&start_clock,NULL);
}

void CmTimer::Stop()
{
	if (!is_started){
		printf("CmTimer '%s' is started. Nothing done\n", title.c_str());
		return;
	}
    gettimeofday(&end_clock,NULL);
    //cumulative_clock += clock() - start_clock;
	is_started = false;
}

void CmTimer::Reset()
{
	if (is_started)	{
		printf("CmTimer '%s'is started during reset request.\n Only reset cumulative time.\n");
		return;
	}
    gettimeofday(&start_clock,NULL);
    gettimeofday(&end_clock,NULL);
    //cumulative_clock = 0;
}

bool CmTimer::Report()
{
	if (is_started){
		printf("CmTimer '%s' is started.\n Cannot provide a time report.", title.c_str());
		return false;
	}

	float timeUsed = TimeInSeconds();
	printf("[%s] CumuTime: %gs, #run: %d, AvgTime: %gs\n", title.c_str(), timeUsed, n_starts, timeUsed/n_starts);
	return true;
}

float CmTimer::TimeInSeconds()
{
	if (is_started){
		printf("CmTimer '%s' is started. Nothing done\n", title.c_str());
		return 0;
	}
    return  double((end_clock.tv_sec  - start_clock.tv_sec) * 1000000u +
             end_clock.tv_usec - start_clock.tv_usec) / 1.e6;
    //return float(cumulative_clock) / CLOCKS_PER_SEC;
}

