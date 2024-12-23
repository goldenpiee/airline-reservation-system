#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>
#include <memory>

extern const int total_number_of_seats; // We declare this as extern here

// Declare seats as extern as well, so it's visible across files
extern std::vector<int> seats;

/**
 * @brief Класс для управления авиабилетами и бронированиями.
 */
class Flight {
public:
    /**
     * @brief Забронировать билет.
     */
    void book_ticket();

    /**
     * @brief Отменить бронирование билета.
     */
    void cancel_ticket();

    /**
     * @brief Изменить место в бронировании.
     */
    void change_reservation();

    /**
     * @brief Показать детали пассажира.
     */
    void passenger_details();

    /**
     * @brief Показать все бронирования.
     */
    void get_booking_details();

private:
    /**
     * @brief Структура для хранения информации о пассажире.
     */
    struct Passenger {
        std::string fname;       ///< Имя пассажира
        std::string lname;       ///< Фамилия пассажира
        std::string ID;          ///< Идентификационный номер
        std::string phone_number;///< Номер телефона
        std::string food_menu;   ///< Выбранное меню
        int seat_number;         ///< Номер места
        int reservation_number;  ///< Номер бронирования
        std::unique_ptr<Passenger> next; ///< Указатель на следующего пассажира
    };

    std::unique_ptr<Passenger> start; ///< Указатель на начало списка пассажиров
    int reserve_seats = 1000;         ///< Текущий номер бронирования
    int cancel_tickets = 0;           ///< Количество отмененных билетов

    /**
     * @brief Показать доступные места в самолете.
     */
    static void display_available_seats();
};

#endif // FLIGHT_H
