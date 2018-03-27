//
//  MetropolisHastings.cpp
//  fnMath
//
//  Created by Steven Novak on 03/05/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#include "MetropolisHastings.hpp"

namespace fnMath{
namespace Stats{

#pragma mark Public Methods
// ---------------------------------------- Public Methods

MetropolisHastings::MetropolisHastings()
{
    _function = nullptr;
    _x = _rng.GenerateDouble();
}

MetropolisHastings::MetropolisHastings(Function* f)
{
    _function = f;
    _x = _rng.GenerateDouble();
}

void MetropolisHastings::BurnIn(int iterations)
{
    if(_function == nullptr)
        return;

    _v = _function->Evaluate(_rng.GenerateDouble());
    for(int i=0; i<iterations; i++)
        this->GetNext();
}

double MetropolisHastings::GetNext()
{
    double value, x, xp, u=1, a=0;

    _v = _function->Evaluate(_x);

    while(a < u)
    {
        _rng.GenerateNormals(_x, 1, &x, &xp);
        u = _rng.GenerateDouble();

        value = _function->Evaluate(x);
        a = value / _v;
    }
    _x = x;
    _v = value;
    return x;
}

#pragma mark Accessors
// ---------------------------------------- Accessors


#pragma mark Private Methods
// ---------------------------------------- Private Methods

} // End Stats NameSpace
} // End fnMath NameSpace
