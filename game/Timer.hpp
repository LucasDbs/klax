/*
** EPITECH PROJECT, 2019
** Lucas Duboisse
** File description:
** Timer.hpp
*/

#if !defined(TIMER_HPP_)
#define TIMER_HPP_

#include <thread>

class Timer
{
        private:
                bool _active;

        public:
                Timer();
                ~Timer();

                template<class Obj, class Function>
                void setInterval(Obj obj, Function function, int interval);
};

template<class Obj, class Function>
void Timer::setInterval(Obj obj, Function function, int interval)
{
        _active = true;
        std::thread t([=] () {
                while (true) {
                        if (!_active)
                                return;
                        std::this_thread::sleep_for(std::chrono::milliseconds(interval));
                        if (!_active)
                                return;
                        if (!(obj->*function)())
                                return;
                }
        });
        t.detach();
}

#endif // TIMER_HPP_
