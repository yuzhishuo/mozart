#include <iostream>
#include <iomanip>

#include "edit_distance.h"
using namespace std;
using namespace mozart;

/**
 * find the min edit distance and return the edit distance
 * will sotre the best path info in string rs1, rs2
 * s1, s2 is the user given string for caculating the edit distance
 */
int  EditDistanceHelp::CalcPath(const string &s1, const string &s2, string &rs1, string &rs2)
{
    //first find min dist and store path info
    int len1 = s1.length();
    int len2 = s2.length();

    vector<vector<ArrayData>> array (len1 + 1, vector<ArrayData>(len2 + 1));

    //kernal for finding the best path and store path info to array
    for (int i = 0; i <= len1; i++)
        SetArrayData(array[i][0], i, i - 1, 0);
    for (int j = 0; j <= len2; j++)
        SetArrayData(array[0][j], j, 0, j - 1);
    int min_dist;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++) {
            if (array[i -1][j].dist < array[i][j - 1].dist)  //can also be <=
                SetArrayData(array[i][j], array[i - 1][j].dist + 1, i - 1, j);
            else
                SetArrayData(array[i][j], array[i][j - 1].dist + 1, i, j - 1);
            min_dist = array[i - 1][j - 1].dist + (s1[i - 1] != s2[j - 1]);
            if (min_dist < array[i][j].dist)  // < is OK but <= make modify high priority
                SetArrayData(array[i][j], min_dist, i - 1, j - 1);
        }

    //store the best path result to  two result string  rs1 and rs2
    StoreResult(array, len1, len2, s1, s2, rs1, rs2);
    min_dist = array[len1][len2].dist;

    //print array
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            cout << "(" << array[i][j].pre_x << "," << setw(2) << array[i][j].pre_y << ")  ";
        }
        cout << endl;
    }

    //return min edit distance
    return min_dist;
}

/**
 * find the min edit distance only do not need path info
 */
int  EditDistanceHelp::EditDistance(const string& s1, const string& s2)
{
    using std::min;
    int len1 = s1.length();
    int len2 = s2.length();
    int array[len1 + 1][len2 + 1];
    for (int i = 0; i <= len1; i++)
        array[i][0] = i;
    for (int j = 1; j <= len2; j++)
        array[0][j] = j;
    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
            array[i][j] = min(min(array[i - 1][j] + 1, array[i][j - 1] + 1),
                              array[i - 1][j - 1] + (s1[i - 1] != s2[j - 1]));
    return array[len1][len2];
}

/**
 * Set all data members value for one array element
 */
void EditDistanceHelp::SetArrayData(ArrayData &a, int dist, int pre_x, int pre_y)
{
    a.dist = dist;
    a.pre_x = pre_x;
    a.pre_y = pre_y;
}

/**
 * Based on the path info stored in array ,find the best path and store result to string rs1 and rs2
 */
void  EditDistanceHelp::StoreResult(vector<std::vector<ArrayData>>& array, int index_x, int index_y,
                        const string &s1, const string &s2,
                        string &rs1, string &rs2)
{
    if (index_x == 0 && index_y== 0)
        return;

    if ((array[index_x][index_y].pre_x < index_x) && (array[index_x][index_y].pre_y < index_y)) {
        StoreResult(array, index_x - 1, index_y - 1, s1, s2, rs1, rs2);
        rs1 += s1[index_x - 1];
        rs2 += s2[index_y - 1];
    } else if (array[index_x][index_y].pre_x < index_x) {
        StoreResult(array, index_x - 1, index_y, s1, s2, rs1, rs2);
        rs1 += s1[index_x - 1];
        rs2 += '-';
    } else {
        StoreResult(array, index_x, index_y - 1, s1, s2, rs1, rs2);
        rs1 += '-';
        rs2 += s2[index_y - 1];
    }
}