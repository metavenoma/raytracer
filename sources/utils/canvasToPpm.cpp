#include "raytracer.h"

void canvasToPpm(Canvas c)
{
    std::ofstream ppm("canvas.ppm");
    if (!ppm.is_open())
    {
        std::cerr << "File cannot be created" << std::endl;
        return;
    }

    // Write PPM header
    ppm << "P3" << std::endl;
    ppm << c.width() << " " << c.height() << std::endl;
    ppm << "255" << std::endl;

    // Loop through each pixel in the canvas
    for (int i = 0; i < c.height(); i++)
    {
        int lineLength = 0;  // Track length of the current line
        for (int j = 0; j < c.width(); j++)
        {
            // Retrieve the pixel color using getIntValue for each color component
            Color pixel = c.pixelAt(i, j);
            int r = c.getIntValue(pixel.r());
            int g = c.getIntValue(pixel.g());
            int b = c.getIntValue(pixel.b());

            // Format the pixel string
            std::string pixelStr = std::to_string(r) + " " + std::to_string(g) + " " + std::to_string(b);

            // Check if adding this pixel would exceed 70 characters, and if so, start a new line
            if (lineLength + pixelStr.size() > 70)
            {
                ppm << std::endl;  // Start a new line if it exceeds 70 characters
                lineLength = 0;
            }

            // Write the pixel value to the file
            ppm << pixelStr;
            lineLength += pixelStr.size();

            // Add a space between pixels, but not at the end of the line
            if (j < c.width() - 1)
            {
                ppm << " ";
                lineLength++; // Add 1 to lineLength for the space
            }
        }
        ppm << std::endl;  // End the current line of pixels
    }

    ppm.close();
}

