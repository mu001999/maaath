#pragma once

#include <string>

/*
Request:
[TYPE_ID][KEYWORDS]

Response4search:
filename#...#
path#...#
abstract#...#
...

Response4knowgraph:
keyword#...# (first keyword after segmentation)
...
*/

class Request
{
public:
    enum CommType
    {
        Article = 0,
        Definition,
        Property,
        Example,
        Exercise,
        ConceptMap
    };

    // constructor
    Request(const std::string &raw);
    // destructor
    ~Request() = default;

    CommType type() const;
    std::string keywords() const;

private:
    CommType type_;
    std::string keywords_;
};
