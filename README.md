# CLI PPM Image Editor

Ever thought Paint was too easy? No u haven't? Well i got great news, using this tool u can draw by typing in commands, how will it look like? U won't know till u save it.

Commands:

new       w h              = create new image with width and height  

save      filename         = save image with filename  

circle    x y radius = draw circle at x y with radius 

rectangle x y w h    = draw rectangle at x y with width and height  

pixel     x y       = draw pixel at x y  

color r g b = set color to use with values r g b

U can also use the first letter of the command, examples:  

pixel 50 50 255 124 62  
p 50 50 255 124 62

When commands share the same name, the command that draws has priority:

c 50 50 10 will draw circle  
co 255 0 0 will set color
