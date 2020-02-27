#include "src/bus.h"

Bus::Bus(std::string name, Route * out, Route * in,
        int capacity, double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  distance_remaining_ = 0;
  direction_ = 'E';
  current_route_ = outgoing_route_;
  current_stop_ = (outgoing_route_)->GetRouteStops().front();
  is_at_stop_ = true;
  stop_number_ = 0;
  bus_data_ = BusData();
}


bool Bus::LoadPassenger(Stop * this_stop) {
  if (this_stop != NULL) {
      this_stop->LoadPassengers(this);
    return true;
  }
  return false;
}

void Bus::UnloadPassenger(Stop * this_stop) {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
    if ((*it)->GetDestination() == this_stop->GetId()) {
      this_stop->AddPassengers(*it);
      it = passengers_.erase(it);
      it--;
    }
  }
}
double Bus::GetSpeed() {
  return speed_;
}
bool Bus::Move() {
  distance_remaining_ = distance_remaining_ - speed_;
    return true;
}

// bool Refuel() {
//  This may become more complex in the future
//  fuel_ = max_fuel_;
// }
void Bus::UpdatePassengersOnBus() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

bool Bus::IsTripComplete() {
  if (GetDirection() == 'W') {
    if (distance_remaining_ <= 0) {
      if (incoming_route_->GetDestinationStopIndex()
          == (incoming_route_->GetRouteNumOfStops() - 1) ) {
        return true;
      } else {
        return false;
      }
    } else {
        return false;
      }
  } else {
    return false;
  }
}

bool Bus::IsRouteComplete() {
  if (GetDirection() == 'E') {
    if (distance_remaining_ <= 0) {
      if (outgoing_route_ != NULL) {
        if (outgoing_route_->GetDestinationStopIndex() ==
            (outgoing_route_->GetRouteNumOfStops() - 1) ) {
          return true;
        } else {
          return false;
        }
      }
    } else {
      return false;
    }
  } else if (GetDirection() == 'W') {
    return IsTripComplete();
  } else {
    return false;
  }
}

bool Bus::GotToStop() {
  if (distance_remaining_ <= 0) {
    distance_remaining_ = 0;
    return true;
  } else {
    return false;
  }
}

Stop * Bus::GetCurrentStop() {
  return current_stop_;
}

Stop * Bus::GetPreviousStop() {
  return current_route_->GetStopBefore();
}

void Bus::SetCurrentStop() {
  current_stop_ = current_route_->GetDestinationStop();
}

void Bus::SetDistanceRemaining(Route * aRoute) {
  distance_remaining_ = aRoute->GetNextStopDistance();
}

char Bus::GetDirection() {
  return direction_;
}

Route * Bus::GetCurrentRoute() {
  return current_route_;
}

std::list<Passenger *> Bus::GetBusPassengers() {
  return passengers_;
}

void Bus::ChangeDirection() {
  direction_ = 'W';
  stop_number_ = 0;
  current_route_ = incoming_route_;
  current_stop_ = incoming_route_->GetDestinationStop();
  distance_remaining_ = 0;
}

// Helper function that pushes the passenger to end ot bus
void Bus::AddPass(Passenger *p) {
  this->passengers_.push_back(p);
}

void Bus::Update() {  // using common Update format
  UpdateBusData();
  if (IsTripComplete() == false) {
    if (IsRouteComplete() == false) {
      if (GotToStop() == false) {
        is_at_stop_ = false;
        // UpdateBusData();
        Move();
      } else {  // If the bus is at the stop, then unload
                // and update the current stop pointer as well as change the
                // distance_remaining_ variable to distance to next stop
        is_at_stop_ = true;
        // UpdateBusData();
        UnloadPassenger(current_stop_);
        LoadPassenger(current_stop_);
        UpdatePassengersOnBus();
        stop_number_++;
        current_route_->NextStop();  // this moves the route's ptr to next stop
                                        // and incr the dest stop index
        // SetDistanceRemaining(current_route_);  // sets new dist remaining
        SetCurrentStop();
        SetDistanceRemaining(current_route_);  // sets new dist remaining
      }
    } else {  // if route is complete, check if on out route then chng direction
      if (GetDirection() == 'E') {
        ChangeDirection();
      }
    }
  } else {  // if the trip is complete, then change the bus memvar to "delete"
    speed_ = 0;
    distance_remaining_ = 9999;
  }
}

void Bus::Report(std::ostream &out) {
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}

double Bus::CalculateAvgLongitude() {
  Stop * curr = GetCurrentStop();
  Stop * prev = GetPreviousStop();
  double avg_longitude = (curr->GetLongitude() + prev->GetLongitude())/2.0;
  return avg_longitude;
}

double Bus::CalculateAvgLatitude() {
  Stop * curr = GetCurrentStop();
  Stop * prev = GetPreviousStop();
  double avg_latitude = (curr->GetLatitude() + prev->GetLatitude())/2.0;
  return avg_latitude;
}

int Bus::GetNumberIntOfPassengers() {
  int num_of_pass = 0;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
      it!= passengers_.end(); it++) {
    num_of_pass++;
  }
  return num_of_pass;
}


void Bus::UpdateBusData() {
  bus_data_.id = name_;
  bus_data_.num_passengers = GetNumberIntOfPassengers();
  bus_data_.capacity = passenger_max_capacity_;
  if (is_at_stop_ == true) {
    bus_data_.position.x = GetPreviousStop()->GetLongitude();
    bus_data_.position.y = GetPreviousStop()->GetLatitude();
  } else {
    bus_data_.position.x = CalculateAvgLongitude();
    bus_data_.position.y = CalculateAvgLatitude();
  }
}

BusData Bus::GetBusData() {
  UpdateBusData();
  return bus_data_;
}

std::string Bus::GetName() const {
  return name_;
}

Stop * Bus::GetNextStop() {
  return current_route_->GetStopAfter();
}

int Bus::GetCapacity() {
  return passenger_max_capacity_;
}
