#include "Flight.h"
#include <iostream>

using namespace std;

/**
 * @brief Глобальный объект Flight.
 */
Flight flight;

/**
 * @brief Функция для отображения главного меню.
 */
void welcome() {
    while (true) {
        cout << "\nWelcome to Airline Reservation System\n";
        cout << "1. Book Ticket\n2. Cancel Ticket\n3. Change Reservation\n4. Passenger Details\n";
        cout << "5. Get Booking Details\n6. Exit\nYour choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            flight.book_ticket();
            break;
        case 2:
            flight.cancel_ticket();
            break;
        case 3:
            flight.change_reservation();
            break;
        case 4:
            flight.passenger_details();
            break;
        case 5:
            flight.get_booking_details();
            break;
        case 6:
            cout << "Thank you for using the system. Goodbye!\n";
            return;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}

/**
 * @brief Точка входа в программу.
 */
int main() {
    welcome();
    return 0;
}
