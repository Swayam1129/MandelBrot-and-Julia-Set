#include <stdio.h>
#include <stdlib.h>

int imageH = 720;

int recursiveFractalSeq(double ReC, double ImC, double ReZ, double ImZ, int depth, int maxIterations);


int recursiveFractalSeq(double ReC, double ImC, double ReZ, double ImZ, int depth, int maxIterations){
    //for Mandelbrot Set
    //Zn+1 = (Zn)^2 + c
    //c = Zn+1 - (Zn)^2
    //Plot all values of c  that cause Zn to diverge with a fixed Zo = 0 , where c is mapped to a pixel in a image

    // Calculate the square of the magnitude (|z|^2 = ReZ^2 + ImZ^2)
    if(depth>=maxIterations){
        return maxIterations;
    }

    // Calculate the square of the magnitude (|z|^2 = ReZ^2 + ImZ^2)
    double MagSquared = (ReZ*ReZ) + (ImZ*ImZ);

    // If |z|^2 > 4, it has diverged
    if (MagSquared > 4){
        return depth;

    }

    double newReZ = (ReZ*ReZ) - (ImZ*ImZ) + ReC; // Rea Part of Zn^2+c
    double newImZ = (2.0*ReZ*ImZ) + ImC;// Imaginary Part of Zn^2+c

    return recursiveFractalSeq(ReC,ImC,newReZ,newImZ,depth+1,maxIterations);
}
