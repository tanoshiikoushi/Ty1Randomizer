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

        // std::cout << first_time_in_rainbow_cliffs_instance->toString() << "end";

        delete to_delete;
        return true;
    }

    return false;
}

void change_DisableTwoUpTwoRangsCheck(KIniRoot* two_up)
{

}
