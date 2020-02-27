#ifndef SRC_STOP_H_
#define SRC_STOP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <list>
#include <iostream>

#include "src/bus.h"
#include "src/passenger.h"
#include "src/data_structs.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

class Bus;
/**
* @brief The class that describes a stop.
*
*/
class Stop {
 public:
/**
* @brief Constructor sets longitude and latitude of a stop
* @param[in] double= 44.973723 longitude
* @param[in] double= -93.234365 latitude
*
*/
  explicit Stop(int, double = 44.973723, double = -93.235365);
  // Adding passengers to the stop (from the generator)
  int GetId() const;
/**
 * @brief Method adds passenger to the stop by adding to the end of the passenger
 *
 * @return Returns 0
 *
 */
  int AddPassengers(Passenger *);
/**
 * @brief Method will update the stop by updating the passengers at the stop
 *
 */
  void Update();
/**
 * @brief Method will remove passengers from the stop and add the onto a bus
 * @param[in] Bus* The bus that is currently at the stop
 *
 */
  double GetLongitude();
  double GetLatitude();
/**
 * @brief Method will remove passengers from stop and load them onto the bus
 * that is passed in
 * @return number of passengers loaded
 *
 */
  int LoadPassengers(Bus *);
  std::list<Passenger *> GetPassengersAtStop();
  void Report(std::ostream &out = std::cout) const;
  int GetNumberOfPassengers();

 private:
  int id_;
  std::list<Passenger *> passengers_;  // considered array, vector, queue, list
  double longitude_;
  double latitude_;  // are we using long/lat coords?
  bool reached_current_stop_;  // this flag is used for iterating through the
                               // outgoing/incoming routes so that it doesn't
                               // include stops the bus already passed
  // derived information - not needed depending on passengers_
  // data structure implementation?
  // int passengers_present_;
};
#endif  // SRC_STOP_H_
