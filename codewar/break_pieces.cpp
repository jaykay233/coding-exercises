// You are given a ASCII diagram, comprised of minus signs -, plus signs +, vertical bars | and whitespaces . Your task is to write a function which breaks the diagram in the minimal pieces it is made of.

// For example, if the input for your function is this diagram:

// +------------+
// |            |
// |            |
// |            |
// +------+-----+
// |      |     |
// |      |     |
// +------+-----+
// the returned value should be the list of:

// +------------+
// |            |
// |            |
// |            |
// +------------+
// (note how it lost a + sign in the extraction)

// as well as

// +------+
// |      |
// |      |
// +------+
// and

// +-----+
// |     |
// |     |
// +-----+
// The diagram is given as an ordinary multiline string. There are no borders touching each others.

// The pieces should not have trailing spaces at the end of the lines. However, it could have leading spaces if the figure is not a rectangle. For instance:

//     +---+
//     |   |
// +---+   |
// |       |
// +-------+
// However, it is not allowed to use more leading spaces than necessary. It is to say, the first character of some of the lines should be different than a space.

// Finally, note that only the explicitly closed pieces are considered. Spaces "outside" of the shape are part of the background . Therefore the diagram above has a single piece.

// Have fun!

// Note : in C++ you are provided with two utility functions :

// std::string join(const std::string &sep, const std::vector<std::string> &to_join); // Returns the concatenation of all the strings in the vector, separated with sep 

// std::vector<std::string> split_lines(const std::string &to_split); // Splits a string, using separator '\n'
// Harder version of the kata available here: Break the Pieces (evilized edition)
// =======


#include <vector>
#include <utility>
#include <math>
std::string join(const std::string &sep, const std::vector<std::string>& to_join);
std::vector<std::string> split_lines(const std::string& to_split);

using namespace std;

int area(pair<int,int>& a,pair<int,int>& b){
    return abs(b.first - a.first) * (b.second - a.second);
}

vector<string> break_piece(const string &shape)
{
    vector<pair<int,int>> points;
    vector<string> lines = split(shape);
    for(int i = 0 ;i < line.size();i++){
        for(int j = 0;j<lines[i].size();j++){
            if(lines[i][j] == '+')
                points.push_back(make_pair(i,j));
        }
    }
    sort(points.begin(), points.end(),[](auto& p1, auto& p2){
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    });
    
    vector<bool> vis(points.size(),false);
    vector<vector<bool>> connected(points.size(),vector<bool>(points.size(),false));
    

    for(int i = 0; i<points.size();i++){
        int j = i + 1;
        for(;j<points.size();j++){
            if(area(points[i],points[j])==0)    
                continue;
            break;
        }
        pair<int,int> upper_right = {points[i].first, points[j].second};
        pair<int,int> lower_left = {points[j].first, points[i].second};
        
    }   

}