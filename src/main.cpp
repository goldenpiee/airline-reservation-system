#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <memory>
using namespace std;

const int total_number_of_seats = 100; // Общее количество мест в самолете
vector<int> seats(total_number_of_seats, 0); // Массив статусов мест: 0 - свободно, -1 - занято
/**
 * @brief Класс для управления авиабилетами и бронированиями.
 */
class Flight {
public:
 /**
     * @brief Конструктор по умолчанию.
     */
    Flight() : start(nullptr) {}
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
        string fname; ///< Имя пассажира
        string lname; ///< Фамилия пассажира
        string ID; ///< Идентификационный номер
        string phone_number; ///< Номер телефона
        string food_menu; ///< Выбранное меню
        int seat_number; ///< Номер места
        int reservation_number; ///< Номер бронирования
        unique_ptr<Passenger> next; ///< Указатель на следующего пассажира
    };

    unique_ptr<Passenger> start; ///< Указатель на начало списка пассажиров
    int reserve_seats = 1000; ///< Текущий номер бронирования
    int cancel_tickets = 0; ///< Количество отмененных билетов

     /**
     * @brief Показать доступные места в самолете.
     */
    void display_available_seats();
} flight;

void Flight::display_available_seats() {
    cout << "Available seats:\n";
    for (int i = 0; i < total_number_of_seats; ++i) {
        if (seats[i] == 0) {
            cout << "|" << (i + 1) << "| ";
            if ((i + 1) % 10 == 0) cout << endl;
        }
    }
    cout << endl;
}

void Flight::book_ticket() {
    auto new_passenger = make_unique<Passenger>();
    cout << "Enter your first name: ";
    cin >> new_passenger->fname;
    cout << "Enter your last name: ";
    cin >> new_passenger->lname;
    cout << "Enter your ID: ";
    cin >> new_passenger->ID;
    cout << "Enter your phone number: ";
    cin >> new_passenger->phone_number;

    int seat_number;
    do {
        display_available_seats();
        cout << "Enter the seat number: ";
        cin >> seat_number;
        if (seat_number < 1 || seat_number > total_number_of_seats || seats[seat_number - 1] == -1) {
            cout << "Invalid or taken seat. Please choose another.\n";
        } else {
            seats[seat_number - 1] = -1;
            new_passenger->seat_number = seat_number;
            break;
        }
    } while (true);

    cout << "Choose your food preference:\n";
    cout << "1. Veg\n2. Non-Veg\n3. No Food\nYour choice: ";
    int choice;
    cin >> choice;
    new_passenger->food_menu = (choice == 1) ? "Veg" : (choice == 2) ? "Non-Veg" : "No Food";

    new_passenger->reservation_number = ++reserve_seats;
    cout << "Your reservation number is: " << new_passenger->reservation_number << endl;

    if (!start) {
        start = move(new_passenger);
    } else {
        Passenger* temp = start.get();
        while (temp->next) {
            temp = temp->next.get();
        }
        temp->next = move(new_passenger);
    }
}

void Flight::cancel_ticket() {
    int reservation_number;
    cout << "Enter your reservation number: ";
    cin >> reservation_number;

    Passenger* prev = nullptr;
    Passenger* current = start.get();

    while (current) {
        if (current->reservation_number == reservation_number) {
            if (!prev) {
                start = move(current->next);
            } else {
                prev->next = move(current->next);
            }
            seats[current->seat_number - 1] = 0;
            ++cancel_tickets;
            cout << "Reservation cancelled successfully.\n";
            return;
        }
        prev = current;
        current = current->next.get();
    }

    cout << "Reservation not found.\n";
}

void Flight::change_reservation() {
    int current_seat, new_seat;
    cout << "Enter your current seat number: ";
    cin >> current_seat;

    if (seats[current_seat - 1] != -1) {
        cout << "The seat is not reserved.\n";
        return;
    }

    display_available_seats();
    cout << "Enter your new seat number: ";
    cin >> new_seat;

    if (new_seat < 1 || new_seat > total_number_of_seats || seats[new_seat - 1] == -1) {
        cout << "Invalid or taken seat. Please try again.\n";
        return;
    }

    seats[current_seat - 1] = 0;
    seats[new_seat - 1] = -1;
    cout << "Reservation updated successfully.\n";
}

void Flight::passenger_details() {
    int reservation_number;
    cout << "Enter your reservation number: ";
    cin >> reservation_number;

    Passenger* current = start.get();
    while (current) {
        if (current->reservation_number == reservation_number) {
            cout << "Passenger Details:\n";
            cout << "Name: " << current->fname << " " << current->lname << "\n";
            cout << "ID: " << current->ID << "\n";
            cout << "Phone: " << current->phone_number << "\n";
            cout << "Seat: " << current->seat_number << "\n";
            cout << "Food: " << current->food_menu << "\n";
            return;
        }
        current = current->next.get();
    }
    cout << "Passenger not found.\n";
}

void Flight::get_booking_details() {
    Passenger* current = start.get();
    cout << setw(15) << "Reservation" << setw(15) << "First Name" << setw(15) << "Last Name"
         << setw(10) << "Seat" << setw(15) << "Food" << endl;

    while (current) {
        cout << setw(15) << current->reservation_number
             << setw(15) << current->fname
             << setw(15) << current->lname
             << setw(10) << current->seat_number
             << setw(15) << current->food_menu << endl;
        current = current->next.get();
    }
}

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
 * 
 * @return int Статус выполнения.
 */
int main() {
    welcome();
    return 0;
}
