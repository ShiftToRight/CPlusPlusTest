// CPlusPlusTest.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <cstdint>
#define ANZAHL_CTRL_SEGMENTE 5

// uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = {255,0,1,2,3};               // 4
// uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = {252,253,254,255,0 };        // 4
// uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = { 0,   1,  2,  3,0 };        // 3       <-
// uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = { 0,   1,  2,  3,7 };        // 3
// uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = { 0,   1,  2,  7,8 };        // 2
// uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = { 253,  254,  255,  0, 1 };  // 4
 //uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = { 0,  1,  2,  3, 255 };  // 3
 uint8_t plotcontrol[ANZAHL_CTRL_SEGMENTE] = { 0,  255,  0,  1, 2 };  // 4
int main() {
    uint8_t  segmentindex = 0;          // Ersmal Index 0 gefunden
    uint32_t sequenzNumber = 0;         
    uint8_t value_before = 0;

    uint8_t *sourceAdr = plotcontrol;
  
    // nach dem Segment mit dem höchsten SegmentCounter suchen
    for (uint8_t i = 0; i < ANZAHL_CTRL_SEGMENTE; i++)
    {
        uint8_t value;

        value = *sourceAdr++;
        
        
        // Im ersten Durchlauf:
        // Sequenznummer als gültig gefunden ansehen = gültiger Eintrag wird in der 0. Kontrollstruktur vermutet...
        if (i == 0) {
            segmentindex = 0;
            sequenzNumber = value;
            value_before = value;
        }

        // Umbruch gefunden ?
        // Umbruch von 255->0 => weitersuchen
        //
        if ((value == 0 && value_before == 255) || (value == (value_before + 1)))
        {
            // Ja : der nächste Index ist kleiner als der letzte
            segmentindex = i;
            sequenzNumber = value;// value_before;
            value_before = value;
        }
    /*    else if (value != (value_before + 1) && i > 0)
        {
            segmentindex = i-1;
            sequenzNumber = value_before;
            break;
        }
        */

        
        
    /*    
        if (value_before == 255 && value == 0 && i < (ANZAHL_CTRL_SEGMENTE -1))
        {
            value_before = value;
            continue;
        }
        else if (value_before == 255 && value == 0 && i == (ANZAHL_CTRL_SEGMENTE - 1))
        {
            segmentindex = i;
            printf("PlotCTRL Umbruch\n");
            printf("sequenzNumber: %d\n", (uint32_t)sequenzNumber);
            printf("Segmentindex: %d\n", (uint32_t)segmentindex);
            break;
        }
        else  if (value == (value_before + 1))
        {
            // Hier wird der Index gespeichert bei dem der voriege Wert um 1 kleiner ist als der aktuelle.
            segmentindex = i;
        }
        else if ((value > (value_before + 1) || value < value_before) && i > 0 )
        {
            // ein Umbruch zu alten Werten wird unter folgenden Bedingungen festgestellt:
            // 1. der Unterschied des aktuellen Wertes zum voriegen ist größer 1  oder
            // 2. der aktuelle Wert ist kleiner als der voriege.
            // Dann ist der gespeicherte Index die letzte Speicherposition.
            sequenzNumber = value_before;
            printf("PlotCTRL Umbruch\n");
            printf("sequenzNumber: %d\n", (uint32_t)sequenzNumber);
            printf("Segmentindex: %d\n", (uint32_t)segmentindex);
            break;
        }
        value_before = value;
        */
    }
    
    printf("\nPlotCTRL Gefunden\n");
    printf("sequenzNumber: %d\n", (uint32_t)sequenzNumber);
    printf("Segmentindex:  %d\n", (uint32_t)segmentindex);

}


