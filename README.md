# StringSplitter Library for Arduino
An Arduino library that adds string splitting functionality to character delimited C++ strings.

## Features

- Adds string splitting functionality to Arduino.
- Can specify the maximum number of substrings, via ``limit`` up to ``MAX``.
- ``MAX`` is ``5`` by default and can be overridden in ``StringSplitter.h``.
- ``limit`` equal to and below ``1``, returns the whole input string.
- The last substring contains the remaining part of the whole string, including delimiters.
- If delimiter is not found, the whole string can be found in the first substring.

## Methods
#### 1. Initialization ####
```
new StringSplitter(String input, char delimiter, unsigned int limit);
* Return: StringSplitter object.
* input: String with delimiters to be split.
* delimiter: Character around which string will be split. Not included in substrings.
* limit: Maximum number of substrings. Overriden by MAX in StringSplitter.h

```

#### 2. Get Substring Count ####
```
int getItemCount();
* Return: Number of substrings. Min = 1, Max = (limit or MAX, whichever is lesser).
```

#### 2. Get Substring at Index ####
```
String getItemAtIndex(int index);
* Return: Substring of input string.
* index: Position of substring with respect to the input string. Starts from 0.
```

## Usage
```
#include "StringSplitter.h"

StringSplitter *splitter = new StringSplitter("abc,def,ghi,jkl", ',', 3);
int itemCount = splitter->getItemCount();

for(int i = 0; i < itemCount; i++){
  String item = splitter->getItemAtIndex(i);
}
```
