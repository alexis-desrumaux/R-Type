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
#include <memory>

struct myclock_t
{
    struct timeval start;
    struct timeval end;
};

namespace myclock
{
    std::shared_ptr<myclock_t> createClock();
    void resetClock(std::shared_ptr<myclock_t>);
    long getElapsedTime_millisec(std::shared_ptr<myclock_t> clock);
}

#endif /* !TOOLS_HPP_ */
