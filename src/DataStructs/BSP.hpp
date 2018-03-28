//
//  BSP.hpp
//  fnMath
//
//  Created by Steven Novak on 3/26/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//
//
// --------------------------------------------------
//
//
//
//
//
// --------------------------------------------------

#ifndef BSP_HPP
#define BSP_HPP

#include <vector>

namespace fnMath{

typedef enum
{
    Behind = -1,
    Congruent,
    InFront,
    Divided
} BSPLocation;

typedef struct
{
    float x;
    float y;
    float z;
} Point;

typedef struct
{
    Point p1;
    Point p2;
    Point p3;
} BSPPoly;

typedef struct BSPNode BSPNode;

struct BSPNode
{
    BSPNode* parent;
    BSPNode* front;
    BSPNode* back; 
    BSPPoly poly;
}; 

class BSP 
{
    public:
    // ------------------------- Public Method
    BSP();

    void ConstructTree(std::vector<BSPPoly>* polySet);

    void RecursiveAdd(BSPNode* node, std::vector<BSPPoly>* polySet);
    
    int FindCenter(std::vector<BSPPoly>* polySet);
    
    void DividePoly(BSPPoly* poly,BSPPoly* plane);
    
    bool IsConvexSet(std::vector<BSPPoly>* polySet);

    BSPLocation IsInFront(BSPPoly* target, BSPPoly* divider);
    
    BSPLocation IsInFront(Point* target, BSPPoly* divider);
    
    void Norm(BSPPoly *poly, Point *norm);

    private:
    // ------------------------- Private Members
    BSPNode _root;

    // ------------------------- Private Method

}; // End BSP Class

} // End fnMath Namespace

#endif