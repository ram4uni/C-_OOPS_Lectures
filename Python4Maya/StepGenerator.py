import maya.cmds as cmds

try:
    if cmds.window(Createwindow, exists= True):
        cmds.deleteUI(Createwindow)
except NameError:
    print ("ERROR")

     
Createwindow = cmds.window ("testUI", t= "Steps Creator_Ver01", w=300,h=200)
cmds.columnLayout(adjustableColumn=True )
cmds.separator(h=5)
cmds.text(l = "Creating Steps" , fn = "boldLabelFont")
cmds.separator(h=10)
userstepCount = cmds.intSliderGrp(l="Step Count",min = 4, max = 100, field = True, value = 4)

cmds.separator(h=15)
userDefinedAngle = cmds.intSliderGrp(l="Angle",min = 0, max = 180, field = True)
cmds.separator(h=15)
cmds.button(l = "Create", w=500, h=75, c= "StepsGenerator()")
cmds.separator(h=5)
cmds.separator(h=5)
cmds.text(l = "ram4students - Creating Tools" , fn = "boldLabelFont")
cmds.separator(h=10)
cmds.showWindow(Createwindow)


def StepsGenerator(*args):
    steps=[]
    stepCount = cmds.intSliderGrp(userstepCount,q= True, value=True)
    angle = cmds.intSliderGrp(userDefinedAngle,q= True, value=True)
    for i in range(stepCount):
        step = cmds.polyCube(w= 15, h =1, d=4, n="step#", ch=0)[0]
        cmds.move(0,1.5*i, 4*i, step)
        steps.append(step)
    cmds.group(steps, n = "Steps_Grp")
    cmds.nonLinear(type="bend", curvature= angle)
    cmds.rotate(90,0,0)
    cmds.delete(steps, ch=1)
        
    
    
    
    
    
    
    
    
    