#include <fstream>
#include <iostream>
#include "animal_reference.h" /* need to include the animal header file we generated */

using namespace std;
namespace ak = awkward;

int main() {

  cout << "initiate sequence"<< endl; 

  /* Open the input file in binary mode */
  //ifstream infile("../../../data/animal_raw", ifstream::binary);
  ifstream infile("/home/josh/dev/awkward-kaitai/dataReaderWriter/data/animal_raw", ifstream::binary);

  cout << "In-file check" << endl;

  /* Create a kaitai stream of the source file */
  kaitai::kstream ks(&infile);

  cout << "kaitai stream check" << endl;

  /* Get a pointer to the array containing all the animals */
  ak::ArrayBuilder animal_array = read_animal(&ks);

  cout << "awkward array check" << endl;

  // take a snapshot
  shared_ptr<ak::Content> array = animal_array.snapshot();
 
  cout << array.get()-> tojson(false,1);
}
