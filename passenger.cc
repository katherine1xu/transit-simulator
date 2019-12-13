/**
 * @file passeenger.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/passenger.h"

#include <iostream>
#include <string>


int Passenger::count_ = 0;

// Passenger::Passenger(Stop * dest = NULL, std::string name = "Nobody") {
Passenger::Passenger(int destination_stop_id, std::string name): name_(name),
                     destination_stop_id_(destination_stop_id),
                     wait_at_stop_(0), time_on_bus_(0), id_(count_) {
  count_++;
  just_got_on_ = false;
}

void Passenger::GetOnBus() {
  if (time_on_bus_ == 0) {
    just_got_on_ = true;
    time_on_bus_ = 1;
    Passenger::Update();
  }
}

void Passenger::Update() {
  if (Passenger::IsOnBus() == true) {
    if (just_got_on_ == true) {
      just_got_on_ = false;
    } else {
      time_on_bus_++;
    }
  } else {
    wait_at_stop_++;
  }
}

int Passenger::GetTotalWait() const {
  return (wait_at_stop_ + time_on_bus_);
}

bool Passenger::IsOnBus() const {
  if (time_on_bus_ >= 1) {
    return true;
  } else {
    return false;
  }
}

int Passenger::GetDestination() const {
  return destination_stop_id_;
}

int Passenger::GetTimeOnBus() {
  return time_on_bus_;
}

int Passenger::GetTimeAtStop() {
  return wait_at_stop_;
}

std::string Passenger::GetName() {
  return name_;
}

void Passenger::Report(std::ostream &out) {
  out << "Name: " << name_ << std::endl;
  out << "Destination: " << destination_stop_id_ << std::endl;
  out << "Total Wait: " << GetTotalWait() << std::endl;
  out << "\tWait at Stop: " << wait_at_stop_ << std::endl;
  out << "\tTime on bus: " << time_on_bus_ << std::endl;
}
