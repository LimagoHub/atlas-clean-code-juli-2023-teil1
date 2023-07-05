#include <iostream>


#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <vector>

std::vector<std::thread> myThreads;
auto thread_function(std::string message)-> void
{
    int value = rand() % 1000;
    std::this_thread::sleep_for(std::chrono::milliseconds(value));
    std::cout << message << std::endl;
}

auto foo() -> void {

    for (int i = 0; i < 5; ++i) {
        myThreads.emplace_back(std::thread{&thread_function, "Hallo " + std::to_string(i)});
    }



    std::cout << "Fertig\n";
}

auto main() -> int
{
    foo();
    for ( auto &myThread: myThreads) {
        myThread.join();
    }
    return 0;
}


