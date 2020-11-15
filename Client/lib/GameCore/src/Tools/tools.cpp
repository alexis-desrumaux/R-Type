/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** tools
*/

#include "../../include/Tools/Tools.hpp"

long myclock::getElapsedTime_millisec(std::shared_ptr<myclock_t> clock)
{
    long seconds, millisec, useconds = 0;
    gettimeofday(&clock->end, NULL);
    seconds = clock->end.tv_sec - clock->start.tv_sec; //seconds
    useconds = clock->end.tv_usec - clock->start.tv_usec; //milliseconds
    millisec = ((seconds) * 1000 + useconds/1000.0);
    return millisec;
}

std::shared_ptr<myclock_t> myclock::createClock()
{
    std::shared_ptr<myclock_t> clock = std::make_shared<myclock_t>();
    gettimeofday(&clock->start, NULL);
    return clock;
}

void myclock::resetClock(std::shared_ptr<myclock_t> clock)
{
    gettimeofday(&clock->start, NULL);
}
