#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include "../abilitycard.h"
class Download: public AbilityCard {
    public:
    void activate() override;
};

#endif