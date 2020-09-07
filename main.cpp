#include <iostream>
#include <vector>
void printVector(std::vector<int> input){
    for(int i = 0; i < input.size(); ++ i) {
        std::cout<<input[i]<<std::endl;
    }
}

int main(){
    std::vector<int> testcase = {1,2,3,4,5};
    printVector(testcase);

    return 0;
}