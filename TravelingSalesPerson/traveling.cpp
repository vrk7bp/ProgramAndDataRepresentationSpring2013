//Venkata-Gautam Kanumuru, vrk7bp, traveling.cpp, April 22nd, 2013

//Manipulated from traveling-skeleton.cpp that is provided in the In-Lab

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#include "middleearth.h"

 /** @brief Computes the total distance of path
 *
 * Given a predetermined path, the method returns the summation
 * of the individual paths between the nodes in the order given.
 * @return Float holding the total distance
 * @param me The MiddleEarth Object
 * @param start A string holding the starting (and ending) city
 * @param dests A vector<string> holding the path traveled
 * @remarks This method is used in combination with the next_permutation() method to find the minimum path.
 * By physically calculating each permutaion and finding the distance, we can (in a brute force manner) find the minimum path.
 */

float computeDistance (MiddleEarth &me, string start, vector<string> dests);


 /** @brief Prints out the path
 *
 * Given a predetermined path, the method prints out the path in order.
 * @return Void
 * @param start A string holding the starting (and ending) city
 * @param dests A vector<string> holding the path traveled
 * @remarks This method is used for more debugging, in order to make sure that the right permutations are being printed out.
 */

void printRoute (string start, vector<string> dests);


 /** @brief The main method
 *
 * This is the main method that runs the entire program. 
 * @return Int denoting whether the run was valid or if an error occurred.
 * @param argc[1] x-size (width)
 * @param argc[2] y-size (height)
 * @param argc[3] number of cities in the world
 * @param argc[4] The random seed (denotes what instance of the world you want, input -1 for random).
 * @param argc[5] The number of cities to visit (the length of path, not including the starting and ending city);
 * @remark The main uses both the middleearth.cpp class as well as the printRoute and computeDistances methods to find the shoretest path in a brute force manner.
 * How long this program takes to run is determined by the last parameter because the amount of permutations possible is n!, with n being the last parameter.
 * The beginning of this code is based upon the traveling-skeleton.cpp that is provided in the In-Lab.
 * @remark The parameters for this method come from the command prompt, and should be input with the start of the program (./a.out ...)/
 */


int main (int argc, char **argv) {
  // check the number of parameters
  if ( argc != 6 ) {
    cout << "Usage: " << argv[0] << " <world_height> <world_width> "
	 << "<num_cities> <random_seed> <cities_to_visit>" << endl;
    exit(0);
  }
  // we'll assume the parameters are all well-formed
  int width, height, num_cities, rand_seed, cities_to_visit;
  sscanf (argv[1], "%d", &width);
  sscanf (argv[2], "%d", &height);
  sscanf (argv[3], "%d", &num_cities);
  sscanf (argv[4], "%d", &rand_seed);
  sscanf (argv[5], "%d", &cities_to_visit);

  // Create the world, and select your itinerary
  MiddleEarth me(width, height, num_cities, rand_seed);
  vector<string> dests = me.getItinerary(cities_to_visit);

  string start = dests[0];

  float trackerValue = computeDistance(me, start, dests);
  vector<string> trackVector = dests;
  //cout << sizeof(trackVector);

  do {
    for(int x = 0; x < dests.size(); x++) {
      float interVal = computeDistance(me, start, dests);
      if(interVal < trackerValue) {
	trackerValue = interVal;
	trackVector.clear();
	trackVector = dests;
      }
    }
  } while(std::next_permutation(++dests.begin(), dests.end()));

  cout << "Minimum path has distance of " << trackerValue << ": ";
  printRoute(start, trackVector);

  //cout << sizeof(trackVector);

  return 0;
}

// This method will compute the full distance of the cycle that starts
// at the 'start' parmater, goes to each of the cities in the dests
// vector IN ORDER, and ends back at the 'start' parameter.
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
  string city1;
  string city2;

  city2 = start;

  float distanceTracker = 0;
  for(int x = dests.size()-1; x >= 0; x--) {
    city1 = dests[x];
    distanceTracker += me.getDistance(city1, city2);
    city2 = city1;
  }

  return distanceTracker;
}

// This method will print the entire route, starting and ending at the
// 'start' parameter.  The output should be of the form:
// Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
void printRoute (string start, vector<string> dests) {
  for(int x = 0; x < dests.size(); x++) {
    cout << dests[x] << " -> ";
  }
  cout << start << endl;
}
