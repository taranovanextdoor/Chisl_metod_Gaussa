#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
    for (auto& i : v) {
        cout << setw(4) ;
        out << i << ' ';
    }
    return out;
}
//template <typename T, typename R>
void operator+( vector<double >& a,vector<double > b){// a - строка в которую записываем р-т
    if( a.size() == b.size() ){
        int it = 0;
        for(auto& item : a){
            item += b[it];
            it ++;
        }
    }
}
template <typename T, typename R>
vector<T> operator*( vector<T> a, R multiplier){
    for(auto& item : a){
        item *= multiplier;
    }
    return a;
}
int main()
{
    vector<double> v0 = {2, 4, -1, 1 },
                            v1 = {-3, -3, -5, 2},
                            v2 = {-1, 1, -4, 1};
    v0 + v2;// результат записывается в первый операнд
    v1 + v2*-3;
    v2 + v0;
    v2 + v1;
    cout << "Matrix after metod Gaussa is " << endl;
    cout << v0 << endl << v1 << endl << v2 << endl ;
    double x3 = v2 [3] / v2 [2];
    double x2 = ( v1 [3] - v1 [2] * x3) / v1 [1];
    double x1 = v0 [3] - v0[2] * x3 - v0[1] * x2;
    cout << "x1 = " << x1 << endl << "x2 = " << x2 << endl << "x3 = " << x3 ;
}