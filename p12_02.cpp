#include <iostream>
#include <string>

using namespace std;
void reverse(char *str)
{
    char *end = str;
    char tmp;
    int nCnt = 0;
    if (str != nullptr) {
        //while (*end++ != '\0'); => Very dangerous... Try to avoid this. The pointer ends up at \0 + 1 position....
        while (*end != '\0')
            end++;
        end--;
        
        while (str < end) {
            tmp = *end;
            *end-- = *str;
            *str++ = tmp;
        }
    }
}

int main()
{
    char str[] = "I am a jedai";
    cout << "before: " << str << endl;
    reverse(str);
    cout << "after: " << str << endl;
}
