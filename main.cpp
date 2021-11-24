#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <memory>

#include <edit_distance.hpp>

using namespace mozart;
using namespace std;

/**
 * @brief 
 * 
 * @param in 
 * @param out 
 */
void TestEditDistance(ifstream& in, ofstream& out)
{
    string in_s1;
    string in_s2;
    string out_s1;
    string out_s2;
    ///loop to get input and to corresponding operation on EditDistance
    ///and write the result to the out put file
    while (in >> in_s1 >> in_s2)
    {
        EditDistanceHelp::CalcPath(in_s1, in_s2, out_s1,out_s2);
        out << out_s1 << "  " << out_s2 << std::endl;
    }
}

int main(int argc, char* argv[])
{

   if (argc != 3) {
        cout << "Usage is : ""test_edit_distance <input_file> <output_file>"<< endl;
        return -1;
    }

    ifstream in(argv[1]);
    
    if (!in) {
        cout << "Could not find the file named "
            << argv[1] << " to open!" << endl;
        return -1;
    }
    ofstream out(argv[2]);

    try {
        TestEditDistance(in, out);
    }
    catch (std::bad_alloc&) {
        cout << "no more available memory" << endl;
        in.close();
        out.close();
        return -1;
    }

    in.close();
    out.close();
    return 0;
}
