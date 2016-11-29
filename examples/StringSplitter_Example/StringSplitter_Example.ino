/*
 StringSplitter example: Basic
 
 This example shows how to split a delimited string to substrings (items) by using the StringSplitter library.
 The output is visible in the Serial Monitor.

 For more details see: https://github.com/aharshac/ArduinoStringSplitter
*/

#include "StringSplitter.h"

void setup() {
  Serial.begin(9600);
  Serial.println(F("StringSplitter Library Test"));

  String strTest = "123,456,789,abc";
  Serial.println("Test String: " + strTest);
  
  StringSplitter *split = new StringSplitter(strTest, ',', 3);  // new StringSplitter(string_to_split, delimiter, limit)
  int itemCount = split->getItemCount();
  Serial.println("Item count: " + String(itemCount));

  for(int i = 0; i < itemCount; i++){
    String item = split->getItemAtIndex(i);
    Serial.println("Item @ index " + String(i) + ": " + String(item));
  }

  Serial.println(F("End of program."));
  Serial.end();
}

void loop() {
  // put your main code here, to run repeatedly:

}
