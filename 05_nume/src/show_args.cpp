#include <iostream>

int main(int argc,char* argv[]){
   
    if (argc <= 1) {
        std::cout << "No program arguments found." << std::endl;
    }
    for (int i = 0; i < argc; i++) {
       
        std::cout << argv[i] << std::endl;
    }

}