/**\file ******************************************************************************************

 \par Projekt: Common

 \n   Wurm GmbH & Co. KG
 \n   Morsbachtalstrasse 30
 \n   42857 Remscheid
 \n   Germany

 Autor: karbach
 Datum: 03.05.2016

 \par Beschreibung: Abstraktion der STL-Map (std::map) für einen fest allozierten Speicher. Die Map sortiert
 die eingetragenen Values anhand des gegebenen Keys. Dabei ist zu beachten, dass nicht alle Key/Value pairs
 so einfach sortiert werden können.

 Letzte Änderung am: $Date: $
 durch: $Author: $

 $Revision: $
 $Id: $

 ***************************************************************************************************/
#ifndef CMAPPINGTABLE_H_
#define CMAPPINGTABLE_H_
// -------------------------------------------------------------------------------------------------
//                                Include files
// -------------------------------------------------------------------------------------------------
#include <stdint.h>
#include <stdlib.h>
//#include "CDebugChannel.h"
// -------------------------------------------------------------------------------------------------
//                                Macros
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------
//                                Type definitions
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------
//                                Structure Declarations
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------
//                                Global Variables
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------
//                                Extern Variables
// -------------------------------------------------------------------------------------------------

// -------------------------------------------------------------------------------------------------
//                               Global function prototypes
// -------------------------------------------------------------------------------------------------

/// \defgroup CMappingTable
/// \brief    Gruppe für CMappingTable

template<class _KeyType, class _ValueType>
struct CMapElement
{
    _KeyType first;
    _ValueType second;
};

typedef CMapElement<uint16_t, uint16_t> *CMapElementIteratorUINT16;

