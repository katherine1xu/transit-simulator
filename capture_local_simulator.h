#ifndef SRC_CAPTURE_LOCAL_SIMULATOR_H_
#define SRC_CAPTURE_LOCAL_SIMULATOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <vector>
#include <iostream>
#include <ostream>
#include <fstream>
#include <string>

#include "src/simulator.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
 * @brief The class that is used for outputing data into .txt file
 */
class CaptureLocalSimulator : public Simulator {
 public:
  bool Start() override;
  bool Update() override;
  void SetFilename(std::string);
 private:
  std::string filename_;
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // SRC_CAPTURE_LOCAL_SIMULATOR_H_
