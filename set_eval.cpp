#include <vector>
#include <cmath>
#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/format.hpp>
#include <iterator>
#include <iomanip>

/**

    1. Read 4 files (GT, L, SC, QSC)
    2. Find minimum
    3. align numbers && write lines

**/

int main(void){
    std::cout << "Open New files." << std::endl;

    std::ofstream file_obj1;
    file_obj1.open("/home/url-intern/url/evaluate/for_eval/dcc01_eval.txt");
    file_obj1.close();
    std::ofstream file_obj2;
    file_obj2.open("/home/url-intern/url/evaluate/for_eval/L_eval.txt");
    file_obj2.close();
    std::ofstream file_obj3;
    file_obj3.open("/home/url-intern/url/evaluate/for_eval/SC_eval.txt");
    file_obj3.close();
    std::ofstream file_obj4;
    file_obj4.open("/home/url-intern/url/evaluate/for_eval/QSC_eval.txt");
    file_obj4.close();

    std::cout<< "Find minimum" << std::endl;

    std::ifstream myfile1("/home/url-intern/url/evaluate/L_trajectory.txt");
    myfile1.unsetf(std::ios_base::skipws);
    unsigned line_count1 = std::count(
        std::istream_iterator<char>(myfile1),
        std::istream_iterator<char>(), 
        '\n');

    std::ifstream myfile2("/home/url-intern/url/evaluate/SC_trajectory.txt");
    myfile2.unsetf(std::ios_base::skipws);
    unsigned line_count2 = std::count(
        std::istream_iterator<char>(myfile2),
        std::istream_iterator<char>(), 
        '\n');

    std::ifstream myfile3("/home/url-intern/url/evaluate/QSC_trajectory.txt");
    myfile3.unsetf(std::ios_base::skipws);
    unsigned line_count3 = std::count(
        std::istream_iterator<char>(myfile3),
        std::istream_iterator<char>(), 
        '\n');

    std::ifstream myfile4("/home/url-intern/url/evaluate/dcc01.txt");
    myfile4.unsetf(std::ios_base::skipws);
    unsigned line_count4 = std::count(
        std::istream_iterator<char>(myfile4),
        std::istream_iterator<char>(), 
        '\n');

    int min_num = 0;
    if (line_count1 <= line_count2){
        if (line_count1 <= line_count3){
            min_num = line_count1;
        }
        else{
            min_num = line_count3;
        }
    }
    else{
        if (line_count2 <= line_count3){
            min_num = line_count2;
        }
        else{
            min_num = line_count3;
        }
    }
    std::cout << "Minimun num is " << min_num << std::endl;

    
    int gap1 = line_count1 - min_num;
    int det1 = line_count1 / gap1;
    int gap2 = line_count2 - min_num;
    int det2 = line_count2 / gap2;
    int gap3 = line_count3 - min_num;
    int det3 = line_count3 / gap3;
    int gap4 = line_count4 - min_num;
    int det4 = line_count4 / gap4;

    int num_1 = 0;
    int num_2 = 0;
    int num_3 = 0;
    int num_4 = 0;

    std::ifstream readFile1("/home/url-intern/url/evaluate/L_trajectory.txt");
    std::string line1;
    while(getline(readFile1, line1)){
        if ( (line_count1 % det1) != 0 ){
            std::ofstream FileObj1;
            FileObj1.open("/home/url-intern/url/evaluate/for_eval/L_eval.txt", std::ios::app);
            FileObj1 << std::fixed << std::setprecision(8)
                    << line1
                    << "\n";
            FileObj1.close();
            num_1++;
        }
    }
    readFile1.close();


    std::ifstream readFile2("/home/url-intern/url/evaluate/SC_trajectory.txt");
    std::string line2;
    while(getline(readFile2, line2)){
        if ( (line_count2 % det2) != 0 ){
            std::ofstream FileObj2;
            FileObj2.open("/home/url-intern/url/evaluate/for_eval/SC_eval.txt", std::ios::app);
            FileObj2 << std::fixed << std::setprecision(8)
                    << line2
                    << "\n";
            FileObj2.close();
            num_2++;
        }
    }
    readFile2.close();


    std::ifstream readFile3("/home/url-intern/url/evaluate/QSC_trajectory.txt");
    std::string line3;
    while(getline(readFile3, line3)){
        if ( (line_count3 % det3) != 0 ){
            std::ofstream FileObj3;
            FileObj3.open("/home/url-intern/url/evaluate/for_eval/QSC_eval.txt", std::ios::app);
            FileObj3 << std::fixed << std::setprecision(8)
                    << line3
                    << "\n";
            FileObj3.close();
            num_3++;
        }
    }
    readFile3.close();


    std::ifstream readFile4("/home/url-intern/url/evaluate/dcc01.txt");
    std::string line4;
    while(getline(readFile4, line4)){
        if ( (line_count4 % det4) != 0 ){
            std::ofstream FileObj4;
            FileObj4.open("/home/url-intern/url/evaluate/for_eval/dcc01_eval.txt", std::ios::app);
            FileObj4 << std::fixed << std::setprecision(8)
                    << line4
                    << "\n";
            FileObj4.close();
            num_4++;
        }
    }
    readFile4.close();

    std::cout << "number of lines is each " << num_1 << " "  << num_2 << " "  << num_3 << " "  << num_4 << " !!" << std::endl;

    return 0;
}
