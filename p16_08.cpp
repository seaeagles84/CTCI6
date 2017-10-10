#include <iostream>
#include <vector>
#include <list>
using namespace std;

string ConvertChunk(int num) {
    vector<string> small {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
        "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    vector<string> ten {"dummyten 0", "dummyten 1", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string hundred = "hundred";
    string space = " ";
    string out;
    
    if (num/100)
        out = space + small[num/100] + space + hundred;
        
    num = num%100;
    
    if (num == 0) {
        // do nothing
    } else if (num < 20) {
        out = out + space + small[num];
    } else {
        out = out + space + ten[num/10];
        if (num%10) 
            out = out + space + small[num%10];
    }
    
    return out;
}

void Num2English(int num) {
    vector<string> big {"dummybig","thousand", "million", "billion"};
    list<string> chunk;
    string outcome;
    string space = " ";
    
    if (num == 0) {
        cout << "zero" << endl;
        return;
    }
    
    if (num < 0) {
        outcome = "negative" + space;
        num = -num; // be careful here! 
    }
    
    int count = 0;
    while (num) {
        if (count > 0) {
            chunk.push_front(ConvertChunk(num % 1000)+space+big[count]);
        } else {
            chunk.push_front(ConvertChunk(num % 1000));
        }
        num = num/1000;
        count++;
    }
        
    int idx = 0;
    for (const auto &str : chunk) {
        if (idx > 0) 
            outcome += space + str; 
        else
            outcome += str;
        //cout << "idx: " << idx << endl;
        //idx++;
    }
    
    cout << outcome << endl;
}

int main() {
	
	Num2English(3);
	Num2English(19);
	Num2English(30);
	Num2English(45);
	Num2English(100);
	Num2English(104);
	Num2English(832);
	Num2English(11832);
	Num2English(3211832);
	Num2English(-3211832);
	Num2English(2147483648-1);
	
	return 0;
}
