// CMappingTable_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include "CMappingTable.h"

int main()
{
    CMappingTable<uint16_t, uint16_t> myTable;

    myTable.reserve(10);

    myTable.insert(1191, 444);
    myTable.insert(2, 544);
    myTable.insert(2, 543);
    myTable.insert(2, 542);
    myTable.insert(1, 644);
    myTable.insert(4, 744);
    myTable.insert(0-1, 144);

    CMapElementIteratorUINT16 it = myTable.begin();
    for (it=myTable.begin(); it!=myTable.end(); ++it)
    {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    std::cout << myTable.find(2)->second << std::endl;
    std::cout << myTable.find(33)->second << std::endl;

    if(myTable.find(43) == myTable.end())
    {
        std::cout << "Element was not found!" << std::endl;
    }


	for (;;)
	{

		CMappingTable<uint16_t, uint16_t> myTable2;
		const uint16_t max = 10;
		myTable2.reserve(max);
		for (uint16_t i = 0; i < max + 2; i++)
		{
			int16_t error = myTable2.insert(1 + i, i + 10);
			if (error != 0)
				std::cout << error << std::endl;
		}

		it = myTable2.begin();
		for (it = myTable2.begin(); it != myTable2.end(); ++it)
		{
			std::cout << it->first << " => " << it->second << std::endl;
		}
	}
    return 0;
}


