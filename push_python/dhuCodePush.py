
import os
import shutil
import subprocess
import filecmp
import serial
import sys


DstDir= ""
srcDir = ""
serialName = ""

excludeSet = {"appcore.dll"}
srcFileNameList = []
adbList = []


def get_config():
    try:
        f = open("./dhuAdb.cfg","r")
    except Exception as e:
        print("open dhuAdb.cfg error:",e)
        return 1
    else:
        cfgList = f.readlines()
        if len(cfgList) < 3:
            print("config file error")
            f.close()
            return 1
        else:
            global DstDir,srcDir,serialName
            DstDir = cfgList[0].strip()
            srcDir = cfgList[1].strip()
            serialName = cfgList[2].strip()

        f.close()
        return 0



def error_process(e):
    print("can not open path: " + srcDir)
 

def file_process():
    try:
        for root, dirs, files in os.walk(srcDir,onerror=error_process):
            files[:] = [f for f in files if f not in excludeSet]
            for f in files:
                # print(f)
                srcFileNameList.append(f)

    except Exception:
        pass       
    else:
        print("\n********** start file copy from srcDir **********")
        for f in srcFileNameList:
            dstFile = os.path.join(DstDir,f)
            srcFile = os.path.join(srcDir,f)

            if os.path.exists(dstFile):
                if filecmp.cmp(srcFile,dstFile):
                    # print(f + "  has no change")  
                    pass  
                else:
                    try:        
                        shutil.copy2(srcFile,dstFile)
                        adbList.append(f)
                        print("copy file (update):  " + f)
                    except Exception as e:
                        print("copy failed:",e)
            else:
                try:
                    shutil.copy2(srcFile,dstFile)
                    adbList.append(f)
                    print("copy file (new):  " + f)
                except Exception as e:
                    print("copy failed:",e)

def file_remove():
    for f in adbList:
        fileDel = os.path.join(DstDir,f)
        if os.path.exists(fileDel):
            print("\ndelete file:",f)
            os.remove(fileDel)

def adb_process():
    os.chdir(DstDir)
    batFile = open("adb.bat","w")
    batFile.writelines("adb root\n")
    batFile.writelines("adb shell mount -o remount,rw /vendor\n")
    for f in adbList:
        orderStr = "adb push " + f + " /vendor\n"
        batFile.writelines(orderStr)
    batTxt = open("adb1.txt","w")
    batTxt.writelines("mount /dev/block/vdi /mnt\n")

    for f in adbList:
        orderStr = "mv /vendor/" + f + " /mnt \n"
        batTxt.writelines(orderStr)

    batTxt.writelines("umount /mnt\n")
    batTxt.writelines("exit\n")

    batFile.close()
    batTxt.close()

    try:
        childPro = subprocess.Popen("adb.bat && adb shell < adb1.txt", shell = True,stdout = subprocess.PIPE,stderr = subprocess.PIPE ,creationflags=subprocess.CREATE_NEW_CONSOLE )
        out,err = childPro.communicate()
        returncode = childPro.wait()
        if returncode:
            raise subprocess.CalledProcessError(returncode, childPro)
    except Exception:
        print("adb error,please check connection")
        return 1
    else:
        os.remove("adb.bat")
        os.remove("adb1.txt")
        return 0
        
    
def serial_process():
    ser = serial.Serial()
    ser.port = serialName
    ser.baudrate = 115200
    ser.timeout = 0.2
    
    try:
        ser.open()
    except Exception:
        print("\nserial connect error,please check if connected or port already open" )
        return 1
    else:
        try: 
            ser.write(chr(0x03).encode("gbk"))
            data0 = ser.readlines()
            print("\nread serial: ", data0)

            result1 = ser.write("slay cluster_hmi\n".encode("gbk"))
            data = ser.readlines()
            print("\nread serial 1: ", data)

            result2 = ser.write("mount -t dos /dev/disk/ota_download /mnt/\n".encode("gbk"))
            data1 = ser.readlines()
            print("\nread serial 2: ", data1)
                
            # print("write: %d, %d" % (result1,result2))

            for f in adbList:
                orderStr = "mv /mnt/" + f + " /usr/bin/dhu-cluster\n"
                result3 = ser.write(orderStr.encode("gbk"))
                # print("write: %d" % result3)

            result4 = ser.write("cd /usr/bin/dhu-cluster/\n".encode("gbk"))
            result5 = ser.write("chmod 777 cluster_hmi\n".encode("gbk"))
            result6 = ser.write("./cluster_hmi\n".encode("gbk"))
            # print("write: %d,  %d" % (result4,result5))  

        except Exception as e:
            print("write error: ",e )
            ser.close()
            return 1
        else:
            ser.close()
            # print("\nOpen serial shell and send cmd below to start program:\n\ncd /usr/bin/dhu-cluster\n./cluster_hmi ")
            return 0
            

def exit_process():
    while 1:
        ret = input("\npress q to end process:")
        if "q" == ret:
            break
        else:
            pass


if __name__ == '__main__':
    # input("press any key to start:")
    if 1 == get_config():
        pass
    else:
        print("\nsrcDir:",srcDir)
        print("DstDir:",DstDir)

        file_process()
        if 0 == len(adbList):
            print("\nno file update, end process")        
        else:
            if 1 == adb_process():
                file_remove()
            else:
                if 1 == serial_process():
                    file_remove()
                else:
                    while 1:
                        print("\nif cluster do not restart or any other wrong ")
                        print("power to reboot,\n\npress s to start serial operation again")
                        print("\nor press q to exit:")
                        ret = input("\npress a key to next step:")
                        if "s" == ret:
                            serial_process()
                        elif "q" == ret:
                            break
                        
    exit_process()
            







