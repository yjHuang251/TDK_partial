## project setting
if you have a different project name, change it at **.project** and **.cproject**
## description
* set a clock with 1000Hz for localization and navigation
* define an array to store distances
* follow the drama first, if error ocurrs then hit the wall (haven't finished)
* when it's time to do mission, send message to Arduino and stop localizing and navigating
* coordinate system based on the chassis
## detail
```
timer callback:
   ｜
   \/
 ->v,w-->localization: calculate current pose and get line following data--
｜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　|
Ｌnavigation: speed control and offset correction<-distance, theta<--------

```