#ifndef _EDIT_DISTANCE_H
#define _EDIT_DISTANCE_H
#include <string>
#include<vector>

namespace mozart {

class EditDistanceHelp {
    private:
        /**
         * @brief the array data type as ArrayData
         */
        struct ArrayData {
            int dist;       /**< The min edit distance until current pos*/
            int pre_x;      /**< Store the previous postion, x part horizontal */
            int pre_y;      /**< Store the previous postion, y part vertical*/
        };
    public:
        /**
         * @brief Find the min edit distance and return the edit distance.
         * will sotre the best path info in  std::string rs1, rs2
         * s1, s2 is the user given  std::string for caculating the edit distance
         * @param s1,s2 Input  std::strings.
         * @param rs1,rs2 Store the result path.
         * @return Will return the edit distance for  std::string s1 and s2.
         */
        static int CalcPath(const  std::string &s1, const  std::string &s2,  std::string &rs1,  std::string &rs2);
        /**
         * @brief  Find the min edit distance only do not need path info.
         */
        static int EditDistance(const  std::string& s1, const  std::string& s2);
    private:
        /**
         * @brief Set all data members value for one array element.
         */
        static void SetArrayData(ArrayData &a, int dist, int pre_x, int pre_y);
        /**
         * @brief the best path and store result to  std::string rs1 and rs2.
         * Recursion function.
         * @param array The array will store all the info of each positon (x, y).
         * @param index_x  Current postion x part.
         * @param index_y  Current postion y part.
         * @param s1,s2  The input two  std::string for caculating their best edit distance path.
         * @param rs1,rs2 Will store the result.
         */
        static void StoreResult(std::vector<std::vector<ArrayData>>& array, int index_x, int index_y,
                                const  std::string &s1, const  std::string &s2,
                                std::string &rs1,  std::string &rs2);
};

} // ns mozart
#endif // _EDIT_DISTANCE_H