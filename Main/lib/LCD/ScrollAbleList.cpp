#include "ScrollAbleList.h"

namespace MyPhone {

// Constructor
ScrollAbleList::ScrollAbleList(LCD& lcd, const std::vector<std::string>& Items, const std::vector<std::string>& SubItems, short OuterBoundary, short InnerBoundary, uint8_t ItemSize,  uint8_t SubItemSize)
    : LCD(lcd), Items(Items), SubItems(SubItems), OuterBoundary(OuterBoundary), InnerBoundary(InnerBoundary), ItemSize(ItemSize), SubItemSize(SubItemSize), frame(&Screen)
{
    // Get Item Dimensions
    Screen.setTextSize(ItemSize);
    ItemHeight = Screen.fontHeight();

    // Get SubItem Dimensions
    Screen.setTextSize(SubItemSize);
    SubItemHeight = Screen.fontHeight();

    // Initialize beginning format
    ItemOffset = getItemOffset();
    BoxHeight = getBoxHeight();
    TotalVisibleItems = ScreenHeight / BoxHeight + 1;

    // Create Sprite    
    frame.setColorDepth(16);
    frame.createSprite(ScreenWidth, ScreenHeight);
    frame.fillSprite(TFT_BLACK);

    Selected = 0;
    TopItem = 0;
    ListOffset = 0;
}

// Destructor
ScrollAbleList::~ScrollAbleList() {

}

// Public Methods
void ScrollAbleList::Display(){
    // Clear Screen
    frame.fillScreen(TFT_BLACK);

    // Set positions
    short Text_Pos = OuterBoundary - ListOffset;
    short NextLinePos = BoxHeight - ListOffset;

    // Draw Top Line
    frame.drawLine(0, Text_Pos - OuterBoundary, ScreenWidth, 0, TFT_WHITE);
    // frame.drawLine(0, 1, ScreenWidth, 1, ST77XX_WHITE);

    // Iterate over the Lists
    for (size_t i = TopItem; i < TopItem + TotalVisibleItems; ++i) {

        // Selected Item Config
        uint16_t TextColour;
        if (i == Selected){
            TextColour = TFT_BLACK;
            frame.fillRect(1, Text_Pos - OuterBoundary + 2, ScreenWidth - 2, BoxHeight - 3, TFT_WHITE);
        }else{
            TextColour = TFT_WHITE;
        }

        // Pull item and subitem
        std::string Item = Items[i];
        std::string SubItem = SubItems[i];

        // Print Item
        frame.setTextColor(TextColour);
        frame.setTextSize(ItemSize);
        frame.setCursor(OuterBoundary, Text_Pos);
        frame.println(Item.c_str());

        // Print SubItem
        frame.setTextColor(TextColour);
        frame.setTextSize(SubItemSize);
        frame.setCursor(OuterBoundary, Text_Pos + ItemHeight + InnerBoundary);
        frame.println(SubItem.c_str());

        // Draw Bottom Line
        frame.drawLine(0, NextLinePos, ScreenWidth, NextLinePos, TFT_WHITE);
        // frame.drawLine(0, NextLinePos - 1, ScreenWidth, NextLinePos - 1, ST77XX_WHITE);

        // Set Next Positions
        Text_Pos = NextLinePos + OuterBoundary;
        NextLinePos = NextLinePos + BoxHeight - 1;
        }

    frame.pushSprite(0,0);
}

void ScrollAbleList::Scroll(bool Direction){
    if (Direction == true) { // Scroll Down
        // Change Offset
        if (Selected == TopItem + TotalVisibleItems - 2){
            ListOffset = ItemOffset;
        }
        // Change Top Item
        if (Selected == TopItem + TotalVisibleItems - 1){
            TopItem += 1;
        }
        // Scroll
        Selected = Selected + 1;
    } else { // Scroll Up
        // Change Offset
        if (Selected == TopItem + 1) {
            ListOffset = 0;
        }
        // Change Top Item
        if (Selected == TopItem) {
            TopItem = TopItem - 1;
        }
        // Scroll
        Selected = Selected - 1;
    }
}

// Private Methods
short ScrollAbleList::getBoxHeight(){
    return ItemHeight + SubItemHeight + 2 * OuterBoundary + InnerBoundary;
}

short ScrollAbleList::getItemOffset(){
    return ScreenHeight % getBoxHeight();
}

}