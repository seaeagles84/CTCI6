#include <iostream>
#include <string>

void ConvertSpace(std::string &str, int true_length)
{
    int count = 0;
    int index = 0;
    std::string replstr = "%20";
    
    while (count < true_length) {
        if (str[index] != ' ') {
            index += 1;
        } else {
            str.replace(index,1,replstr);
            index += 3;
        }
        count++;
    }
}

int main()
{
    using namespace std;
    
    string inputstr = "Mr Jaaaaohn Smith    ";
    int true_length = 17;
    
    cout << "Before: " << inputstr << endl;
    ConvertSpace(inputstr, true_length);
    cout << "Aftere: " << inputstr << endl;
    
    return (0);
}
