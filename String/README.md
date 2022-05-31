# String
### convert binary string to decimal
```
stoi(str, 0, 2);
```
```
### check if string s2 is substring of string s2
```
#include <bits/stdc++.h>
using namespace std;
int subStr(string s2, string s1)
{
	int counter = 0; // pointing s2
	int i = 0;
	for(;i<s1.length();i++)
	{
		if(counter==s2.length()) break;
		if(s2[counter]==s1[i]) counter++;
	    else {
			// Special case where character preceding the i'th character is duplicate
			if(counter > 0) i -= counter;
			counter = 0;
		}
	}
	return counter < s2.length()?-1:i-counter;
}

int main() {
	string s1 = "geeksfffffoorrfoorforgeeks";
	cout << subStr("for", s1);
	return 0;
}
```
