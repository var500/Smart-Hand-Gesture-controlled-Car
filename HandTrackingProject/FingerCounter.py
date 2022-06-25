import cv2
import time
import os
import HandTrackingModule as htm
# import urllib.request
# import http
import esp_python as ep

base = "http://<ip address of NodeMCU>/"

wCam, hCam = 840, 680

cap = cv2.VideoCapture(0)
cap.set(3, wCam)
cap.set(4, hCam)

folderPath = "FingerImages"
myList = os.listdir(folderPath)
overlayList = []
for imPath in myList:
    image = cv2.imread(f'{folderPath}/{imPath}')
    overlayList.append(image)

detector = htm.handDetector(detectionCon=0.75)

tipIds = [4, 8, 12, 16, 20]

while True:
    success, img = cap.read()
    img = detector.findHands(img)
    lmList = detector.findPosition(img, draw=False)

    if len(lmList) != 0:

        fingers = []
        # thumb
        if lmList[tipIds[0]][1] > lmList[tipIds[0] - 1][1]:
            fingers.append(1)
        else:
            fingers.append(0)

        # four fingers
        for id in range(1, 5):
            if lmList[tipIds[id]][2] < lmList[tipIds[id] - 2][2]:
                fingers.append(1)
            else:
                fingers.append(0)

        # print(fingers)

        totalFingers = fingers.count(1)
        # print(totalFingers)
        if totalFingers == 1:
            print("Moving Forward")
            ep.transfer("Forward")
        elif totalFingers == 2:
            print("Forward Left")
            ep.transfer("Left")
        elif totalFingers == 3:
            print("Forward Right")
            ep.transfer("Right")
        elif totalFingers == 4:
            print("Move Backward")
            ep.transfer("Backward")
        elif totalFingers == 5:
            print("Stop Robot")
            ep.transfer("Stop")
        elif totalFingers == 0:
            print("Wait")

        h, w, c = overlayList[totalFingers - 1].shape
        img = overlayList[totalFingers - 1]

    cv2.imshow("Image", img)
    cv2.waitKey(1)
