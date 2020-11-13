/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** tools
*/

#include "../../include/Tools/Tools.hpp"

long  myclock::getElapsedTime_millisec(myclock_t *clock)
{
    long seconds, millisec, useconds = 0;
    gettimeofday(&clock->end, NULL);
    seconds = clock->end.tv_sec - clock->start.tv_sec; //seconds
    useconds = clock->end.tv_usec - clock->start.tv_usec; //milliseconds
    millisec = ((seconds) * 1000 + useconds/1000.0);
    return millisec;
}

myclock_t *myclock::createClock()
{
    myclock_t *clock = new myclock_t;
    gettimeofday(&clock->start, NULL);
    return clock;
}

void myclock::resetClock(myclock_t *clock)
{
    gettimeofday(&clock->start, NULL);
}
