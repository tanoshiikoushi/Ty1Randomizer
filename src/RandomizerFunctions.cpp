#include "RandomizerFunctions.h"
#include <iostream>

bool change_GetTwoRangsFromRainbowCliffs(KIniRoot* rainbow_cliffs)
{
    // Get Attribute ID
    std::string attributes_id = rainbow_cliffs->queryElementByName("TYATTRIBUTES")->getInstanceList()->getCurrentContained()
                                              ->queryPropertyByName("ID")->getPropertyValue();

    KIniEvent* post_cutscene_event = new KIniEvent(nullptr);
    post_cutscene_event->appendProperty(new KIniProperty(false, false, false, "TargetID", attributes_id, nullptr, nullptr, 0));
    post_cutscene_event->appendProperty(new KIniProperty(false, false, false, "Message", got_two_rangs_message, nullptr, nullptr, 0));

    ListMember<KIniInstance>* iter = rainbow_cliffs->queryElementByName("DIALOG")->getInstanceList();
    KIniInstance* first_time_in_rainbow_cliffs_instance = nullptr;

    while (iter != nullptr)
    {
        if (!iter->isComment())
        {
            if (first_time_in_rainbow_cliffs_id.compare(iter->getCurrentContained()->queryPropertyByName("ID")->getPropertyValue()) == 0)
            {
                first_time_in_rainbow_cliffs_instance = iter->getCurrentContained();
            }
        }

        iter = iter->getNextListMember();
    }

    if (!(first_time_in_rainbow_cliffs_instance == nullptr))
    {
        KIniProperty* on_completion_event = first_time_in_rainbow_cliffs_instance->queryPropertyByName("OnCompletion");
        if (on_completion_event == nullptr) { return false; }
        KIniEvent* to_delete = on_completion_event->getEvent();
        on_completion_event->setEvent(post_cutscene_event);

        delete to_delete;
        return true;
    }

    return false;
}

void randomizeOneLevel(KIniRoot* level, uint32_t seed, std::string to_ignore)
{
    uint8_t randomize_count = 0;
    std::string* valid_positions = new std::string[MAX_RANDOMIZED_COUNT];
    for (uint8_t j = 0; j < MAX_RANDOMIZED_COUNT; j++)
    {
        valid_positions[j] = "";
    }

    ListMember<KIniInstance>* iter = nullptr;

    // Gather valid Cog Positions
    iter = level->queryElementByName("GOLDENCOG")->getInstanceList();
    while (iter != nullptr)
    {
        if (!iter->isComment())
        {
            if (to_ignore.find(iter->getCurrentContained()->queryPropertyByName("type")->getPropertyValue()) == std::string::npos)
            {
                valid_positions[randomize_count] = iter->getCurrentContained()->queryPropertyByName("pos")->getPropertyValue();
                randomize_count++;
            }
        }

        iter = iter->getNextListMember();
    }



    // Gather valid Thunder Egg Positions
    iter = level->queryElementByName("THUNDEREGG")->getInstanceList();
    while (iter != nullptr)
    {
        if (!iter->isComment())
        {
            if (to_ignore.find(iter->getCurrentContained()->queryPropertyByName("ID")->getPropertyValue()) == std::string::npos)
            {
                valid_positions[randomize_count] = iter->getCurrentContained()->queryPropertyByName("pos")->getPropertyValue();
                randomize_count++;
            }
        }
        iter = iter->getNextListMember();
    }

    // Gather valid Bilby Positions
    iter = level->queryElementByName("CAGEDBILBY")->getInstanceList();
    while (iter != nullptr)
    {
        if (!iter->isComment())
        {
            if (to_ignore.find(iter->getCurrentContained()->queryPropertyByName("type")->getPropertyValue()) == std::string::npos)
            {
                valid_positions[randomize_count] = iter->getCurrentContained()->queryPropertyByName("pos")->getPropertyValue();
                randomize_count++;
            }
        }

        iter = iter->getNextListMember();
    }

    uint8_t* available_ids = new uint8_t[randomize_count];
    uint8_t rando_done_count = 0;
    uint8_t temp_int = 0;
    uint8_t to_select = 0;

    for (uint8_t i = 0; i < randomize_count; i++)
    {
        available_ids[i] = i;
    }

    srand(seed);

    // Write to valid Thunder Eggs
    iter = level->queryElementByName("THUNDEREGG")->getInstanceList();
    while (iter != nullptr)
    {
        if (!iter->isComment())
        {
            if (to_ignore.find(iter->getCurrentContained()->queryPropertyByName("ID")->getPropertyValue()) == std::string::npos)
            {
                to_select = rand() % (randomize_count-rando_done_count);
                iter->getCurrentContained()->queryPropertyByName("pos")->setPropertyValue(valid_positions[available_ids[to_select]]);

                // switch a valid position back to where this was
                if (to_select != (randomize_count-rando_done_count-1))
                {
                    temp_int = available_ids[(randomize_count-rando_done_count-1)];
                    available_ids[(randomize_count-rando_done_count-1)] = 0xFF;
                    available_ids[to_select] = temp_int;
                }

                rando_done_count++;
            }
        }

        iter = iter->getNextListMember();
    }

    // Write to valid Bilbies
    iter = level->queryElementByName("CAGEDBILBY")->getInstanceList();
    while (iter != nullptr)
    {
        if (!iter->isComment())
        {
            if (to_ignore.find(iter->getCurrentContained()->queryPropertyByName("type")->getPropertyValue()) == std::string::npos)
            {
                to_select = rand() % (randomize_count-rando_done_count);
                iter->getCurrentContained()->queryPropertyByName("pos")->setPropertyValue(valid_positions[available_ids[to_select]]);

                // switch a valid position back to where this was
                if (to_select != (randomize_count-rando_done_count-1))
                {
                    temp_int = available_ids[(randomize_count-rando_done_count-1)];
                    available_ids[(randomize_count-rando_done_count-1)] = 0xFF;
                    available_ids[to_select] = temp_int;
                }

                rando_done_count++;
            }
        }

        iter = iter->getNextListMember();
    }

    // Write to valid Cogs
    iter = level->queryElementByName("GOLDENCOG")->getInstanceList();
    while (iter != nullptr)
    {
        if (!iter->isComment())
        {
            if (to_ignore.find(iter->getCurrentContained()->queryPropertyByName("type")->getPropertyValue()) == std::string::npos)
            {
                to_select = rand() % (randomize_count-rando_done_count);
                iter->getCurrentContained()->queryPropertyByName("pos")->setPropertyValue(valid_positions[available_ids[to_select]]);

                // switch a valid position back to where this was
                if (to_select != (randomize_count-rando_done_count-1))
                {
                    temp_int = available_ids[(randomize_count-rando_done_count-1)];
                    available_ids[(randomize_count-rando_done_count-1)] = 0xFF;
                    available_ids[to_select] = temp_int;
                }

                rando_done_count++;
            }
        }

        iter = iter->getNextListMember();
    }

    delete[] valid_positions;
    delete[] available_ids;
}
