#include <iostream>
#include <vector>

#include "src/stop.h"

Stop::Stop(int id, double longitude, double latitude) : id_(id),
            longitude_(longitude), latitude_(latitude) {
  passengers_ = std::list<Passenger *>();
              // Defaults to Westbound Coffman Union stop
  // no initialization of list of passengers necessary
}

int Stop::AddPassengers(Passenger * pass) {
  passengers_.push_back(pass);
  return 1;
}


void Stop::Update() {
  for (std::list<Passenger *>::iterator it = passengers_.begin();
        it != passengers_.end(); it++) {
    (*it)->Update();
  }
}

int Stop::GetId() const {
  return id_;
}

double Stop::GetLongitude() {
  return longitude_;
}

double Stop::GetLatitude() {
  return latitude_;
}

// Loads passengers onto the bus
int Stop::LoadPassengers(Bus * bus) {
  std::vector<Passenger*> toDelete;
  std::list<Stop*> currStops = bus->GetCurrentRoute()->GetRouteStops();
  std::list<Passenger*> currStopPass = this->passengers_;

  for (std::list<Passenger *>::iterator it = currStopPass.begin();
      it != currStopPass.end(); it++) {
      for (std::list<Stop *>::iterator it2 = currStops.begin();
          it2!= currStops.end(); it2++) {
           if ((*it)->GetDestination() == (*it2)->GetId()) {
              bus->AddPass(*it);
              (*it)->GetOnBus();
              toDelete.push_back(*it);
            }
        }
    }

    for (Passenger* p : toDelete) {
      this->passengers_.remove(p);
    }

    return 1;
}

std::list<Passenger *> Stop::GetPassengersAtStop() {
  return passengers_;
}

void Stop::Report(std::ostream &out) const {
  out << "ID: " << id_ << std::endl;
  out << "Passengers waiting: " << passengers_.size() << std::endl;
  for (std::list<Passenger *>::const_iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
    (*it)->Report();
  }
}

int Stop::GetNumberOfPassengers() {
  int num_of_pass = 0;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end(); it++) {
    num_of_pass++;
  }
  return num_of_pass;
}
