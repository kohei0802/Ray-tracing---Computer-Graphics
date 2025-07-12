# Ray-tracing - Computer Graphics
My solution to Games101 HW5. 

Almost all the codes in this HW are provided by the teaching team, starting with Prof. Lingqi Yan.

# My main tasks
1. Implement Moller Trumbore Algorithm to detect the nearest intersection between ray and triangle.
2. Calculate correct coordinates of the pixels on the image screen to compute a correct direction vector.

# Result
<img width="908" height="429" alt="image" src="https://github.com/user-attachments/assets/91175cd7-f964-4e3b-95ce-5120a8d7279a" />

# Explanation
1. For direction vector, it has to be normalized. I tried removing the normalization, which affected the refraction the most. It didn't affect the phong shading part much, probably because phong shading will make sure the incident ray is normalized anyway. 
However, for calculation like refraction, if I don't normalize the directional vector (x, y, -1), the magnitude is smaller in the middle than the side of the screen, which will cause distortion in the t detected. 
2. If I don't do tnear > 0 check in the moller trumbore algorithm, when shadow ray tries to detect whether any triangle is blocking its path to the light source, it'll almost always think something is blocking it because the intersection checking function
returns "true". Therefore, the intersection checking function needs to make sure the triangle is actually creating a shadow by checking tnear > 0. Otherwise, the result will be completely black, as shown below.
3. I can also check whether determinant is near 0 in Moller Trumbore, to make sure the solution is a valid one. Because the light can be parallel to the triangle (although it rarely happens), or there might be no intersection.

## If the intersection checking function returns true even if tnear > 0, it'll cast shadow everywhere. 
<img width="908" height="429" alt="image" src="https://github.com/user-attachments/assets/1ac29aba-a54f-49a1-90d1-3d52d7aa7c7e" />

# Prerequisites
You need OpenCV to build this project. 
If you're on Ubuntu, run 
1. sudo apt install libopencv-dev

# Build
then, go into ./build/ directory or create one if it's not there and run
1. cmake ..
2. make

# Run (How to use the program?)
1. ./Raytracing
2. You'll see an image "binary.ppm" to see the result of the ray tracing.

Codes for this HW are mostly provided by Games 101 teaching team. 
