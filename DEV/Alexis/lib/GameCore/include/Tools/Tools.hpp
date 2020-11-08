/*
** EPITECH PROJECT, 2020
** Perso
** File description:
** Tools
*/

#ifndef TOOLS_HPP_
#define TOOLS_HPP_

#include <sys/time.h>
#include <iostream>

struct myclock_t
{
    struct timeval start;
    struct timeval end;
};

namespace myclock
{
    myclock_t *createClock();
    void resetClock(myclock_t *);
    long getElapsedTime_millisec(myclock_t *clock);
}

#endif /* !TOOLS_HPP_ */
