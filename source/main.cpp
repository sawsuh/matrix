#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <cstring>
void sleep (unsigned int mseconds)
{
  clock_t goal = mseconds + clock();
  while (goal > clock());
}
/* std::string random_string (size_t length)           THIS IS THE STRING VERSION, WHICH I REMOVED WHEN I SWITCHED IT 
{                                                      TO CHARS
  auto randchar = []() -> char
  {
    const char charset[] = 
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      " abcdefghijklmnopqrstuvwxyz";
      const size_t max_index = (sizeof(charset) - 1);
      return charset [ rand() % max_index ];
  };
  std::string str(length,0);
  std::generate_n( str.begin(), length, randchar );
  return str;
} */
void randgen (size_t length, char* arr, char *randchar)
{
  for (int i = 0; i != length; i++)
  {
    *(i + arr) = *(randchar + (rand() % 62));           //generate random character in that space
  }
}
int main(int argc, char* argv[])
{
  char randchar[] = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";
  std::string targ1 = argv[1];
  char *targ = (char*)targ1.c_str();
  size_t targlen = targ1.length();
  char gend[targlen];
  randgen(targlen, gend, randchar);
  char rand[targlen];
  while (strcmp(gend, targ))        //keeps looping until the string has been generated
  {
    randgen (targlen, rand, randchar);
    for ( int i=0; i != targlen; i++)
    {
      if (*(rand + i) == *(targ + i))
      {
        *(gend + i) = *(rand + i);              //locks the character if it is generated in the right spot
        break; 
      }
    }
    for (int i=0; i != targlen; i++)
    {
      if (*(gend + i) == *(targ + i))
        {
          std::cout << *(gend + i);                 //print the locked character if it exists
        }                                           // otherwise print the random character
      else{
        std::cout << *(rand + i);
      }
    }
  sleep(20000);
  std::cout << "\r" << std::flush;
  }
  std::cout << gend << std::endl;
}
