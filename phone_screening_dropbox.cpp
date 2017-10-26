#include <iostream>
using namespace std;
/*

- /foo
    - /images
      - /foo.png
    - /temp
      - /baz
        - /that.foo
    - /bar.png
    - /file.tmp
    - /other.temp
    - /blah.txt
    

[
   ['/foo/bar.png', '/foo/images/foo.png'],
   ['/foo/file.tmp', '/foo/other.temp', '/foo/temp/baz/that.foo']
]

string -> [][]strings
*/

// To execute C++, please define "int main()"
int main() {
  // beginning from the root, go over each entry 
  // if the entry is a file, then do cksum filename => number
  // number -> key of a hash table unordered_multimap
  // absolute path of the file -> value of the hash table
  

}

vector<vector<string>> findDuplicates(string root) 
{
  vector<vector<string>> outcome;
  queue<string> q_entry;
  unordered_multimap<long long int, string> hashmap_size;
  unordered_map<string, bool> visited;
  
  q_entry.push(root);
  
  while (!q_entry.empty()) {
    string entry = q_entry.front();
    q_entry.pop();
    
    if (visited[entry])
      continue;
    visited[entry] = true;
    
    if (IS_DIR(entry)) {
      vector<string> entries = GETENTRIES(entry);
      for (auto elem : entries) {
        q_entry.push(elem);
      }
    } else {
      long long int key = FILESIZE(entry);
      hashmap_size[key].APPEND(entry);
    }
  }
  
  //Find the duplicates
  for (auto elem : hashmap_size) {
    if (elem.count > 1) {
      unordered_multimap<long long int, string> hashmap_cksum;
  
      for (int i = 0; i < elem.count; i++) {
        long long int key = CKSUM(entry);
        hashmap_cksum[key].APPEND(elem[i]);
      }
      
      for (auto elem_sub : hashmap_cksum) {
        if (elem_sub.count > 1) {
          outcome.push_back(elem_sub);
        }
      } 
    }
  }
  
  return outcome;
}
