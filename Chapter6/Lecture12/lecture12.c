#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
		Simulation of a Moving Object
		- Speed = 1.0 m/s
		- dt = 1.0 s
		- Distance traveled during dt = Speed * dt
		
		- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m
		- Step 2 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m + 1.0 m = 2.0 m
		- Step 3 : 1.0 m/s * 1.0 s = 1.0 m, dist = 2.0 m + 1.0 m = 3.0 m
		- ... ...
	*/
	// const double speed = 1.0;
	// const unsigned repeat_max = 10;

	// double dt = 1.0;
	// double time = 0.0, distance = 0.0;  // Elapsed time & distance
	// for(unsigned i = 0; i < repeat_max; ++i)
	// {
	// 	distance += speed * dt;
	// 	time += dt;
	// 	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, distance);
	// }
	
	/*
		Zeno's Paradox
		- Step 1 : 1.0 * 1.0 = 1.0, 1.0
		- Step 2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
		- Step 3 : 1.0 * 0.25 = 0.25, 1.5 + 0.25 = 1.75	
		... ... 
	*/
	const double speed = 1.0;
	const unsigned repeat_max = 10;

	double dt = 1.0;
	double time = 0.0, distance = 0.0;  // Elapsed time & distance
	for(unsigned i = 0; i < repeat_max; ++i)
	{
		distance += speed * dt
		time += dt;
		printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, distance);
		dt = dt / 2.0;  // 2가 promotion으로 doulbe형태가 됩니다.
		// dt = dt * 0.5;  곱하기가 나누기 보다 빠르기 때문에 이렇게 쓰는게 더 일반적입니다.
	}

	//Note: infinite geometric series

	const double speed = 1.0;
	const unsigned repeat_max = 10;

	double dt = 1.0;
	double time = 0.0
	double distance_arch = 0.0;
	double distance_turtle = 0.0;   // Elapsed time & distance
	double speed_arch = 10.0;
	double speed_turtle = 0.001;

	for(unsigned i = 0; i < repeat_max; ++i)
	{
		distance_arch += speed_arch * dt;
		distance_turtle += speed_turtle * dt;
		time += dt;
		printf("Time = %fs, Arch = %fm, Turtle = %fm\n", time, distance_arch, distance_turtle);
		dt = dt * 0.5;
	}



	return 0;
}
