#include <iostream>
#include <vector>

using namespace std;

class MyPoint {
    public:
    int m_r;
    int m_c;
    MyPoint (int r = 0, int c = 0) : m_r(r), m_c(c)
    {
    }
};

int main ()
{
    vector<MyPoint> vMyPt;
    vector<MyPoint>::iterator it;
    vMyPt.push_back(MyPoint(3,4));
    vMyPt.push_back(MyPoint(5,9));
    
    it = vMyPt.begin();
    while (it != vMyPt.end()) {
        cout << it->m_r << " " << it->m_c << endl;
        ++it;
    }
    
}
