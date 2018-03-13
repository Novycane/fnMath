//
//  MetropolisHastings.hpp
//  fnMath
//
//  Created by Steven Novak on 03/12/2018.
//  Copyright © 2018 Steven Novak. All rights reserved.
//

#ifndef METROPOLISHASTINGS_HPP
#define METROPOLISHASTINGS_HPP

#include "Random.hpp"
#include "../Function.hpp"

namespace fnMath{
namespace Stats{

class MetropolisHastings
{
public:
    MetropolisHastings();
    MetropolisHastings(Function* f);

    void BurnIn(int iterations);
    double GetNext();

private:
    double _v;
    RandomNumber _rng;
    Function* _function;

};  // End MetropolisHastings Class

} // End Stats Namespace
} // End fnMath Namespace

#endif