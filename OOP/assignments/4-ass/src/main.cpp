#include <iostream>

#include "../include/Hotel.h"

using namespace std;

// Define macros for menu options
#define OPTION_ADD_CUSTOMER 1
#define OPTION_DISPLAY_CUSTOMERS 2
#define OPTION_SEARCH_CUSTOMER 3
#define OPTION_DELETE_CUSTOMER 4
#define OPTION_DISPLAY_ROOM_TYPE 5
#define OPTION_CALCULATE_RENTAL_FEE 6
#define OPTION_EXIT 7

int main() {
  Hotel hotel;

  while (true) {
    cout << "--------------------------------\n";
    cout << OPTION_ADD_CUSTOMER << ". Add customer\n";
    cout << OPTION_DISPLAY_CUSTOMERS << ". Display customers\n";
    cout << OPTION_SEARCH_CUSTOMER << ". Search customer by ID\n";
    cout << OPTION_DELETE_CUSTOMER << ". Delete customer by ID\n";
    cout << OPTION_DISPLAY_ROOM_TYPE << ". Display room type\n";
    cout << OPTION_CALCULATE_RENTAL_FEE
         << ". Calculate rental fee by customer ID\n";
    cout << OPTION_EXIT << ". Exit\n";
    cout << "--------------------------------\n";
    cout << "Enter your choice: ";
    int choice = hotel.getValidIntInput(OPTION_ADD_CUSTOMER, OPTION_EXIT);

    switch (choice) {
      case OPTION_ADD_CUSTOMER:
        hotel.addCustomer();
        break;
      case OPTION_DISPLAY_CUSTOMERS:
        hotel.displayCustomers();
        break;
      case OPTION_SEARCH_CUSTOMER:
        hotel.searchByCustomerID();
        break;
      case OPTION_DELETE_CUSTOMER:
        hotel.deleteCustomerByID();
        break;
      case OPTION_DISPLAY_ROOM_TYPE:
        hotel.displayRoomType();
        break;
      case OPTION_CALCULATE_RENTAL_FEE:
        hotel.calculateRentalFeeByCustomerID();
        break;
      case OPTION_EXIT:
        cout << "Exiting...\n";
        return 0;
      default:
        cout << "Invalid choice\n";
        break;
    }
  }

  return 0;
}