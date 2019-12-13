/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <iostream>
#include <string>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The class that describes a passenger object.
 *
 */

class Passenger {  // : public Reporter {
 public:
/**
* @brief Constructor will set name_ to "Nobody" and destnation_stop_id to -1
*
* @param[in] int=-1 Stop ID
* @param[in] std::string Name
*
*/
  explicit Passenger(int = -1, std::string = "Nobody");
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
/**
 * @brief Method will check to see if the passenger is on the bus
 *
 * @return Boolean that indicates true if on the bus and false if not
 *
 */
  bool IsOnBus() const;
  int GetDestination() const;
  int GetTimeOnBus();
  int GetTimeAtStop();
  std::string GetName();
  void Report(std::ostream &out = std::cout);

 private:
  bool just_got_on_;
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
#endif  // SRC_PASSENGER_H_
