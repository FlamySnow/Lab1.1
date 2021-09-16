# The folium of Descartes
> It's an algebraic curve that described by following equation:
x^3 + y^3 = nxy
## Description
1. Function **get_n()** returns a value of parameter *n*.
2. Function **set_n(double n)** lets a user set a value of parameter *n*. Returns a changed example of class.
3. Function **getSide()** returns the side of a square that is equal to the largest chord of the folium.
4. Function **distanceToCenter(double angle)** returns the distance to center in polar coordinate system based on angle.
5. Function **topRadius()** returns the radius of curvature at the top of the folium.
6. Function **nodeRadius()** returns the radius of curvature at the node point.
7. Function **squareOfLoop()** returns the square of the loop of the folium.
8. Function **diameterOfLoop()** returns the length of the largest diameter of the loop.
9. Function **distanceToDiameter()** returns the distance from the node to the largest diameter.

### Note:
* Parameter n must be positive, because it is geometrically a diagonal of square that has side equal to chord of the folium. (*Actually, it can be negative, but I don't like TFCV. Hope you don't either.*)
* Angle in polar coordinates must be in the following interval: [0; 2Pi].