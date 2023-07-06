cmake_minimum_required(VERSION 3.25)
project(ArrayFillerProject)

set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(OUTPUT_DIR ${CMAKE_SOURCE_DIR}/build/${PLATFORM_ARCHITECTURE}/$<CONFIG>)
set(PROJ_CONFIG $<CONFIG>)

enable_testing()
add_executable(ArrayFillerProject main.cpp controllers/BaseController.h time/stopwatch.h client/ArrayClient.h generators/number_generator.h collections/impl/sequential/array_factory_sequential_impl.h collections/abstract_array_factory.h generators/generator.h collections/impl/decorators/array_factory_benchmark_decorator.h controllers/impl/BaseControllerImpl.h generators/random/mersenne_twister_number_generator.h generators/number_generator_factory.h generators/random/mersenne_twister_number_generator_factory.h  generators/generator_factory.h collections/impl/parallel/array_factory_parallel_impl.h collections/impl/parallel/array_factory_auto_impl.h collections/impl/decorators/array_factory_logging_decorator.h collections/impl/decorators/array_factory_security_decorator.h tests/collections/my_dummy_for_abstract_array_factory.h generators/impl/GenericGenerator.h Caclulator.h CalculatorExtension.h)

# Add tests
add_subdirectory(tests)