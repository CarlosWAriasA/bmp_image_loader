/*
 *    BMP Loader written by Raydelto Hernandez  (raydelto@yahoo.com)
 */

#include <cstdio>
#include <string>
#include <iostream>
#include "bmp_reader.h"
using namespace std;

int main(void)
{
    unsigned char *rgbData;
    unsigned char *header;
    unsigned int imageSize;
    unsigned int headerSize;

    // Read the BMP file
    cout << "Reading the BMP file ... " << endl;
    ReadBMP("img/test.bmp", header, rgbData, headerSize, imageSize);

    // Apply grayscale filter
    ApplyGrayFilter(header, rgbData);

    // Flip the image vertically and write the result
    unsigned char *headerVert, *rgbDataVert;
    headerVert = new unsigned char[headerSize];
    rgbDataVert = new unsigned char[imageSize];

    // Copy the original data for vertical flip
    memcpy(headerVert, header, headerSize);
    memcpy(rgbDataVert, rgbData, imageSize);

    cout << "Flipping the image vertically..." << endl;
    FlipVertically(headerVert, rgbDataVert);

    // Write the vertically flipped image to a new BMP file
    cout << "Writing the vertically flipped BMP file..." << endl;
    WriteBMP("img/test_vert_flip.bmp", headerVert, rgbDataVert, headerSize, imageSize);

    // Flip the image horizontally and write the result
    unsigned char *headerHoriz, *rgbDataHoriz;
    headerHoriz = new unsigned char[headerSize];
    rgbDataHoriz = new unsigned char[imageSize];

    // Copy the original data for horizontal flip
    memcpy(headerHoriz, header, headerSize);
    memcpy(rgbDataHoriz, rgbData, imageSize);

    cout << "Flipping the image horizontally..." << endl;
    FlipHorizontally(headerHoriz, rgbDataHoriz);

    // Write the horizontally flipped image to a new BMP file
    cout << "Writing the horizontally flipped BMP file..." << endl;
    WriteBMP("img/test_horiz_flip.bmp", headerHoriz, rgbDataHoriz, headerSize, imageSize);

    // Free the dynamically allocated memory
    cout << "Freeing resources..." << endl;
    delete[] rgbData;
    delete[] header;
    delete[] headerVert;
    delete[] rgbDataVert;
    delete[] headerHoriz;
    delete[] rgbDataHoriz;

    cout << "This application has ended its execution." << endl;
    return 0;
}
