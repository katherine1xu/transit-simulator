#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <list>
#include <iostream>
#include <string>

#include "src/passenger_generator.h"
#include "src/stop.h"
#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

class PassengerGenerator;

class Stop;
/**
* @brief The class that describes a route.
*
*/
class Route {
 public:
/**
* @brief Constructor sets the route name, list of stops, list of distances
* between the stops, the number of stops, and passenger generator
*
* @param[in] std::string name
* @param[in] Stop** list of Stop* objects
* @param[in] double* list of distances between stops
* @param[in] int number of passengers
*
*/
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
    PassengerGenerator *);
/**
* @brief Method clones the route
* @return Route * that is a copy
*
*/
  Route * Clone();
/**
* @brief Method will update the stops in the list as well as generate new
* passengers
*
*/
  void Update();
  std::list<double> GetRouteDistBetween();
  int GetRouteNumOfStops();
  int GetDestinationStopIndex() const;
  Stop * GetStopInList(std::list<Stop *>, int);
/**
* @brief Method will check to see if the route is at the last stop of the list
* @return Boolean that indicates true if at the end of the stops, false otherwise
*
*/
  bool IsAtEnd() const;
/**
* @brief Method will update the GetDestinationStop by incrementing the index
* and updating the pointer to the destination_stop_ by iterating through the
* stops up to the index
*
*/
  void NextStop();  // Change destination_stop_ to next stop
  Stop * GetDestinationStop() const;    // Get pointer to next stop
  Stop * GetStopBefore();
  Stop * GetStopAfter();
  double GetTotalRouteDistance() const;
  double GetNextStopDistance() const;
  void Report(std::ostream&);
  std::string GetName();
  std::list<Stop *> GetRouteStops();
/**
* @brief Method will create new passengers by calling the passenger generator
*
*/
  int GenerateNewPassengers();       // generates passengers on its route

/**
* @brief Method will update the route data structs everytime it's called
*
*/
  void UpdateRouteData();
  RouteData GetRouteData();

 private:
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  bool is_at_current_stop_;
  RouteData route_data_;

  // double trip_time_; // derived data - total distance travelled on route
};
#endif  // SRC_ROUTE_H_
