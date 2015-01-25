#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
void sleep (unsigned int mseconds)
{
  clock_t goal = mseconds + clock();
  while (goal > clock());
}
void randgen (size_t length, char* arr, char *randchar)
{
  for (int i = 0; i != length; i++)
  {
    *(i + arr) = *(randchar + (rand() % 63));           //generate random character in that space
  }
}
int main(int argc, char* argv[])
{
  char randchar[] = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";
  char *targ = (char*)argv[1];
  char *ptr = &targ[0];
  size_t targlen = strlen(ptr);
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
