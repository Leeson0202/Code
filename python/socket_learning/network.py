from pygeocoder import Geocoder

address = '207 N.Defiance St,Archbold, OH'
print(Geocoder.geocode(address)[0].corrdinates)