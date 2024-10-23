/**
 * Graphics.cpp
 * Project UID 2e6ea4e086ea6a06753e819c30923369
 *
 * EECS 183
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

#include "Graphics.h"
#include "bmp.h"

using namespace std;

class Graphics
{
public:

    
    Graphics() {
        for (int i = 0; i < DIMENSION; i++) {
            for (int j = 0; j < DIMENSION; j++) {
                pixelData[i][j] = 
            }
        }
    }

    /**
     * Requires: Nothing.
     * Modifies: pixelData.
     * Effects:  Sets all pixels to black.
     * Note: you will want to implement the private
     *  member function initArray before implementing
     *  clear()
     */
    void clear();

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Writes the BMP file to filename.
     */
    void writeFile(string fileName) const;

    /**
     * Requires: color is a valid Color
     * Modifies: pixelData.
     * Effects:  Sets the pixel at (x, y) to color
     *      if it is within the bounds.
     *      See the specification for how pixels are stored.
     */
    void setPixel(int x, int y, Color color);

private:
    /**
     * Requires: Nothing.
     * Modifies: pixelData.
     * Effects:  Initializes all pixels in pixelData to black.
     */
    void initArray();

    // Holds the color in the pixels
    Color pixelData[DIMENSION][DIMENSION];
};

// Your code goes above this line.
// Don't change the implementation below!

void Graphics::writeFile(string fileName) const
{
    ofstream outFile;
    outFile.open(fileName, ios::binary);

    // determine padding
    int padding = (4 - (DIMENSION * 3) % 4) % 4;

    // BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    bf.bfType = 0x4d42; // type of file = bitmap
    bf.bfSize = DIMENSION * (DIMENSION + padding) * 3 + 54; // TODO
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = 54; // location of pixels

    // BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    bi.biSize = 40; // header size
    bi.biWidth = DIMENSION;
    bi.biHeight = -DIMENSION;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = 0;
    bi.biSizeImage = bi.biWidth * bi.biHeight * 3;
    bi.biXPelsPerMeter = 2834;
    bi.biYPelsPerMeter = 2834;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    // write output BITMAPFILEHEADER
    outFile.write((char*)&bf, sizeof(BITMAPFILEHEADER));

    // write output BITMAPINFOHEADER
    outFile.write((char*)&bi, sizeof(BITMAPINFOHEADER));

    // iterate over lines
    for (int i = 0; i < DIMENSION; i++)
    {
        // iterate over pixels in line
        for (int j = 0; j < DIMENSION; j++)
        {
            // temporary storage
            Color pixel = pixelData[i][j];

            // write RGB triple to outfile
            outFile << (BYTE)pixel.getBlue() << (BYTE)pixel.getGreen()
                << (BYTE)pixel.getRed();
        }

        // write padding to outfile
        for (int k = 0; k < padding; k++)
        {
            outFile << 0;
        }
    }

    // close file
    outFile.close();
}
