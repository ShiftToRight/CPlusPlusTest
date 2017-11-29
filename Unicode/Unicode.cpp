// Unicode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <codecvt>
#include <string>
#include <locale>
#include <iomanip>
#include <iostream>

int main() 
{
  using namespace std;

  ios_base::sync_with_stdio(false); // Avoids synchronization with C stdio on gcc         
                                    // (either localize both or disable sync)

  wcout.imbue(locale("en_US.UTF-8")); // change default locale

  unsigned char euroUTF8[] = { 0xE2, 0x82, 0xAC, 0x00 }; // Euro sign UTF8

  wstring_convert<codecvt_utf8<wchar_t>> converter_UTF8_wchar;
  wstring euroWideStr = converter_UTF8_wchar.from_bytes((char*)euroUTF8);
  wcout << euroWideStr << endl;

  string euroNarrowStr = converter_UTF8_wchar.to_bytes(euroWideStr);
  cout << euroNarrowStr << endl;
}


