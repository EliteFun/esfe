/*   Random.hpp
 * 
 * Version: alpha 0.1
 * Copyright 2018 - Elite Fun
 * Date: 2018-02-20
 * 
 * Random class declaration. Can
 * generate random ints, floats,
 * or doubles
 */


#pragma once

/*** HEADERS ***/

#include <random>
#include <time.h>


namespace esfe
{
    
class Random
{
public:
    
    /** \brief Constructor
     * 
     * Seed the mersenne twister with
     * the current time
     */
    Random  ( );

    /** \brief Generate a random int
     * 
     * \arg min: minimum number
     * \arg max: maximum number
     * \return generated number (int)
     * 
     * Generate a random int between
     * min and max.
     */
    int    randomInt    ( int min = 0,      int max = 10      );
    
    /** \brief generate a random double
     * 
     * \arg min minimum number
     * \arg max maximum number
     * \return generated number (double)
     * 
     * Generate a random double between
     * min and max.
     */
    double randomDouble ( double min = 0.0, double max = 10.0 );
    
    /** \brief generate a random float
     * 
     * \arg min: minimum number
     * \arg max: maximum number
     * \return generated number (float)
     * 
     * Generate a random float between
     * min and max.
     */
    float  randomFloat  ( float min = 0.0f, float max = 10.0f );

private:
    
    std::mt19937       mt; ///< mersenne twister
};

}  // namespace esfe
