#include "../include/Customer.h"

// Getters and Setters
std::string Customer::getFullName() const { return fullName; }

void Customer::setFullName(const std::string &name) { fullName = name; }

int Customer::getAge() const { return age; }

void Customer::setAge(int age) { this->age = age; }

std::string Customer::getID() const { return ID; }

void Customer::setID(const std::string &id) { ID = id; }

int Customer::getRentalDays() const { return rentalDays; }

void Customer::setRentalDays(int days) { rentalDays = days; }

std::string Customer::getRoomType() const { return roomType; }

void Customer::setRoomType(const std::string &type) { roomType = type; }

// Method to get details
std::string Customer::getDetails() const {
  return "Full Name: " + fullName + "\nAge: " + std::to_string(age) +
         "\nID: " + ID + "\nRental Days: " + std::to_string(rentalDays) +
         "\nRoom Type: " + roomType;
}