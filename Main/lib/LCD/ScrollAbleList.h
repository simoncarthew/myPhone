#ifndef SCROLLABLELIST_H
#define SCROLLABLELIST_H

#include <LCD.h>
#include <string>
#include <vector>

namespace MyPhone {

class ScrollAbleList : public LCD {
public:
    // Constructor & Destructor
    ScrollAbleList(LCD& lcd, 
                   const std::vector<std::string>& Items, 
                   const std::vector<std::string>& SubItems, 
                   short OuterBoundary = 5, 
                   short InnerBoundary = 3,
                   uint8_t ItemSize = 2, 
                   uint8_t SubItemSize = 1);

    ~ScrollAbleList(); // Destructor

    // Class Methods
    void Display();
    void Scroll(bool Direction);

    
    // Class Variables
    const std::vector<std::string>& Items;
    const std::vector<std::string>& SubItems;
    short OuterBoundary;
    short InnerBoundary;

    uint8_t ItemSize;
    uint8_t SubItemSize;
    uint16_t ItemHeight;
    uint16_t SubItemHeight;

    uint8_t TotalVisibleItems;
    uint8_t BoxHeight;
    uint8_t ItemOffset;

    int Selected;
    int TopItem;
    short ListOffset;

    TFT_eSprite frame;

    // Class Methods
    short getBoxHeight();
    short getItemOffset();
};

}

#endif
