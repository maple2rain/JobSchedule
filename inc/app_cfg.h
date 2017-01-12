#ifndef APP_CFG_H
#define APP_CFG_H

#include <iostream>

typedef unsigned int us16;

/* debug print define */
#define DEBUG_ON 0
#if DEBUG_ON
    #define DEBUG_PRINT_JOB(jobs, type) \
    do{ \
        std::cout << "join time is: ";\
        for(auto it = scheduler->jobs.begin(); it != scheduler->jobs.end(); ++it)\
            std::cout << (*it)->get##type() << " ";\
        std::cout << std::endl;  \
    }while(0)
#else
    #define DEBUG_PRINT_JOB(jobs, type) do{}while(0)
#endif

template <typename ... T>
void DummyWrapper(T... t){}

template <class T>
T unpacker(const T& t){
    std::cout << ' ' << t;
    return t;
}

#if DEBUG_ON
template <typename T, typename... Args>
void DEBUG_PRINT(const T& t, const Args... data) {
    std::cout << t;
    DummyWrapper(unpacker(data)...);// unpack Args to
    std::cout << std::endl;
}
#else
template <typename T, typename... Args>
void DEBUG_PRINT(const T& t, const Args... data) {
}
#endif

#endif // APP_CFG_H
