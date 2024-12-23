cmake_minimum_required(VERSION 3.10)
project(AirlineReservationSystem)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исходный код
add_executable(airline_reservation src/main.cpp)

# Включаем тестирование
enable_testing()

# Добавляем тесты
add_executable(test_booking tests/test_booking.cpp)
target_link_libraries(test_booking PRIVATE airline_reservation)

add_test(NAME TestBooking COMMAND test_booking)
