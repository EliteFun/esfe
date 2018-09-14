/*   Random.cpp
 * 
 * Version: 0.1
 * Copyright 2018 - Elite Fun
 * Date: 2018-02-20
 * 
 * Random class implementation.
 * --> see Random.hpp
 */


/******* INCLUDES *******/

// ESFE //
#include "ESFE/Util/Random.hpp"


namespace esfe
{

Random::Random ( ):
mt(time(NULL))
{ }

int Random::randomInt ( int min, int max )
/* Generate a random int between 'min' and 'max'
*/
{
    std::uniform_int_distribution<int> dist( min, max );
    return dist( mt );
}

double Random::randomDouble ( double min, double max )
/* Generate a random double between 'min' and 'max'
*/
{
    std::uniform_real_distribution<double> dist( min, max );
    return dist( mt );
}

float Random::randomFloat ( float min, float max )
/* Generate a random float between 'min' and 'max'
*/
{
    std::uniform_real_distribution<float> dist( min, max );
    return dist( mt );
}

}  // namespace esfe
