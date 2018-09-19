import math
import numpy as np

def updateRobotPos(robotPos, mousePos):
    x = robotPos[0]
    y = robotPos[1]

    '''
    vectRobot = np.matrix(robotPos).T
    matAlpha = transformToRotationMatrix(0.03)
    matRotation = np.matmul(matAlpha, vectRobot)

    oa = np.array([x,y]).T
    oc = np.array([mousePos[0],mousePos[1]]).T
    ca = oa - oc
    caprime = np.matmul(matAlpha, ca)
    oaprime = oc + caprime
    '''

    '''
    VERSION COORDONNEES HOMOGENES
    '''
    vectRobot = np.matrix(robotPos).T
    oa = np.matrix([x,y,1]).T
    oc = np.matrix([mousePos[0],mousePos[1],1]).T
    matAlpha = transformToHomogenousRotationMatrix(0.03)
    oaprime = np.matmul(translateMatrix(oc),matAlpha)
    oaprime = np.matmul(oaprime,translateMatrix(-oc))
    oaprime = np.matmul(oaprime,oa)

    '''
    VERSION ATAN2
    teta = math.atan2(y,x)
    r = math.sqrt(pow(x,2)+pow(y,2))
    tetap = teta + 0.03
    robotPos[0] = math.cos(tetap)*r
    robotPos[1] = math.sin(tetap)*r
    '''

    '''
    VERSION MATRICIELLE
    robotPos[0] = matRotation[0]
    robotPos[1] = matRotation[1]
    '''

    '''
    VERSION AUTOUR DE LA SOURIS
    robotPos[0] = oaprime[0,0]
    robotPos[1] = oaprime[0,1]
    '''

    robotPos[0] = oaprime[0,0]
    robotPos[1] = oaprime[1,0]

    

    return robotPos

def transformToRotationMatrix(alpha):
    mat =  np.matrix([[math.cos(alpha),-math.sin(alpha)],
    [math.sin(alpha),math.cos(alpha)]])
    return mat

def transformToHomogenousRotationMatrix(alpha):
    mat =  np.matrix([[math.cos(alpha),-math.sin(alpha),0],
    [math.sin(alpha),math.cos(alpha),0],
    [0,0,1]])
    return mat

def translateMatrix(vect):
    mat =  np.matrix([[1,0,vect[0,0]],
    [0,1,vect[1,0]],
    [0,0,1]])
    return mat