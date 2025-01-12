#include "header.h"

// TODO: map pixel 'x' to real part for Mandelbrot set
double map_x_to_real(int x, int imgW, double centerX, double zoomFactor) {
    double planeW = 3.0 / zoomFactor;  // Complex plane width scaled by zoomFactor
    return centerX - (planeW / 2) + ((double)x / imgW) * planeW;
}

// TODO: map pixel 'y' to imaginary part for Mandelbrot set
double map_y_to_imaginary(int y, int imgH, double centerY, double zoomFactor) {
    double planeH = 2.0 / zoomFactor;  // Complex plane height scaled by zoomFactor
    return centerY + (planeH / 2) - ((double)y / imgH) * planeH;
}

// TODO: map pixel 'x' to real part for Julia set
double map_x_to_real_julia(int x, int imgW) {
    return -2.0 + ((double)x / imgW) * 4.0;  // Fixed range from -2 to 2
}

// TODO: map pixel 'y' to imaginary part for Julia set
double map_y_to_imaginary_julia(int y, int imgH) {
    return 1.5 - ((double)y / imgH) * 3.0;  // Fixed range from 1.5 to -1.5
}



// TODO: generate Julia set fractal image in PPM format
void generateFractalImageJulia(double ReC, double ImC, int maxIterations, int imgW, int imgH) {
    
    printf("P3\n%d %d\n255\n", imgW, imgH);

    // Loop through each pixel in the image
    for (int y = 0; y < imgH; ++y) {
        for (int x = 0; x < imgW; ++x) {
            
            double ReZ = map_x_to_real_julia(x, imgW);
            double ImZ = map_y_to_imaginary_julia(y, imgH);

            
            int iterations = recursiveFractalSeq(ReC, ImC, ReZ, ImZ, 0, maxIterations);

            
            double alpha = (double)iterations / maxIterations;

           
            int r, g, b;
            if (iterations == maxIterations) {
                r = g = b = 255;
            } else {
                r = (int)(alpha * 0);    
                g = (int)(alpha * 255);  
                b = (int)(alpha * 153);  
            }

            
            printf("%d %d %d ", r, g, b);
        }
        printf("\n"); 
    }
}
