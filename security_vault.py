import cv2
import numpy as np
import serial
import time
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')
ser = serial.Serial('COM9', 9600, timeout=0)
isopen=cv2.VideoCapture(0)
rec=cv2.face.LBPHFaceRecognizer_create()
rec.read('trainer/trainer.yml')
t=0
count=0
# id=[0,1]
while(isopen.isOpened()):
  for t in range(0,30):
    ret, img=isopen.read()
    
    gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    faces = face_cascade.detectMultiScale(gray,1.3,5)
    for(x,y,w,h) in faces:
      cv2.imshow('img',img)
      id,conf=rec.predict(gray[y:y+h,x:x+w])
      print (id)
      if (id==0 or id==1):
        cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)
        roi_gray = gray[y:y+h,x:x+w]
        count=count+0.035
        # if count>=1 :
        #   time.sleep(1)
        #   ser.write('H')
        # else:
        #   time.sleep(1)
        #   ser.write(b'L')
        # time.sleep(1)
        ser.write(b'H')
        time.sleep(1)
        ser.write(b'L')
      # else:
      #   time.sleep(1)
      #   ser.write(b'L')
          
      cv2.imshow('img',img)                   
  count=0     
    
  if cv2.waitKey(10) & 0xFF == ord('q'):
    isopen.release()
    cv2.destroyAllWindows()
