cmake_minimum_required(VERSION 3.25)
project(ArrayFillerProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(ArrayFillerProject main.cpp controllers/BaseController.h time/stopwatch.h client/ArrayClient.h generators/number_generator.h collections/impl/sequential/array_factory_sequential_impl.h collections/abstract_array_factory.h generators/generator.h collections/impl/decorators/array_factory_benchmark_decorator.h controllers/impl/BaseControllerImpl.h generators/random/mersenne_twister_number_generator.h generators/number_generator_factory.h generators/random/mersenne_twister_number_generator_factory.h collections/impl/parallel/array_factory_parallel_impl.h)
