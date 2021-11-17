## Graphics Client TODO list

- [ ] A constructor with two parameters: GraphicsClient( std::string, int ) where the first parameter is the URL to connect, e.g., “localhost” or “lamb.cs.iastate.edu” and the second parameter is the port number to connect

- [ ] A copy constructor that creates a new connection to the same address and port number. 

- [ ] A destructor that performs the appropriate operations to release all allocated resources. 

- [ ] An operator = method that closes the existing connection and creates a new connection with the parameters from the right-hand side.

- [ ] setBackgroundColor( int , int, int ) sets the background color of the associated display.  The parameters are the red, green and then blue values respectively.

- [ ] setDrawingColor( int, int, int ) set the color that objects will be drawn at until another setDrawingColor call is made.  The parameters are again, red, green and blue.  

- [ ] clear() clears the display to the background color.

- [ ] setPixel( int, int, int, int, int ) sets the pixel at the location given by the first two parameters to the color given by the last three parameters.  The first two parameter are the location given by the x and then y coordinate.  The last three parameters are the color given by red, green, and blue in that order.

- [ ] drawRectangle( int, int, int, int ) draws a rectangle at the specified coordinates given by the first two parameters of the specified size given by the last two parameters.  The first two parameters are again the x and y coordinate in that order, and the last two parameters are the width and height, also given in that order.

- [ ] fillRectangle( int, int, int, int ) draws a filled rectangle at the position and size given by the parameters.  The parameters are the same as the drawRectangle parameters. 

- [ ] clearRectangle( int, int, int, int ) clears (sets the pixels to the background color) at the location and size specified by the parameters.  These parameters are the same as the drawRectangle parameters. 

- [ ] drawOval( int, int, int, int ) draws an oval at the specified location inscribed in a rectangle of the specified size.  The parameters are the same as given in drawRectangle. 

- [ ] fillOval(int, int, int, int ) is the same as the drawOval method except the oval is filled. 

- [ ] drawLine( int, int, int,  int ) draws a line starting a point 1 and ending at point 2.  Point 1 is given by the first two parameters, x and y, in that order, and point 2 is given by the last two parameters, x followed by y. 

- [ ] drawstring( int, int, string ) draws a string of characters on the display given by the last parameter at the position given by the first two parameters, x, y, in that order. 

- [ ] repaint() send the redraw (repaint) signal to the attached graphics server. 