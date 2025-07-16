# Ray-tracing - Computer Graphics
My solution to Games101 exercise 5

# My main tasks
1. Corrected the mistake in the original castRay code in the REFLECTION case
2. Implement Moller Trumbore Algorithm to detect the nearest intersection between ray and triangle.
3. Calculate correct coordinates of the pixels on the image screen to compute a correct direction vector.

# Result
<img width="750" height="453" alt="Screenshot from 2025-07-13 19-24-59" src="https://github.com/user-attachments/assets/96d2ec7b-c094-4c93-b032-c64fdcdf1bc5" />

# Moreover, I corrected the mistake in the original Reflection code
## Before (reflective ball was completely black, under shadow)
<img width="550" height="448" alt="Screenshot from 2025-07-13 18-56-34" src="https://github.com/user-attachments/assets/04fd4ab5-f3b9-4e9d-8355-b6ac5acf72b6" />

## After (reflective ball is correctly reflecting lights)
<img width="750" height="453" alt="Screenshot from 2025-07-13 19-24-59" src="https://github.com/user-attachments/assets/96d2ec7b-c094-4c93-b032-c64fdcdf1bc5" />

# Explanation
1. In the original code, there were two mistakes. In REFLECTION case, the vector used to determine the ray origin offset was not correct. This mistake made it has self-intersection in the REFLECTION case, making it completely black in color. Another mistake was subtle,
   but the hitPoint was used as the start of the light direction instead of the shadowPointOrig, which offset was performed on
3. For direction vector, it has to be normalized. I tried removing the normalization, which affected the refraction the most. It didn't affect the phong shading part much, probably because phong shading will make sure the incident ray is normalized anyway. 
However, for calculation like refraction, if I don't normalize the directional vector (x, y, -1), the magnitude is smaller in the middle than the side of the screen, which will cause distortion in the t detected. 
4. If I don't do tnear > 0 check in the moller trumbore algorithm, when shadow ray tries to detect whether any triangle is blocking its path to the light source, it'll almost always think something is blocking it because the intersection checking function
returns "true". Therefore, the intersection checking function needs to make sure the triangle is actually creating a shadow by checking tnear > 0. Otherwise, the result will be completely black, as shown below.
5. I can also check whether determinant is near 0 in Moller Trumbore, to make sure the solution is a valid one. Because the light can be parallel to the triangle (although it rarely happens), or there might be no intersection.

## If the intersection checking function returns true even if tnear > 0, it'll cast shadow everywhere. 
<img width="400" height="188" alt="image" src="https://github.com/user-attachments/assets/1ac29aba-a54f-49a1-90d1-3d52d7aa7c7e" />

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
