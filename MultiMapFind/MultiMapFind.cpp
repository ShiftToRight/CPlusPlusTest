// MultiMapFind.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>

int _tmain(int argc, _TCHAR* argv[])
{
	  std::multimap<char,int> mymm;

  mymm.insert (std::make_pair('x',10));
  mymm.insert (std::make_pair('y',20));
  mymm.insert (std::make_pair('z',30));
  mymm.insert (std::make_pair('z',40));

 // std::multimap<char,int>::iterator it = mymm.find('x');
 // mymm.erase (it);
 // mymm.erase (mymm.find('z'));

  // print content:
  std::cout << "elements in mymm:" << '\n';
  std::cout << "y => " << mymm.find('y')->second << '\n';
  std::cout << "z => " << mymm.find('z')->second << '\n';
 // std::cout << "z => " << mymm.find(30)->first << '\n';




   std::multimap<char,int> foo,bar;

  foo.insert(std::make_pair('x',100));
  foo.insert(std::make_pair('y',200));

  bar.insert(std::make_pair('a',11));
  bar.insert(std::make_pair('b',22));
  bar.insert(std::make_pair('a',55));

  foo.swap(bar);

  std::cout << "foo contains:\n";
  for (std::multimap<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';

  std::cout << "bar contains:\n";
  for (std::multimap<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    std::cout << (*it).first << " => " << (*it).second << '\n';



  return 0;
}

