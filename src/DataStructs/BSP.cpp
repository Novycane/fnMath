//
//  BSP.cpp
//  fnMath
//
//  Created by Steven Novak on 3/26/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#include "BSP.hpp"

#include <iostream>

namespace fnMath
{
    // --------------------------------------------------
    // ----- Constructors
    BSP::BSP()
    {
        _root.parent = nullptr;
        _root.front = nullptr;
        _root.back = nullptr;
    }

    // --------------------------------------------------
    // ----- Public Methods

    void BSP::ConstructTree(std::vector<BSPPoly>* polySet)
    {
        RecursiveAdd(&_root, polySet);
    }

    // --------------------------------------------------
    // ----- Private Methods

    void BSP::RecursiveAdd(BSPNode* node, std::vector<BSPPoly>* polySet)
    {
        std::vector<BSPPoly>* frontSet;
        std::vector<BSPPoly>* backSet;

        if(IsConvexSet(polySet))
        {
            return;
        }

        node->poly = (*polySet)[FindCenter(polySet)];

        frontSet = new std::vector<BSPPoly>();
        backSet = new std::vector<BSPPoly>();
        
        for(int i=0; i<polySet->size(); i++)
        {
            BSPLocation location = IsInFront(&(*polySet)[i] , &node->poly);
            if(location == InFront || location == Congruent)
                frontSet->push_back((*polySet)[i]);
            else if (location == Behind)
                backSet->push_back((*polySet)[i]);
            else
            {
                DividePoly(&(*polySet)[i] , &node->poly, frontSet, backSet);
            }
        }

        BSPNode* frontNode = new BSPNode();
        BSPNode* backNode = new BSPNode();

        frontNode->parent = backNode->parent = node;
        node->front = frontNode;
        node->back = backNode;

        RecursiveAdd(frontNode, frontSet);
        RecursiveAdd(backNode, backSet);
    }

    void BSP::DividePoly(BSPPoly* poly, BSPPoly* plane, std::vector<BSPPoly>* front, std::vector<BSPPoly>* back)
    {
        std::vector<Point> f, b;

        // calculate points on front and back of plane
        if(IsInFront(&poly->p1, plane) == InFront)
            f.push_back(poly->p1);
        else
            b.push_back(poly->p1);

        if(IsInFront(&poly->p2, plane) == InFront)
            f.push_back(poly->p1);
        else
            b.push_back(poly->p1);

        if(IsInFront(&poly->p3, plane) == InFront)
            f.push_back(poly->p1);
        else
            b.push_back(poly->p1);
            
        std::cout << f.size() << " " << b.size() << std::endl;
        // are two points infront or behind plane?
        if(f.size() == 2)
        {
            // -- calculate first intersection
        }
        else
        {
            // -- calculate second intersection
        }
        
        // Create triangle from two new points to single point
        // Create triangle from two old points to one new point
        // Create Triangle From two old points to second new point
    }

    bool BSP::IsConvexSet(std::vector<BSPPoly>* polySet)
    {
        for(int i = 0; i < polySet->size(); i++)
        {
            BSPPoly pi = (*polySet)[i];
            for(int j = 0; j<polySet->size(); j++)
            {
                if(i != j)
                {
                    BSPPoly pj = (*polySet)[j];
                    BSPLocation location = IsInFront(&pi, &pj);
                    if(location == Behind || location == Divided)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    int BSP::FindCenter(std::vector<BSPPoly>* polySet)
    {
        int center = 0;
        int index, front, back;
        int diff = polySet->size();

        unsigned int* num = (unsigned int*) polySet;

        srand(*num);

        for(int j=0; j<5; j++)
        {
            front = back = 0;
            index = rand() % polySet->size();
            BSPPoly* target = &(*polySet)[index];

            for(int i=0; i < polySet->size(); i++)
            {
                BSPLocation location = IsInFront(&(*polySet)[i] ,target);
                if(location == InFront)
                    front++;
                if(location == Congruent)
                    back++;
                if(location == Behind)
                    back++;
            }

            int newDiff = abs(front - back);
            if(newDiff < diff)
            {
                diff = newDiff;
                center = index;
            }
        }

        return center;
    }

    BSPLocation BSP::IsInFront(Point* target, BSPPoly* divider)
    {
        // ----- Should I put this in a function?
        Point normD;
        float dot;
        Norm(divider, &normD);
        dot = target->x * normD.x + target->y * normD.y + target->z * normD.z;
        
        if(dot < 0)
            return Behind;
        if(dot == 0)
            return Congruent;
        else
            return InFront;
    }

    BSPLocation BSP::IsInFront(BSPPoly* target, BSPPoly* divider)
    {
        int numInFront = 0;
        
        numInFront += IsInFront(&target->p1, divider);
        numInFront += IsInFront(&target->p2, divider);            
        numInFront += IsInFront(&target->p3, divider);

        if(numInFront == 0)
            return Congruent;
        else if(numInFront == 3)
            return InFront;
        else if(numInFront == -3)
            return Behind;
        else
            return Divided;
    }

    void BSP::Norm(BSPPoly *poly, Point *norm )
    {
        Point U;
        Point V;

        U.x = poly->p2.x - poly->p1.x;
        U.y = poly->p2.y - poly->p1.y;
        U.z = poly->p2.z - poly->p1.z;        

        V.x = poly->p3.x - poly->p1.x;
        V.y = poly->p3.y - poly->p1.y;
        V.z = poly->p3.z - poly->p1.z;

        norm->x = U.y * V.z - U.z * V.y;
        norm->y = U.z * V.x - U.x * V.z;
        norm->z = U.x * V.y - U.y * V.x;

        float sum = norm->x * norm->x;
        sum += norm->y * norm->y;
        sum += norm->z * norm->z;
        sum = sqrt(sum);

        norm->x /= sum;
        norm->y /= sum;
        norm->z /= sum;
    }


} // End Name Space 