//TP 2018/2019: ZSR 3, Zadatak 14
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrica;

bool DaLiJeStacionaran (Matrica m) {
    for (int i=0;i<m.size();i++) {
        for (int j=0;j<m.at(0).size();j++) {
            if (i==0 && j==0 && m.at(i).at(j)==m.at(i).at(j+1) && m.at(i).at(j)==m.at(i+1).at(j)) return true;
            if (i==0 && j==m.size()-1 && m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i+1).at(j)) return true;
            if (i==m.size()-1 && j==0 && m.at(i).at(j)==m.at(i-1).at(j) && m.at(i).at(j)==m.at(i).at(j+1)) return true;
            if (i==m.size()-1 && j==m.size()-1 && m.at(i).at(j)==m.at(i).at(j-1) && m.at(i).at(j)==m.at(i-1).at(j)) return true;
            if (i==0 && )
        }
    }
}

int main ()
{
	return 0;
}