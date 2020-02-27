#ifndef SRC_BUS_H_
#define SRC_BUS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <list>
#include <string>

#include "src/passenger.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/data_structs.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
/**
* @brief The class that describes a bus object.
*
*/
class Bus {
 public:
/**
* @brief Constructor sets the bus name, out and in routes, capacity, and speed
*
* @param[in] std::string name
* @param[in] Route* outgoing_route_
* @param[in] Route* incoming_route_
* @param[in] int Passenger capacity
* @param[in] double speed
*
*/
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
                                                 double speed = 1);
  double GetSpeed();
/**
* @brief Method will load passengers at a stop onto the bus
* @param[in] Stop* The current stop the bus is at
* @return Boolean that indicates true if load false otherwise
*
*/
  bool LoadPassenger(Stop *);  // returning revenue delta
/**
* @brief Method will unload the passengers on the bus off the bus
* @param[in] Stop* The current stop the bus is at
*
*/
  void UnloadPassenger(Stop *);
/**
* @brief Method move the bus by adjusting the distance_remaining_
*
* @return Boolean that indicates true move, false otherwise
*
*/
  bool Move();
/**
 * @brief Method will call update on every passenger on the bus
 *
 */
  void UpdatePassengersOnBus();
/**
* @brief Method checks to see if the bus has finished the trip going out and in
*
* @return Boolean that indicates true if all routes complete, false otherwise
*
*/
  bool IsTripComplete();
/**
* @brief Method checks to see if the bus has finished its current route
*
* @return Boolean that indicates true if route is finished, otherwise false
*
*/
  bool IsRouteComplete();
/**
* @brief Method checks if the bus is currently at a stop or if it is moving
*
* @return Boolean that indicates true if it is at the stop, false otherwise
*
*/
  bool GotToStop();
  Stop * GetCurrentStop();
  void SetCurrentStop();
  void SetDistanceRemaining(Route *);
  char GetDirection();
  Route * GetCurrentRoute();
  std::list<Passenger *> GetBusPassengers();
/**
* @brief Method is a helper function that adds passengers to the end of the
* passenger list for the bus
*
*/
  void AddPass(Passenger *p);
/**
* @brief Method changes the direction of the bus from outgoing to incoming
*
*/
  void ChangeDirection();
/**
* @brief Method updates the bus by moving the bus if it is not at a stop and
* but if it is at a stop, it unloads and loads passengers from that stop and
* readjusts the pointers to the next stop as well as the distance remaining
*
* @return Boolean that indicates true move, false otherwise
*
*/
  void Update();
  void Report(std::ostream &out = std::cout);
/**
* @brief Method calculates the avg distance between two stops in the long
*
* @return Double that indicates the avg long distance between the two stops
*
*/
  double CalculateAvgLongitude();
/**
* @brief Method calculates the avg distance between two stops in the lat
*
* @return Double that indicates the avg lat distance between the two stops
*
*/
  double CalculateAvgLatitude();
  int GetNumberIntOfPassengers();
/**
* @brief Method updates the bus data structs data
*
*
*/
  void UpdateBusData();
  BusData GetBusData();
  std::string GetName() const;
  Stop * GetNextStop();
  Stop * GetPreviousStop();
  int GetCapacity();
/**
* @brief Helper function that iterates through the stops in current route to
* get the route the bus is currently at
*
* @return Returns the stop pointed to by the pointer that reps the current stop
*/
  Stop * StopInRoute();

 private:
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  char direction_;
  // std::list<Stop *>::iterator stop_iterator_;
  // std::list<Stop *> stops_bus_visited_;
  Stop * current_stop_;
  Route * current_route_;
  bool bus_is_on_the_move_;
  BusData bus_data_;
  bool is_at_stop_;
  int stop_number_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
};
#endif  // SRC_BUS_H_
