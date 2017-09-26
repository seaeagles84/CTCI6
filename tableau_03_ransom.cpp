In movies, ransom notes would always be written by cutting out words from magazines or books, and pasting them to a sheet of paper. Imagine you have a ransom note you want to write, and a book. How you be able to determine if the text from the book contains all the words we need to cut out for our ransom note text? More precisely, given a string of text, and a list of words, how would find out if all the words exist in the string of text?

//magazine = ['Hello', 'World','Stuff']
//Message = "Hello World"
//return = true

void parseMessage(string str, vector<string> &mystr) 
{
    bool first = true;
    int start = 0, end = 0;
    string word;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ' ') {
            end = i-1;
            word = str.substr(start, end-start+1);
            mystr.push_back(word);
            start = i+1;
        }
    }
    word = str.substr(start, str.size() - start);
    mystr.push_back(word);
}

void countWord(vector<string> vec_str, unordered_map<string,int> &mymap)
{
    for (int i = 0; i < vec_str.size(); i++) {
        if (mymap.count(vec_str[i])) == 0) {
            mymap.insert(make_pair(vec_str[i], 1));
        } else {
            mymap[vec_str[i]]++;
        }
    }
}

bool isPossible(vector<string> magazine, string message)
{
    unordered_map<string,int>::iterator it;
    unordered_map<string,int> map_magazine;
    unordered_map<string,int> map_message;
    vecotr<string> mystr;
    
    countWord(magazine, map_magazine);
    parseMessage(message, mystr);
    countWord(mystr, map_message);
    
    it = map_message.begin();
    while (it != map_message.end()) {
        string str = it->first;
        int count_msg = it->second;
        int count_magazine = map_magazine.count(str);
        if (count_magazine < count_msg)
            return false; 
        ++it;
    }
    
    return true;
}

int main()
{
    vector<string> magazine {"Hello", "World", "Stuff"};
    string message = "Hello World";
    
    cout << "Is possible? " << isPossible (magazine, message) << endl;
    
    return 0;
}
