#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream

using namespace std;

int main(int argc, char ** argv) {

  cout << "Checking Files..." << endl << "\t";
  if (argc != 4) {
    cout << "Usage: image <input image> <neg image> <rotate image>" << endl;
    exit(1);
  } else {
    for (int i = 0; i < argc; i++)
      cout << "File " << i << ": " << argv[i] << endl << "\t";
  }


  int rows = 0;
  int cols = 0;

  ifstream infile(argv[1]);
  stringstream ss;
  string inputLine = "";


  getline(infile, inputLine);

  if (inputLine.compare("P2") != 0) {
    cerr << "Version error" << endl;
  } else {
    cout << "Version : " << inputLine << endl;
  }


  // Continue with a stringstream
  ss << infile.rdbuf();
  // Third line : size
  ss >> cols;
  ss >> rows;

  cout << cols << " columns and " << rows << " rows" << endl;

  int array[rows][cols];

  // setup for negImage
  ofstream negImage;
  negImage.open(argv[3]);

  if (negImage.fail()) {
    cout << "Failed to open negImage: line 55\n";
    exit(1);
  }

  cout << "Making negative image..." << endl;
  negImage << "P2" << endl << rows << " " << cols << endl << 255 << endl;

  // Second line : comment
  //getline(infile , inputLine);
  //cout << "Comment : " << inputLine << endl;
  int val = 256;
  ss >> val;
  cout << "rgb val: " << val << endl;



  // Following lines : data
  for(int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      // store value in array
      ss >> array[rows][cols];
    }
  }
  cout << "image successfully converted to array" << endl;

  for(int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      // array -> negImage
      int negVal = val - array[i][j];
      if (negVal < 0) {
        negImage << 0 << " ";
        cout << "\tSubtraction error" << endl;
      } else {
        negImage << negVal << " ";
      }
    }
  }





  // Now print the array to see the result
  // for(row = 0; row < numrows; ++row) {
  //   for(col = 0; col < numcols; ++col) {
  //     cout << array[row][col] << " ";
  //   }
  //   cout << endl;
  // }



  negImage.close();
  infile.close();

}
