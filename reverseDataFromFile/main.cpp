#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int dataArray[35];
    
    ifstream read("data.txt");
    
    int i = 0;
    for (i = 0; i < 35; i++) {
        read >> dataArray[i];
    }
    
    read.close();
    

    ofstream write("data.txt");
    for (i = 34 ; i >= 0; i--) {
        write << dataArray[i] << " ";
    }
    
    write.close();
    
    return 0;
}
