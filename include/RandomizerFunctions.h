#ifndef RANDOMIZERFUNCTIONS_H_INCLUDED

#include "KIni.h"
#include <string>

// General Constants
const std::string got_two_rangs_message = "GotBothRangs";
const std::string activate_message = "Activate";

// Rainbow Cliffs
const std::string first_time_in_rainbow_cliffs_id = "692,FirstTimeInRainbowCliffs";

// Two Up
const std::string two_up_two_rangs_script_id = "81,iftwobooms";
const std::string two_up_frill_objective_id = "83,RangFrillObj";

bool change_GetTwoRangsFromRainbowCliffs(KIniRoot* rainbow_cliffs);
void change_DisableTwoUpTwoRangsCheck(KIniRoot* two_up);

#define RANDOMIZERFUNCTIONS_H_INCLUDED

#endif
