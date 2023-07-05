#include <iostream>
#include <climits>
#include <cstdlib>
#include <chrono>
#include <memory>

// 1 bis availableProcessors + 1


#define MAX_ARRAY_SIZE (INT32_MAX/8)
using namespace std::chrono;
class Demo {

    std::shared_ptr<int[]> data;
public:

    explicit Demo() : data(std::shared_ptr<int[]>(new int[MAX_ARRAY_SIZE])) {}
    virtual ~Demo() = default;

    auto run()->void {
        auto start = high_resolution_clock::now();
        for (int i = 0; i < MAX_ARRAY_SIZE; ++i) {
            data[i] = rand();
        }
        auto ende = high_resolution_clock::now();
        std::cout << std::endl << "Zeit: " << duration_cast<milliseconds>(ende-start).count() << " ms";
    }
};


auto main() -> int{

    Demo demo;
    demo.run();
    return 0;
}
