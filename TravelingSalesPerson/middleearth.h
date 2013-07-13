//Venkata-Gautam Kanumuru, vrk7bp, middleearth.h, April 22nd, 2013

//Provided for both the In-Lab and the Post-Lab, only doxygen comments were added.

#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
  int num_city_names, xsize, ysize;
  vector<float> xpos, ypos;
  /** @brief Vector holding all the cities in the Lord of the Rings world.
   */
  vector<string> cities;
  float *distances;
  map<string, int> indices;
  
public:

 /** @brief The middle earth constructor
 *
 * Creates the necessary MiddleEarth world based upon
 * the specifications given by the parameters.
 * @return Nothing, creates a MiddleEarth object.
 * @param xsize The width (should be specified to 20)
 * @param ysize The height (should be specified to 20)
 * @param numcities The amount of cities
 * @param seed A random seed that specifies the instance generated.
 * @remarks This method/class is provided as part of the Pre-Lab. Its primary job is to provide a random world in which the brute force traveling salesperson solution can be applied.
 * @attention This method and class were provided by Professor Aaron Bloomfield
 */

  MiddleEarth (int xsize, int ysize, int numcities, int seed);

 /** @brief Destructor
 *
 * Returns any resources previously allocated to the MiddleEarth Object.
 * @return Void
 * @remarks This method/class is provided as part of the Pre-Lab. It has the same function as a typical.
 * @attention This method and class were provided by Professor Aaron Bloomfield
 */

  ~MiddleEarth();

 /** @brief Prints out the statistics of the world.
 *
 * This function prints out the amount of cities and their respective sizes. It then
 * goes through and prints out each of the cities.
 * @return Void
 * @remarks This method/class is provided as part of the Pre-Lab. It prints out all of the cities and specs that are being dealt with, a good method for debugging.
 * @attention This method and class were provided by Professor Aaron Bloomfield
 */

  void print();

 /** @brief Prints out a table of the distances between all of the cities.
 *
 * It will be necessary to open this file in Open Office, and is 
 * helpful for debugging.
 * @return Void
 * @remarks This method/class is provided as part of the Pre-Lab. This method "exports" a file that can be read by Open Office and denotes the distance between all the cities.
 * @attention This method and class were provided by Professor Aaron Bloomfield
 */

  void printTable();

 /** @brief Returns the distance between two specified cities.
 *
 * Given any two cities that are within the city field, this method
 * returns the distance between the two in a float value.
 * @return A float representing the distance between two cities.
 * @param city1 The first city
 * @param city2 The second city
 * @remarks This method/class is provided as part of the Pre-Lab. This is a helpful "helper" method for retrieving the weights of each path. This will be used in the traveling
 * sales person algorithm.
 * @attention This method and class were provided by Professor Aaron Bloomfield
 */

  float getDistance (string city1, string city2);

 /** @brief Returns a vector of cities that must be visited
 *
 * Given a length passed into the method, 
 * goes through and prints out each of the cities that have to be reached.
 * @return vector<string> holding all the cities that have to be reached.
 * @param length representing the amount of cities that want to be reached.
 * @remarks This method/class is provided as part of the Pre-Lab. This method is used for generating the cities that can be reached.
 * @attention This method and class were provided by Professor Aaron Bloomfield
 */

  vector<string> getItinerary(unsigned int length);
};

#endif
