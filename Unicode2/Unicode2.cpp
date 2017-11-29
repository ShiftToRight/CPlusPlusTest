// Unicode2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>
#include <codecvt>
#include <string>
#include <locale>
#include <iomanip>
#include <iostream>

void hex_print(const std::string& s) {
  std::cout << std::hex << std::setfill('0');
  for(unsigned char c : s)
    std::cout << std::setw(2) << static_cast<int>(c) << ' ';
  std::cout << std::dec << '\n';
}

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cout.imbue(locale("C.UTF-8"));

  u16string globeUTF16 = u"\U0001F30D"; // Globe                                             

  wstring_convert<codecvt_utf8_utf16<char16_t>, char16_t> convert_UTF16_UTF8;

  string utf8Str = convert_UTF16_UTF8.to_bytes(globeUTF16);
  cout << "UTF-8 code units: ";
  hex_print(utf8Str);

  cout << utf8Str << endl;
}


