/*
	StringSplitter.h - Library for splitting strings based on a char delimiter.
	Created by Harsha C. Alva, November 26, 2016.
	Released into the public domain.
*/

#include "Arduino.h"
#include "StringSplitter.h"

StringSplitter::StringSplitter(String s, char c, unsigned int limit){
	count = countOccurencesOfChar(s, c) + 1;  // fix for no elements, ie return input string

	if(count <= 1 || limit <= 1){
		count = 1;
		op[0] = s;
		return;
	}

	if(count > limit) count = limit;
	if(count > MAX) count = MAX;

  String d = String(c);
  String first;
  String second = s;

  int current = 0;
  while(second.indexOf(d) > -1){
    if(current >= (count - 1)){
      //current++;
      break;
    }
    for (int i = 0; i < second.length(); i++) {
      if (second.substring(i, i + 1) == d) {
        first = second.substring(0, i);
        second = second.substring(i + 1);
        if(first.length() > 0)
					op[current++] = first;
        break;
      }
    }
  }
    //current = (current < MAX - 1) ? current : MAX;
  if(second.length() > 0)
		op[current] = second;
	//else
	//	--count;
}

int StringSplitter::countOccurencesOfChar(String s, char c){
  int size = 0;
  for(int x = 0; x < s.length(); (s[x] == c) ? size++ : 0, x++);
  return size;
}

int StringSplitter::getItemCount(){
  return count;
}


String StringSplitter::getItemAtIndex(int index){
	if((index >= 0) && (index < count))
		return op[index];
  else
		return "";
}
