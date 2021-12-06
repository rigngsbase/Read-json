
#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>

using json = nlohmann::json;

double distance(std::vector<double> vec1) {
    //std::vector<double> min ;
    double temp = 0;
    double total = 0;
    //double dist;
    auto dataSize = std::size(vec1);
    for (int i = 0; i < dataSize; i++) {
        temp = (std::abs(vec1[i] - 0.35971248));
        //return std::abs(v2[i] - v1[i]);
        temp = pow(temp, 2);
        total += temp;
    }
    return sqrt(total);
}


int main()

{
    std::ifstream file("json_final.json");
    json object = json::parse(file);  

    double min_dis = 1000;
    std::string min_name;

    for (auto& x : object.items()) {
        auto dataSize = std::size(x.value());

        for (int i = 0; i < dataSize; i++) {
            std::vector<double> vec1 = x.value()[i] ;
            double res = distance(vec1);
            /*std::cout << i << " " << res << std::endl;*/
            if (res <= min_dis) {
                min_dis = res;
                min_name = x.key();
            }
        } 
        
    }

    std::cout << min_name << " " << min_dis << std::endl;

    system("pause");
   
    return 0;
}