#include <iostream> // cout, cerr
#include <fstream> // ifstream
#include <sstream> // stringstream
#include <string.h>
using namespace std;

int main(int argc, char ** argv) {

  if (argc != 4) {
    cout << "Usage: image <input image> <neg image> <rotate image>" << endl;
    exit(1);
  }

  stringstream ss;
  ifstream infile;
  infile.open(argv[1]);

  if (!infile) {
    "Can not open argv for input";
  }

  if (infile.fail()) {
    cout << "Can not open: " << argv[1] << " for input";
    exit(1);
  }

  ss << infile.rdbuf();
  string p2;
  int rows;
  int cols;
  ss >> p2;
  ss >> cols >> rows;

  int greyscale;
  ss >> greyscale;
  greyscale = 255;

  int **arr = new int*[cols];
  int i;
  for (i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }
  for (i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ss >> arr[i][j];
    }
  }

  infile.close();

  ofstream inout;
  inout.open(argv[3]);

  if (inout.fail()) {
    cout << "Failed to open: " << argv[3];
    exit(1);
  }

  int inCols = rows;
  int inRows = cols;
  inout << "P2" << endl << rows << " " << cols << endl << greyscale << endl;

  int **inarr = new int*[cols];
  for (i = 0; i < cols; i++) {
    inarr[i] = new int[rows];
  }

  cout << "arr is an array with \n\twidth: " << cols << "\n\tlenth: " << rows << endl;
  cout << "inarr is an array with \n\twidth: " << rows << "\n\tlenth: " << cols << endl;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      inarr[j][rows - i -1] = arr[i][j];

    }
  }
  for (int i = 0; i < inRows; i++) {
    for (int j = 0; j < inCols; j++) {
      inout << inarr[i][j] << " ";
    }
    inout << endl;
  }

  inout.close();

  //////////////////Negative image below///////////////////////////
  ofstream negOut;
  negOut.open(argv[2]);
  if (negOut.fail()) {
    cout << "Failed to open: " << argv[2];
    exit(1);
  }

  int negCols = cols;
  int negRows = rows;

  negOut << "P2" << endl << cols << " " << rows << endl << greyscale << endl;

  for (i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
       negOut << (greyscale - arr[i][j]) << " ";
    }
    negOut << endl;
  }
  negOut.close();



  // int **inarr = new int*[cols];
  for (int i = 0; i < cols; i++) {
    delete[] inarr[i];
  }

  for (i = 0; i < rows; i++) {
    //delete[] inarr[i];
    delete[] arr[i];
  }

  delete[] inarr;
  delete[] arr;

  return 0;

  ////////////////// NON_SQUARE IMAGE //////////////////////////////////

  // } else {
  //
  //   cout << "Non-Square Image:" << endl;
  //
  //   int greyscale;
  //   ss >> greyscale;
  //   greyscale = 255;
  //
  //   //cout <<  "\t-source arr initialized" << endl; //
  //   int **arr = new int*[cols];
  //   for (int i = 0; i < rows; i++) {
  //     arr[i] = new int[cols];
  //   }
  //
  //
  //
  //           //cout <<  "\t-populating source arr" << endl; //
  //           for (int i = 0; i < rows; i++) {
  //             for (int j = 0; j < cols; j++) {
  //               ss >> arr[i][j];
  //               //cout << arr[i][j];
  //             }
  //           }
  //           infile.close();
  //
  //   // init negative array //
  //   //cout <<  "\t-negative array initialized" << endl; //
  //
  //   int **narr = new int*[cols];
  //
  //   for (int i = 0; i < rows; i++) {
  //     narr[i] = new int[cols];
  //   }
  //
  //           // populate negative array //
  //           //cout <<  "\t-negative array poplulated" << endl; //
  //
  //           for (int i = 0; i < rows; i++) {
  //             for (int j = 0; j < cols; j++) {
  //               narr[i][j] = greyscale - arr[i][j];
  //             }
  //           }
  //
  //   // init rotate array //
  //   //cout <<  "\t-rotate array initialized" << endl; //
  //
  //   int **rarr = new int*[rows];
  //   for (int i = 0; i < rows; i++) {
  //     rarr[i] = new int[cols];
  //   }
  //
  //           // populate rotate array //
  //           //cout <<  "\t-rotate array poplulated" << endl;
  //           //cout << "yeah here";
  //           for (int i = 0; i < rows; i++) {
  //             //cout << "Hello world";
  //             for (int j = 0; j < cols; j++) {
  //               //cout << "-";
  //               rarr[i][j] = greyscale - arr[i][j];
  //             }
  //           }
  //
  //
  //  /////////////////////// non square rotated image below ////////////////////////////
  //
  //            // open rotate file /////////////
  //            //cout <<  "\tOpening:" << argv[3] <<  endl;
  //
  //             ofstream rOut;
  //             //cout << "\tofstream initialized" << endl;
  //
  //             rOut.open(argv[3]);
  //             //cout << "file preliminarily opened\n";
  //             if (rOut.fail()) {
  //               //cout << "Failed to open: " << argv[3] << endl;
  //               exit(1);
  //             }
  //
  //             //cout <<  "\trotate file opened" << endl; //
  //
  //
  //             // roate file opened //////////
  //
  //             rOut << "P2" << endl << rows << " " << cols << endl << greyscale << endl;
  //
  //
  //
  //             for (int i = 0; i < rows; i++) {
  //               for (int j = 0; j < cols; j++) {
  //                 rOut << narr[i][j] << " ";
  //               }
  //               rOut << endl;
  //             }
  //
  //
  //             rOut.close();
  //   //////////////////rotate image above ////////////////////////
  //
  //   //////////////////Negative image below///////////////////////////
  //
  //             // Neg-image file opening //////////////////////
  //             ofstream negOut;
  //             negOut.open(argv[2]);
  //
  //             if (negOut.fail()) {
  //               cout << "Failed to open: " << argv[2];
  //               exit(1);
  //             }
  //
  //             //cout <<  "\n\tneg file opened" << endl; //
  //
  //
  //             // Neg image opened ///////////////////////////
  //
  //             // Insert
  //             negOut << "P2" << endl << rows << " " << cols << endl << greyscale << endl;
  //
  //             for (int i = 0; i < cols; i++) {
  //               for (int j = 0; j < rows; j++) {
  //                  negOut << narr[i][j] << " ";
  //               }
  //               negOut << endl;
  //             }
  //
  //             negOut.close();
  //
  //   // Negative image end ///////////////////////////////////
  //
  //   for (int i = 0; i < rows; i++) {
  //     //delete[] rarr[i];
  //     delete[] narr[i];
  //     delete[] arr[i];
  //   }
  //   for (int i = 0; i < cols; i++) {
  //     delete[] rarr[i];
  //   }
  //   delete[] narr;
  //   delete[] rarr;
  //   delete[] arr;
  //
  //   return 0;
  // }
}
