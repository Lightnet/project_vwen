/*
	Project: VWEN
*/

#include <stdio.h>
//#include <unistd.h>
#include <chrono>
#include <thread>
//https://stackoverflow.com/questions/4184468/sleep-for-milliseconds

//int main(int, char**) //main entry point
int main_simple(int, char*) //main entry point
{
    //usleep(10000);
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    return 0;
}