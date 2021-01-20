#ifndef RANDOMIZERFUNCTIONS_H_INCLUDED

#include "KIni.h"
#include <string>
#include <stdlib.h>

// General Constants
const uint16_t MAX_RANDOMIZED_COUNT = 1024;
const std::string got_two_rangs_message = "GotBothRangs";
const std::string activate_message = "Activate";

// Rainbow Cliffs
const std::string first_time_in_rainbow_cliffs_id = "692,FirstTimeInRainbowCliffs";

// Two Up
//const std::string two_up_two_rangs_script_id = "81,iftwobooms";
//const std::string two_up_frill_objective_id = "83,RangFrillObj";
const std::string two_up_ignore = "277,300Opals;276,RangFrills;273,blank;271,TAThunder";

bool change_GetTwoRangsFromRainbowCliffs(KIniRoot* rainbow_cliffs);
void randomizeOneLevel(KIniRoot* level, uint32_t seed, std::string to_ignore);

#define RANDOMIZERFUNCTIONS_H_INCLUDED

#endif
