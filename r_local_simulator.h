#ifndef R_SRC_LOCAL_SIMULATOR_H_
#define R_SRC_LOCAL_SIMULATOR_H_

#include <vector>
#include <string>
#include "src/simulator.h"

class rLocalSimulator : public Simulator {
 public:
  bool Start() override;
  bool Update() override;
 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // R_SRC_LOCAL_SIMULATOR_H_
