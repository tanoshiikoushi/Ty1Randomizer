#include "RandomizerFunctions.h"
#include <iostream>


int main (int argc, char* argv[])
{
    if (argc != 6)
    {
        std::cout << "Usage: Ty1Randomizer \"path_to_rc_in\" \"path_to_rc_out\" \"path_to_tu_in\" \"path_to_tu_out\" seed";
        return 0;
    }

    std::string rainbow_cliffs_lv2 = argv[1]; //"D:/Ty RE/rkv/data_pc/extract/z1.lv2";
    std::string rainbow_cliffs_out = argv[2]; //"D:/Ty RE/rkv/edit_data_pc/extract/z1.lv2";
    std::string two_up_lv2 = argv[3]; //"D:/Ty RE/rkv/data_pc/extract/a1.lv2";
    std::string two_up_out = argv[4]; //"D:/Ty RE/rkv/edit_data_pc/extract/a1.lv2";

    uint32_t seed = std::stoi(argv[5], nullptr, 10);

    KIniRoot* rainbow_cliffs = new KIniRoot(nullptr);
    KIniRoot* two_up = new KIniRoot(nullptr);

    bool ret1 = parseKIni(rainbow_cliffs, rainbow_cliffs_lv2);
    bool ret2 = parseKIni(two_up, two_up_lv2);

    if (ret1 && ret2)
    {
        bool ret3 = change_GetTwoRangsFromRainbowCliffs(rainbow_cliffs);
        if (!ret3)
        {
            std::cout << "Error with changes\n";
        }
        else
        {
            std::fstream out_rc;
            out_rc.open(rainbow_cliffs_out, std::ios::out);
            if (!out_rc.fail())
            {
                out_rc << rainbow_cliffs->toString();
            }
            else
            {
                std::cout << "Error opening rainbow_cliffs_out\n";
            }

            out_rc.close();
        }

        randomizeOneLevel(two_up, seed, two_up_ignore);

        std::fstream out_tu;
        out_tu.open(two_up_out, std::ios::out);
        if (!out_tu.fail())
        {
            out_tu << two_up->toString();
        }
        else
        {
            std::cout << "Error opening two_up_out\n";
        }

        out_tu.close();
    }
    else
    {
        std::cout << "Error loading lv2s\n";
    }

	delete rainbow_cliffs;
	delete two_up;

	return 0;
}
