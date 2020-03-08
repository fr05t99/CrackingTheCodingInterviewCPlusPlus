// Tested online at https://practice.geeksforgeeks.org/problems/urlify-a-given-string/0
// Please ignore the main() part. I have made it harder because I wanted to try char pointer instead of string

#include<bits/stdc++.h>
using namespace std;
void urlify(char *s, int trueLength) {
    int spaceCount = 0;
    for (int j = 0;j < trueLength;j++) {
        if (s[j] == ' ') {
            spaceCount++;
        }
    }
    int index = trueLength + 2 * spaceCount;
    s[index] = '\0';
    int i = trueLength - 1;
    while (i >= 0) {
        if (s[i] == ' ') {
            s[index - 1] = '0';
            s[index - 2] = '2';
            s[index - 3] = '%';
            index -= 3;
        } else {
            s[index - 1] = s[i];
            index--;
        }
        i--;
    }
    printf("%s\n", s);
}
int main()
 {
    int t;
    cin >> t;
    while (t--) {
        string str, s;
        getline(cin, s);
        getline(cin, str);
        int len;
        cin >> len;
        char *cstr = new char[str.length() + 1000];
        urlify(strcpy(cstr, str.c_str()), len);
    }
	return 0;
}
