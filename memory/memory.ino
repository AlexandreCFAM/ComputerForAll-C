#include "memory.h"

void setup()
{
  Serial.begin(9600);
  Serial.println(memory::init());
  bool *ptr1 = (bool*)memory::malloc(BOOLEAN);
  *ptr1 = true;
  Serial.println(*ptr1);
  Serial.println(memory::free(ptr1, BOOLEAN));
  Serial.println(memory::free((bool*)1, BOOLEAN));
  Serial.println(*ptr1);
 /* Serial.println(*ptr);
  *ptr = true;
  Serial.println(*ptr);*/
  //memory::malloc(CHAR);
  //memory::malloc(INT);
}

void loop()
{
    
}