/// \ingroup CMappingTable
template<class _KeyType, class _ValueType>
class CMappingTable
{
public:
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details CMappingTable Konstruktor
    ///
    /// \ingroup CMappingTable
    CMappingTable() : elementBuffer(NULL), curPosition(0), isReserved(false), reserveSize(0) { }
	///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details CMappingTable Dekonstruktor
    ///
    /// \ingroup CMappingTable
    ~CMappingTable() 
	{
		if (elementBuffer)
           delete[] elementBuffer;
		
		curPosition = 0;
		isReserved = false;
		reserveSize = 0;
	}
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Festen Speicherbereich für die Key/Value Pairs allozieren, muss nach dem Instanzieren
    /// einmal aufgerufen werden.
    ///
    /// \param memorySize Speichergröße in Anzahl Elemente der gegeben Typen
    /// \ingroup CMappingTable
    void reserve(const uint16_t memorySize)
    {
        // Wurde bereits Speicher alloziert?
        if(CheckReserved())
        {
            printf("Memory is already allocated!");
            return;
        }
        elementBuffer = new CMapElement<_KeyType, _ValueType>[memorySize];
        if(elementBuffer)
        {
            reserveSize = memorySize;
            isReserved = true;
			memset(elementBuffer, 0 ,memorySize * (sizeof(_KeyType) + sizeof(_ValueType))) ;
		}
        else
        {
            printf("Unable to allocate Memory!");
            return;
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Ein Key/Value Pair in die Map eintragen und anschließend Map sortieren.
    /// Warnung: Da die Map nach jedem insert neu sortiert wird ist dies möglicherweise langsam!
    /// \return  0 Einsortierung hat funktioniert
    /// \return -1 Kein Speicher alloziert
    /// \return -2 Speicher voll
    /// \ingroup CMappingTable
    int16_t insert(_KeyType key, _ValueType value)
    {
        if(!CheckReserved())
        {
            // FEHLER: Speicher ist nicht alloziert
            return -1;
        }

        if(curPosition >= reserveSize)
        {
            // FEHLER: Die Map ist voll
    //        return -2;
        }

        // Prüfen ob der Key bereits eingetragen ist
        CMapElement<_KeyType, _ValueType> *findTemp = find(key);
        if(curPosition && findTemp != end())
        {
            // Ja er ist bereits vorhanden, alten überschreiben
            findTemp->first = key;
            findTemp->second = value;
        }
        else
        {
            // Nein Key ist noch nicht vorhanden, neu Anlegen
            CMapElement<_KeyType, _ValueType> temp;
            temp.first = key;
            temp.second = value;

			if (curPosition >= reserveSize)
			{
				CMapElement<_KeyType, _ValueType> * buffer = new CMapElement<_KeyType, _ValueType>[curPosition + 1];

				for (uint16_t i = 0; i < curPosition; i++)
					buffer[i] = elementBuffer[i];

				delete[] elementBuffer;

				elementBuffer = buffer;
			}
            elementBuffer[curPosition++] = temp;
            // Map wird neu sortiert
            SortBuffer();
        }
		return 0;
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Ein Key/Value Pair in der Map suchen. Es kann keine doppelten Keys geben. Wird ein Key
    /// gefunden, dann wird ein Zeiger auf den Iterator zurückgegeben. Wird das Element nicht gefunden
    /// wird der end()-Iterator zurückgegeben
    ///
    /// \ingroup CMappingTable
    CMapElement<_KeyType, _ValueType> *find(_KeyType key)
    {
        if(!CheckReserved())
        {
            // FEHLER: Map ist nicht alloziert
            return NULL;
        }
        if(curPosition == 0)
        {
            // FEHLER: Es sind keine Keys in der Map (leer)
            return end();
        }
        // Pair suchen und Pointer zurückgeben
        for(uint16_t i=0;i<curPosition;i++)
        {
             if(elementBuffer[i].first == key)
             {
                 return &elementBuffer[i];
             }
        }
        // Der Key wurde nicht in der Map gefunden
        return end();
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Anfangsiterator holen
    ///
    /// \ingroup CMappingTable
    CMapElement<_KeyType, _ValueType> *begin()
    {
        return &elementBuffer[0];
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Enditerator holen, zeigt auf die Stelle hinter dem letzten Element (wie STL)
    ///
    /// \ingroup CMappingTable
    CMapElement<_KeyType, _ValueType> *end()
    {
        return &elementBuffer[curPosition];
    }
private:
    /// \brief Speicher von Pairs
    CMapElement<_KeyType, _ValueType> *elementBuffer;
    /// \brief letzte Einfügeposition im Puffer
    uint16_t curPosition;
    /// \brief Wurde Speicher schon alloziert?
    bool isReserved;
    /// \brief Anzahl an allozierten Elementen
    uint16_t reserveSize;

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Prüfen ob Speicher bereits alloziert wurde
    ///
    /// \ingroup CMappingTable
    bool CheckReserved()
    {
        if(!isReserved || reserveSize == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Ordnungsrelation um Elemente zu sortieren, hier einfacher Größenvergleich
    ///
    /// \ingroup CMappingTable
    static int __compareKeys(const void * a, const void * b)
    {
        // Aus den Parametern Pointer ableiten damit Keys genutzt werden können
        CMapElement<_KeyType, _ValueType>* _a = (CMapElement<_KeyType, _ValueType>*)a;
        CMapElement<_KeyType, _ValueType>* _b = (CMapElement<_KeyType, _ValueType>*)b;

        // Sortierrelation für allgemeine Typen definieren, bei speziellen Klassen müssen
        // nur diese Operatoren definiert werden damit die Keys vergleichbar werden
        if(_a->first < _b->first) return -1;
        if(_a->first == _b->first) return 0;
        if(_a->first > _b->first) return 1;
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// \details Map Sortieren. Wird automatisch beim Einfügen ausgeführt, dadurch ist die Map immer sortiert
    /// Wird der gleiche Key mehrfach eingefügt wird die Map nicht neu Sortiert da, sich der Key schon an
    /// der richtigen Stelle befindet.
    ///
    /// Als Sortieralgorithmus wird qsort aus stdlib.h verwendet.
    ///
    /// \ingroup CMappingTable
    void SortBuffer()
    {
        if(!CheckReserved())
        {
            return;
        }

        // Elemente Sortieren, es wird nur auf den Key geschaut und daraufhin der Speicherbereich mit der
        // Größe aus dem sizeof umkopiert. Somit lässt sich so gut wie jede Art von Daten sortieren.
        qsort(elementBuffer, curPosition, sizeof(CMapElement<_KeyType, _ValueType>), __compareKeys);
    }
};
#endif
