import googlemaps
from datetime import datetime
import requests
from PIL import Image
from PIL import ImageDraw
from PIL import ImageFont
import numpy as np
import math as mt
coordinates=""
distance=0
with open("longitude.txt", "r") as f:
	lg= f.readlines()
	f.close()
with open("latitude.txt", "r") as f:
	lt= f.readlines()
	f.close()
lg = [s.replace('\n','') for s in lg]
lt = [s.replace('\n','') for s in lt]
with open("test1.txt", "r") as f:
	la= f.readlines()
	f.close()
la=[s.split(',') for s in la]
with open("teraterm.log", "r") as f:
	la= f.readlines()
	f.close()
la=[s.replace('\n','') for s in la]
la=[s.split(',') for s in la]
for i in range(0,len(la)):
	if i!=0:

		dlat=((float(la[i][0])-float(la[i-1][0]))*3.14)/180
		dlong=((float(la[i][1])-float(la[i-1][1]))*3.14)/180
		lat_previous=(float(la[i-1][0])*3.14)/180;
		lat_current=(float(la[i][0])*3.14)/180;
		a=mt.sin(dlat/2)*mt.sin(dlat/2)+mt.sin(dlong/2)*mt.sin(dlong/2)*mt.cos(lat_previous)*mt.cos(lat_current);
		c=2*mt.atan2(mt.sqrt(a),mt.sqrt(1-a));
		distance=int(distance+(c*6371*1000))
	if i!=(len(la)-1):
		coordinates=coordinates+str(la[i][0])+","+str(la[i][1])+"|"
	else:
		coordinates=coordinates+str(la[i][0])+","+str(la[i][1])

BASE_URL = "https://maps.googleapis.com/maps/api/staticmap?"
API_KEY = "AIzaSyC1fH3L4yEE1fpR3QyqOgDi-Ht2pxzrryU"

# updating the URL
URL = "https://maps.googleapis.com/maps/api/staticmap?path=color:0xff0000ff|weight:5|"+coordinates+"&size=600x300&scale=2&maptype=roadmap&key=AIzaSyC1fH3L4yEE1fpR3QyqOgDi-Ht2pxzrryU&map_id=8f348d1b5a61d4bb"
# HTTP request
response = requests.get(URL)
# storing the response in a file (image)
with open('map.png', 'wb') as file:
   # writing data into the file
   file.write(response.content)
...
distance=str(distance)
img = Image.open("map.png").convert('RGB')
draw=ImageDraw.Draw(img)
myfont = ImageFont.truetype("Verdana.ttf",40)
draw.text((800,500),"distance="+distance+"",fill=(0,0,0),font=myfont)
img.save("hyderabad.png")
img.show()
