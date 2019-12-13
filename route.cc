/**
 * @file route.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include "src/route.h"

Route::Route(std::string name, Stop ** stops,
            double * distances, int num_stops,
            PassengerGenerator * passGen) {
  for (int i = 0; i < num_stops; i++) {
    stops_.push_back(stops[i]);
  }
  for (int i = 0; i < num_stops - 1; i++) {
    distances_between_.push_back(distances[i]);
  }
  name_ = name;
  num_stops_ = num_stops;
  destination_stop_index_ = 0;
  destination_stop_ = stops_.front();
  generator_ = passGen;
  route_data_ = RouteData();
}

Route * Route::Clone() {
  Stop ** stop_array = new Stop *[num_stops_];
  double * distance_array = new double[num_stops_-1];
  int stop_array_counter = 0;
  int distance_array_counter = 0;
  for (std::list<Stop *>::iterator it = stops_.begin();
      it != stops_.end(); it++) {
    stop_array[stop_array_counter] = *it;
    stop_array_counter++;
  }
  for (std::list<double>::const_iterator it2 = distances_between_.begin();
      it2 != distances_between_.end(); it2++) {
    distance_array[distance_array_counter] = *it2;
    distance_array_counter++;
  }

  Route * route_clone = new Route(name_, stop_array, distance_array, num_stops_,
                                  generator_);
  return route_clone;
}

void Route::Update() {
  UpdateRouteData();
  for (std::list<Stop *>::iterator it = stops_.begin();
      it != stops_.end(); it++) {
    (*it)->Update();
    GenerateNewPassengers();
  }
}

std::list<double> Route::GetRouteDistBetween() {
  return distances_between_;
}

int Route::GetRouteNumOfStops() {
  return num_stops_;
}

int Route::GetDestinationStopIndex() const {
  return destination_stop_index_;
}

Stop * Route::GetStopInList(std::list<Stop *> stops,
                            int destination_stop_index) {
  std::list<Stop *>::iterator it = stops.begin();
  for (int i = 0; i < destination_stop_index; i++) {
    (it)++;
  }
  return *it;
}

bool Route::IsAtEnd() const {
  if (GetDestinationStop() == stops_.back()) {
    return true;
  } else {
    return false;
  }
}

void Route::NextStop() {
  destination_stop_index_++;
  destination_stop_ = GetStopInList(stops_, destination_stop_index_);
}

Stop * Route::GetDestinationStop() const {
  return destination_stop_;
}

Stop * Route::GetStopBefore() {
  std::list<Stop *>::iterator it = stops_.begin();
  for (int i = 0; i < destination_stop_index_ - 1; i++) {
    ++it;
  }
  return (*it);
}

Stop * Route::GetStopAfter() {
  std::list<Stop *>::iterator it = stops_.begin();
  for (int i = 0; i < destination_stop_index_ + 1; i++) {
    ++it;
  }
  return (*it);
}

double Route::GetTotalRouteDistance() const {
  double total_distance = 0.0;
  std::list<double>::const_iterator it = distances_between_.begin();
  for (int i = 0; i < (num_stops_ -1); i++) {
    total_distance += *it;
    (it)++;
  }
  total_distance += distances_between_.back();
  return total_distance;
}

double Route::GetNextStopDistance() const {
  double next_stop_dist = 0.0;
  std::list<double>::const_iterator it = distances_between_.begin();
  for (int i = 0; i < destination_stop_index_ - 1; i++) {
    (it)++;
  }
  next_stop_dist = *it;
  return next_stop_dist;
}

int Route::GenerateNewPassengers() {
  generator_->GeneratePassengers();
  return 0;
}

void Route::Report(std::ostream &out) {
  out << "Name: " << name_ << std::endl;
  out << "Num stops: " << num_stops_ << std::endl;
  int stop_counter = 0;
  for (std::list<Stop *>::const_iterator it = stops_.begin();
      it != stops_.end(); it++) {
    (*it)->Report(out);
    stop_counter++;
  }
}

std::string Route::GetName() {
  return name_;
}

std::list<Stop *> Route::GetRouteStops() {
  return stops_;
}

void Route::UpdateRouteData() {
  std::vector<StopData> stops_data_;
  route_data_.id = GetName();
  for (std::list<Stop *>::iterator it = stops_.begin();
        it != stops_.end(); it++) {
    StopData temp_stop_data = StopData();
    temp_stop_data.id = std::to_string((*it)->GetId());
    temp_stop_data.position.x = (*it)->GetLongitude();
    temp_stop_data.position.y = (*it)->GetLatitude();
    temp_stop_data.num_people = (*it)->GetNumberOfPassengers();
    stops_data_.push_back(temp_stop_data);
  }
  route_data_.stops = stops_data_;
}

RouteData Route::GetRouteData() {
  UpdateRouteData();
  return route_data_;
}
