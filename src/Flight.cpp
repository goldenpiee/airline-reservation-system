#include "Flight.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Define the global variables declared as extern in Flight.h
const int total_number_of_seats = 100; 
std::vector<int> seats(total_number_of_seats, 0);

// Display available seats
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

// Book a ticket
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

    cout << "Choose your food preference:\n1. Veg\n2. Non-Veg\n3. No Food\nYour choice: ";
    int choice;
    cin >> choice;
    new_passenger->food_menu = (choice == 1) ? "Veg" : (choice == 2) ? "Non-Veg" : "No Food";

    new_passenger->reservation_number = ++reserve_seats;
    cout << "Your reservation number is: " << new_passenger->reservation_number << endl;

    if (!start) {
        start = std::move(new_passenger);
    } else {
        Passenger* temp = start.get();
        while (temp->next) {
            temp = temp->next.get();
        }
        temp->next = std::move(new_passenger);
    }
}

// Cancel a ticket
void Flight::cancel_ticket() {
    int reservation_number;
    cout << "Enter your reservation number: ";
    cin >> reservation_number;

    Passenger* prev = nullptr;
    Passenger* current = start.get();

    while (current) {
        if (current->reservation_number == reservation_number) {
            if (!prev) {
                // If passenger to remove is the first node
                start = std::move(current->next);
            } else {
                // Otherwise skip the passenger in the list
                prev->next = std::move(current->next);
            }
            // Mark seat as free
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

// Change reservation (seat)
void Flight::change_reservation() {
    int current_seat, new_seat;
    cout << "Enter your current seat number: ";
    cin >> current_seat;

    // Check if current seat is valid and actually taken
    if (current_seat < 1 || current_seat > total_number_of_seats || seats[current_seat - 1] != -1) {
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

    // Free the old seat and reserve the new one
    seats[current_seat - 1] = 0;
    seats[new_seat - 1] = -1;
    cout << "Reservation updated successfully.\n";
}

// Show passenger details for a given reservation number
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

// Show all booking details
void Flight::get_booking_details() {
    if (!start) {
        cout << "No passengers found.\n";
        return;
    }

    Passenger* current = start.get();
    cout << setw(15) << "Reservation"
         << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(10) << "Seat"
         << setw(15) << "Food"
         << endl;

    while (current) {
        cout << setw(15) << current->reservation_number
             << setw(15) << current->fname
             << setw(15) << current->lname
             << setw(10) << current->seat_number
             << setw(15) << current->food_menu 
             << endl;
        current = current->next.get();
    }
}
